#pragma once

#include <mutex>
#include <memory>
#include <QtCore/QTimer>
#include <se/culvertsoft/mnet/ClassRegistry.h>
#include "ReconnectingWebSocket.h"
#include "MNetSerializer.h"
#include "Route.h"

namespace mnet {

#define CASE_TYPE(T, varName, src) T * varName = dynamic_cast<T*>(src)

	typedef std::shared_ptr<se::culvertsoft::mnet::Message> MsgPtr;
	using se::culvertsoft::mnet::NodeUUID;
	using se::culvertsoft::mnet::Message;
	using se::culvertsoft::mnet::DataMessage;
	using se::culvertsoft::mnet::NodeAnnouncement;
	using se::culvertsoft::mnet::NodeDisconnect;
	using se::culvertsoft::mnet::IdCreateRequest;
	using se::culvertsoft::mnet::ClassRegistry;
	using se::culvertsoft::mnet::IdCreateReply;
	using se::culvertsoft::mnet::cppclient::ClientConfiguration;

	class MNetClient : public ReconnectingWebSocket {
		typedef ReconnectingWebSocket super;
		Q_OBJECT

	public:

		MNetClient(
			const std::string& url,
			const std::string& name = "unnamed_cpp_node",
			const std::vector<std::string>& tags = std::vector<std::string>()) :
			ReconnectingWebSocket(url),
			m_connected(false),
			m_name(name),
			m_tags(tags) {
			m_announceTimer.start(1000);
			connect(this, &MNetClient::send_signal_text, this, &MNetClient::send_slot_text);
			connect(this, &MNetClient::send_signal_binary, this, &MNetClient::send_slot_binary);
			connect(&m_announceTimer, &QTimer::timeout, this, &MNetClient::announce);
		}

		MNetClient(const ClientConfiguration& cfg) :
			MNetClient(cfg.getUrl(), cfg.getName(), cfg.getTags()) {
		}

		bool isConnected() const {
			return m_connected;
		}

		void sendBinary(const char * data, const int n, const NodeUUID& tgt) {
			send(DataMessage().setSenderId(id()).setTargetId(tgt).setBinaryData(std::vector<char>(data, data + n)));
		}

		void sendBinary(const std::vector<char>& data, const NodeUUID& tgt) {
			send(DataMessage().setSenderId(id()).setTargetId(tgt).setBinaryData(data));
		}

		void sendText(const char * data, const int n, const NodeUUID& tgt) {
			send(DataMessage().setSenderId(id()).setTargetId(tgt).setStringData(std::string(data, n)));
		}

		void sendText(const std::vector<char>& data, const NodeUUID& tgt) {
			send(DataMessage().setSenderId(id()).setTargetId(tgt).setStringData(std::string(data.data(), data.size())));
		}

		void sendText(const std::string& data, const NodeUUID& tgt) {
			send(DataMessage().setSenderId(id()).setTargetId(tgt).setStringData(data));
		}

		void send(const Message& msg) {

			if (!isConnected())
				return;

			try {

				if (CASE_TYPE(const DataMessage, dataMsg, &msg)) {
					if (dataMsg->hasBinaryData()) {
						const std::vector<char>& data = m_serializer.writeBinary(*dataMsg);
						Q_EMIT send_signal_binary(QByteArray(data.data(), data.size()));
						return;
					}
				}

				const std::vector<char>& data = m_serializer.writeJson(msg);
				Q_EMIT send_signal_text(QString::fromUtf8(data.data(), data.size()));

			}
			catch (const mgen::Exception& e) {
				qDebug() << "MNetClient:send: exception: " << e.what();
			}

		}

		NodeUUID id() const {
			return m_myId;
		}

		std::vector<Route> getRoutes() const {
			std::lock_guard<std::recursive_mutex> lock(m_mutex);
			std::vector<Route> out;
			for (const auto& pair : m_routes)
				out.push_back(pair.second);
			return out;
		}

		protected Q_SLOTS:

		virtual void announce() {
			if (isConnected() && hasId()) {
				send(NodeAnnouncement()
					.setSenderId(id())
					.setName(m_name)
					.setTags(m_tags));
			}
		}

		// Note that route may be NULL, if the sender is unknown
		virtual void handleMessage(MsgPtr msg, const Route * route) {
		}

		virtual void handleConnect() {
			qDebug() << "MNetClient: connected";
		}

		virtual void handleDisconnect() {
			qDebug() << "MNetClient: disconnected";
		}

		virtual void handleNodeDisconnect(const NodeDisconnect& msg) {
			qDebug() << "MNetClient: redeived remote node disconnect: " << QString::fromStdString(id2string(msg.getDisconnectedNodeId()));
		}

