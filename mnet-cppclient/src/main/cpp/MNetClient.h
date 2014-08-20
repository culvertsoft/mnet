#pragma once

#include <memory>
#include <QElapsedTimer>
#include <QtCore/QMetaType>
#include <QtCore/QTimer>
#include <se/culvertsoft/mnet/ClassRegistry.h>
#include "ReconnectingWebSocket.h"
#include "MNetSerializer.h"
#include "Route.h"

#define CASE_TYPE(T, varName, src) T * varName = dynamic_cast<T*>(src)
typedef std::shared_ptr<se::culvertsoft::mnet::Message> SendItem;
Q_DECLARE_METATYPE(SendItem);

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
		typedef se::culvertsoft::mnet::IdCreateReply IdCreateReply;

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
			qRegisterMetaType<SendItem>("SendItem");
			m_announceTimer.start(1000);
			connect(this, &MNetClient::send_signal, this, &MNetClient::send_slot);
			connect(&m_announceTimer, &QTimer::timeout, this, &MNetClient::announce);
		}

		bool isConnected() const {
			return m_connected;
		}
		
		void send(SendItem message) {
			Q_EMIT send_signal(message);
		}
		
		NodeUUID id() const {
			return m_myId;
		}

	protected Q_SLOTS:

		virtual void announce() {
			if (isConnected() && hasId()) {
				send(std::shared_ptr<NodeAnnouncement>(&(new NodeAnnouncement)
					->setSenderId(id())
					.setName(m_name)
					.setTags(m_tags)));
			}
		}

		// Note that route may be NULL, if the sender is unknown
		virtual void handleMessage(std::shared_ptr<Message> msg, const Route * route) {
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

		void send_signal(SendItem message);

	protected:

		virtual bool hasId() const {
			return id().hasLsb() && id().hasMsb();
		}

		virtual void requestNetworkId() {
			if (isConnected()) {
				send(std::shared_ptr<Message>(new IdCreateRequest()));
			}
		}

		virtual void handleMessage(std::shared_ptr<Message> uknMsg) {
			
			if (uknMsg) {

				if (hasId() && uknMsg->getSenderId() == id())
					return;

				const Route * route = getRoute(uknMsg->getSenderId());

				if (CASE_TYPE(IdCreateReply, msg, uknMsg.get()))  {
					m_myId = msg->getCreatedId();
					announce();
				}
				else if (CASE_TYPE(NodeAnnouncement, msg, uknMsg.get())) {

					if (!msg->hasSenderId()) {
						qDebug() << "MNetClient: handleAnnounce: no senderId supplied";
						return;
					}

					m_routes[id2string(msg->getSenderId())] = Route(*msg);

					handleAnnounce(*msg);
				}
				else if (CASE_TYPE(NodeDisconnect, msg, uknMsg.get())) {

					if (!msg->hasDisconnectedNodeId()) {
						qDebug() << "MNetClient: handleNodeDisconnect: no disconnectdId supplied";
						return;
					}

					m_routes.erase(id2string(msg->getDisconnectedNodeId()));

					handleNodeDisconnect(*msg);
				}
				else {
					handleMessage(uknMsg, route);
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

		virtual void send_slot(SendItem msg)  {
			
			if (!msg)
				return;
			
			if (!isConnected())
				return;

			if (hasId())
				msg->setSenderId(id());
			
			try {

				if (CASE_TYPE(DataMessage, dataMsg, msg.get())) {

					if (dataMsg->hasBinaryData()) {
						const std::vector<char>& data = m_serializer.writeBinary(*dataMsg);
						sendBinaryMessage(QByteArray(data.data(), data.size()));
					}
					else {
						const std::vector<char>& data = m_serializer.writeJson(*dataMsg);
						sendTextMessage(QString::fromUtf8(data.data(), data.size()));
					}

				}
				else {
					const std::vector<char>& data = m_serializer.writeJson(*msg);
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

	};

#undef CASE_TYPE

}