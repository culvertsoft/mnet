#pragma once

#include <memory>
#include <se/culvertsoft/mnet/ClassRegistry.h>
#include "ReconnectingWebSocket.h"
#include "MNetSerializer.h"
#include "Route.h"

namespace mnet {

	class MNetClient : private ReconnectingWebSocket {
		typedef ReconnectingWebSocket super;
		typedef se::culvertsoft::mnet::NodeUUID NodeUUID;
		typedef se::culvertsoft::mnet::Message Message;
	public:

		MNetClient(const QString& url) : 
			ReconnectingWebSocket(url),
			m_connected(false) {
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

		void send(const se::culvertsoft::mnet::Message& message) {

		}

		/**
		 * Note that route may be NULL, if the sender is unknown
		 */
		virtual void handleMessage(std::shared_ptr<Message> msg, Route * route) {

		}

		bool isRunning() const {
			return super::isRunning();
		}

		const NodeUUID& id() const {
			return m_myId;
		}

		virtual void handleConnect() {
			qDebug() << "WebSocket: connected";
		}

		virtual void handleDisconnect() {
			qDebug() << "WebSocket: disconnected";
		}

	protected:

		virtual void handleMessage(std::shared_ptr<Message> msg) {
			using namespace se::culvertsoft::mnet;
			if (msg) {

				Route * route = getRoute(msg->getSenderId());

				switch (msg->_typeId()) {
				case se::culvertsoft::mnet::IdCreateReply::_type_id:
					m_myId = static_cast<se::culvertsoft::mnet::IdCreateReply&>(*msg).getCreatedId();
					break;
				default:
					handleMessage(msg, route);
				}
			}
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


	private:

		/**
		* Called when connection is established.
		*/
		void onConnect() override {
			m_connected = true;
			handleConnect();
		}

		/**
		* Called when connection is lost.
		*/
		void onDisconnect() override {
			super::onDisconnect();
			m_connected = false;
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
		}

		/**
		* Called when there is a websocket error.
		*/
		void onError(const QAbstractSocket::SocketError error) override {
			qDebug() << "WebSocket: got error: " << error;
		}

		std::string id2string(const NodeUUID& id) {
			return std::to_string(id.getLsb()).append(std::to_string(id.getMsb()));
		}

		volatile bool m_connected;
		MNetSerializer<se::culvertsoft::mnet::ClassRegistry> m_serializer;
		std::map<std::string, Route> m_routes;
		NodeUUID m_myId;
		
		// MNetClient is noncopyable
		MNetClient(const MNetClient& other);
		MNetClient& operator=(const MNetClient& other);
	};

}