		virtual void handleAnnounce(const NodeAnnouncement& announcement) {
			qDebug() << "MNetClient: received announcement: " << QString::fromStdString(id2string(announcement.getSenderId()));
		}

	Q_SIGNALS:

		void send_signal_text(QString data);
		void send_signal_binary(QByteArray data);

	protected:

		virtual bool hasId() const {
			return id().hasLsb() && id().hasMsb();
		}

		virtual void requestNetworkId() {
			if (isConnected()) {
				send(IdCreateRequest().setSenderId(id()));
			}
		}

		virtual void handleMessage(MsgPtr msgBase) {

			if (msgBase) {

				if (hasId() && msgBase->getSenderId() == id())
					return;

				const Route * route = getRoute(msgBase->getSenderId());

				if (CASE_TYPE(IdCreateReply, msg, msgBase.get()))  {
					m_myId = msg->getCreatedId();
					announce();
				}
				else if (CASE_TYPE(NodeAnnouncement, msg, msgBase.get())) {

					if (!msg->hasSenderId()) {
						qDebug() << "MNetClient: handleAnnounce: no senderId supplied";
						return;
					}

					{
						std::lock_guard<std::recursive_mutex> lock(m_mutex);
						m_routes[id2string(msg->getSenderId())] = Route(*msg);
					}

					handleAnnounce(*msg);
				}
				else if (CASE_TYPE(NodeDisconnect, msg, msgBase.get())) {

					if (!msg->hasDisconnectedNodeId()) {
						qDebug() << "MNetClient: handleNodeDisconnect: no disconnectdId supplied";
						return;
					}

					{
						std::lock_guard<std::recursive_mutex> lock(m_mutex);
						m_routes.erase(id2string(msg->getDisconnectedNodeId()));
					}

					handleNodeDisconnect(*msg);
				}
				else {
					handleMessage(msgBase, route);
				}

			}

		}

		virtual void handleError(const QAbstractSocket::SocketError error) {
			qDebug() << "WebSocket: got error: " << error;
		}

		const Route * getRoute(const NodeUUID& id) const {
			const std::map<std::string, Route>::const_iterator it = m_routes.find(id2string(id));
			return (it != m_routes.end()) ? &it->second : 0;
		}

		protected Q_SLOTS:

		virtual void send_slot_text(QString data) {
			sendTextMessage(data);
		}

		virtual void send_slot_binary(QByteArray data) {
			sendBinaryMessage(data);
		}


	private:

		/**
		* Called when connection is established.
		*/
		void onConnect() override {
			m_connected = true;

			if (hasId()) {
				announce();
			}
			else {
				requestNetworkId();
			}

			handleConnect();
		}

		/**
		* Called when connection is lost.
		*/
		void onDisconnect() override {
			super::onDisconnect();
			m_connected = false;
			{
				std::lock_guard<std::recursive_mutex> lock(m_mutex);
				m_routes.clear();
			}
			handleDisconnect();
		}

		/**
		* Called when a text message is received.
		*/
		void onTextMessage(const QString message) override {
			qDebug() << "WebSocket: got text: " << message;
			QByteArray utf8Data = message.toUtf8();
			const char * dataPtr = utf8Data.constBegin();
			const int length = utf8Data.size();
			try {
				handleMessage(m_serializer.readJson(dataPtr, length));
			}
			catch (const mgen::Exception& e) {
				qDebug() << "onTextMessage: exception: " << e.what();
			}
			qDebug() << "done onText";
		}

		/**
		* Called when a binary message is received.
		*/
		void onBinaryMessage(const QByteArray message) override {
			qDebug() << "WebSocket: got binary of size: " << message.size();
			const char * dataPtr = message.constBegin();
			const int length = message.size();
			try {
				handleMessage(m_serializer.readBinary(dataPtr, length));
			}
			catch (const mgen::Exception& e) {
				qDebug() << "onTextMessage: exception: " << e.what();
			}
			qDebug() << "done onBinary";
		}

		/**
		* Called when there is a websocket error.
		*/
		void onError(const QAbstractSocket::SocketError error) override {
			handleError(error);
		}

		std::string id2string(const NodeUUID& id) const {
			return std::to_string(id.getLsb()).append(std::to_string(id.getMsb()));
		}

		// Fields
		NodeUUID m_myId;
		volatile bool m_connected;
		MNetSerializer<ClassRegistry> m_serializer;
		std::map<std::string, Route> m_routes;
		std::string m_name;
		std::vector<std::string> m_tags;
		QTimer m_announceTimer;
		mutable std::recursive_mutex m_mutex;

	};

#undef CASE_TYPE

}
