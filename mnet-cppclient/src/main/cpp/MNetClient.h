#pragma once

#include <memory>
#include <se/culvertsoft/mnet/ClassRegistry.h>
#include "ReconnectingWebSocket.h"
#include "MNetSerializer.h"

namespace mnet {

	class MNetClient : private ReconnectingWebSocket {
		typedef ReconnectingWebSocket super;
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

		bool isRunning() const {
			return super::isRunning();
		}

		virtual void handleConnect() {
			qDebug() << "WebSocket: connected";
		}

		virtual void handleDisconnect() {
			qDebug() << "WebSocket: disconnected";
		}


		virtual void handleMessage(std::shared_ptr<se::culvertsoft::mnet::Message> msg) {
			
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
			m_serializer.readJson(dataPtr, length);
		}

		/**
		* Called when a binary message is received.
		*/
		void onBinaryMessage(const QByteArray message) override {
			qDebug() << "WebSocket: got binary of size: " << message.size();
		}

		/**
		* Called when there is a websocket error.
		*/
		void onError(const QAbstractSocket::SocketError error) override {
			qDebug() << "WebSocket: got error: " << error;
		}

		volatile bool m_connected;
		MNetSerializer<se::culvertsoft::mnet::ClassRegistry> m_serializer;
		
		// MNetClient is noncopyable
		MNetClient(const MNetClient& other);
		MNetClient& operator=(const MNetClient& other);
	};

}