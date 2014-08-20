#pragma once

#include <memory>
#include <QElapsedTimer>
#include <se/culvertsoft/mnet/ClassRegistry.h>
#include "ReconnectingWebSocket.h"
#include "MNetSerializer.h"
#include "InstanceOf.h"
#include "Route.h"

namespace mnet {

	class MNetClient : public ReconnectingWebSocket {
		typedef ReconnectingWebSocket super;
		typedef se::culvertsoft::mnet::NodeUUID NodeUUID;
		typedef se::culvertsoft::mnet::Message Message;
		typedef se::culvertsoft::mnet::DataMessage DataMessage;
		typedef se::culvertsoft::mnet::NodeAnnouncement NodeAnnouncement;
		typedef se::culvertsoft::mnet::NodeDisconnect NodeDisconnect;
		typedef se::culvertsoft::mnet::IdCreateRequest IdCreateRequest;
		typedef se::culvertsoft::mnet::ClassRegistry ClassRegistry;

		Q_OBJECT

	public:

		MNetClient(
			const QString& url,
			const std::string& name = "unnamed_cpp_node",
			const std::vector<std::string>& tags = std::vector<std::string>()) : 
				ReconnectingWebSocket(url),
				m_connected(false),
				m_name(name),
				m_tags(tags) {

			connect(this, &MNetClient::send_signal, this, &MNetClient::send_slot);
			m_announceTimer.start();
		}

		bool isConnected() const {
			return m_connected;
		}

		void start() {
			super::start();
		}

		void stop() {
			super::stop();
		}

		void join() {
			super::wait();
		}

		void send(const Message& message) {
			Q_EMIT send_signal(message);
		}

		bool isRunning() const {
			return super::isRunning();
		}

		NodeUUID id() const {
			return m_myId;
		}

	protected:

		virtual void step() override {
			super::step();
			if (hasCheckinInfo() && m_announceTimer.elapsed() > 1000) {
				m_announceTimer.restart();
				checkin();
			}
		}

		// Note that route may be NULL, if the sender is unknown
		virtual void handleMessage(std::shared_ptr<Message> msg, Route * route) {
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

		void send_signal(const Message message);

	protected:

		virtual bool hasCheckinInfo() const {
			return id().hasLsb() && id().hasMsb();
		}

		virtual void checkin() {
			if (isConnected() && hasCheckinInfo()) {
				send(NodeAnnouncement()
					.setSenderId(id())
					.setName(m_name)
					.setTags(m_tags));
				qDebug() << "MNetClient: Checking in";
			}
		}

		virtual void requestNetworkId() {
			if (isConnected()) {
				send(IdCreateRequest());
			}
		}

		virtual void handleMessage(std::shared_ptr<Message> msg) {
			using namespace se::culvertsoft::mnet;
			if (msg) {

				if (hasCheckinInfo() && msg->getSenderId() == id())
					return;

				Route * route = getRoute(msg->getSenderId());

				if (is_base<IdCreateReply>(*msg)) {
					m_myId = static_cast<IdCreateReply&>(*msg).getCreatedId();
					checkin();
				}
				else if (is_base<NodeAnnouncement>(*msg)) {

					NodeAnnouncement& announcement = static_cast<NodeAnnouncement&>(*msg);

					if (!announcement.hasSenderId()) {
						qDebug() << "MNetClient: handleAnnounce: no senderId supplied";
						return;
					}

					m_routes[id2string(announcement.getSenderId())] = Route(announcement);

					handleAnnounce(announcement);
				}
				else if (is_base<NodeDisconnect>(*msg)) {

					NodeDisconnect& discMsg = static_cast<NodeDisconnect&>(*msg);
					if (!discMsg.hasDisconnectedNodeId()) {
						qDebug() << "MNetClient: handleNodeDisconnect: no disconnectdId supplied";
						return;
					}

					m_routes.erase(id2string(discMsg.getDisconnectedNodeId()));

					handleNodeDisconnect(discMsg);
				}
				else {
					handleMessage(msg, route);
				}

			}
		}

		virtual void handleError(const QAbstractSocket::SocketError error) {
			qDebug() << "WebSocket: got error: " << error;
		}

		Route * getRoute(const NodeUUID& id) {
			const std::string key = id2string(id);

			if (m_routes.count(key)) {
				return &m_routes[key];
			}
			else {
				return 0;
			}
		}

	protected Q_SLOTS:

		virtual void send_slot(Message msg)  {

			if (!isConnected())
				return;

			if (hasCheckinInfo())
				msg.setSenderId(id());

			try {

				if (mnet::is_base<DataMessage>(msg)) {

					const DataMessage& dataMsg = static_cast<const DataMessage&>(msg);

					if (dataMsg.hasBinaryData()) {
						const std::vector<char>& data = m_serializer.writeBinary(dataMsg);
						sendBinaryMessage(QByteArray(data.data(), data.size()));
					}
					else {
						const std::vector<char>& data = m_serializer.writeJson(dataMsg);
						sendTextMessage(QString::fromUtf8(data.data(), data.size()));
					}

				}
				else {
					const std::vector<char>& data = m_serializer.writeJson(msg);
					sendTextMessage(QString::fromUtf8(data.data(), data.size()));
				}
			}
			catch (const mgen::Exception& e) {
				qDebug() << "MNetClient:send_slot: exception: " << e.what();
			}
		}

		
	private:

		/**
		* Called when connection is established.
		*/
		void onConnect() override {
			m_connected = true;

			if (hasCheckinInfo()) {
				checkin();
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
			m_routes.clear();
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

		std::string id2string(const NodeUUID& id) {
			return std::to_string(id.getLsb()).append(std::to_string(id.getMsb()));
		}
		
		// Fields
		NodeUUID m_myId;
		volatile bool m_connected;
		MNetSerializer<ClassRegistry> m_serializer;
		std::map<std::string, Route> m_routes;
		std::string m_name;
		std::vector<std::string> m_tags;
		QElapsedTimer m_announceTimer;

	};

}