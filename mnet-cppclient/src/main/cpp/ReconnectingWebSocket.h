#pragma once

#include "WebSocket.h"

namespace mnet {
	
	class ReconnectingWebSocket : public QObject {
		Q_OBJECT
		friend class WebSocket; // for callbacks

	public:

		ReconnectingWebSocket(const QString& url) : 
			m_url(url),
			m_socket(url, this) {
		}

		virtual ~ReconnectingWebSocket() {
			qDebug() << "~ReconnectingWebSocket()";
		}

		void sendTextMessage(const QString& message) {
			m_socket.sendTextMessage(message);
		}

		void sendBinaryMessage(const QByteArray& message) {
			m_socket.sendBinaryMessage(message);
		}
		
	protected Q_SLOTS:
	
		/**
		 * Called when connection is established.
		 */
		virtual void onConnect() {
		}

		/**
		* Called when connection is lost.
		*/
		virtual void onDisconnect() {
			m_socket.reconnect();
		}

		/**
		* Called when a text message is received.
		*/
		virtual void onTextMessage(const QString message) {
		}

		/**
		* Called when a binary message is received.
		*/
		virtual void onBinaryMessage(const QByteArray message) {
		}

		/**
		* Called when there is a websocket error.
		*/
		virtual void onError(const QAbstractSocket::SocketError error) {
		}
				
	private:
		QString m_url;
		WebSocket m_socket;

	};

}
