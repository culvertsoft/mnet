#pragma once

#include "WebSocket.h"

namespace mnet {
	
	class ReconnectingWebSocket : public QObject {
		Q_OBJECT
		friend class WebSocket; // for callbacks

	public:

		ReconnectingWebSocket(const QString& url) : m_url(url), m_socket(url), m_toLive(true) {
			m_socket.init(this);
			reconnect();
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
			if (m_toLive) {
				reconnect();
			}
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
		
		void reconnect() {
			qDebug() << "WebSocket: Connecting to " << m_url;
			m_socket.reconnect();
		}
		
	private:
		QString m_url;
		WebSocket m_socket;
		volatile bool m_toLive;

	};

}
