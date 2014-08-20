#pragma once

#include <iostream>
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

namespace mnet {

	/**
	* Stops this client.
	*/
	class WebSocket : public QObject
	{
		Q_OBJECT

	public:

		/**********************************************************
		*
		*
		*					PUBLIC API
		*
		**********************************************************/

		/**
		* Creates a client and connects its signals and slots.
		* Opens the underlying websocket.
		*/
		template <typename ReceiverType>
		WebSocket(
				const QString& url,
				ReceiverType * receiver,
				Qt::ConnectionType connectionType) : m_url(url) {
			connect(&m_webSocket, &QWebSocket::connected, receiver, &ReceiverType::onConnect, connectionType);
			connect(&m_webSocket, &QWebSocket::disconnected, receiver, &ReceiverType::onDisconnect, connectionType);
			connect(&m_webSocket, &QWebSocket::textMessageReceived, receiver, &ReceiverType::onTextMessage, connectionType);
			connect(&m_webSocket, &QWebSocket::binaryMessageReceived, receiver, &ReceiverType::onBinaryMessage, connectionType);
			connect(&m_webSocket, static_cast<void (QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), receiver, &ReceiverType::onError, connectionType);

			connect(this, &WebSocket::sendTextMessage_signal, this, &WebSocket::sendTextMessage_slot);
			connect(this, &WebSocket::sendBinaryMessage_signal, this, &WebSocket::sendBinaryMessage_slot);
			m_webSocket.open(m_url);
		}

		/**
		 * Closes the underlying socket, which was opened in the constructor.
		 */
		virtual ~WebSocket() {
			m_webSocket.close();
		}

	public Q_SLOTS:
		/**
		 * Emits the signal 'sendTextMessage_signal', which will be
		 * processed in the 'sendTextMessage_slot'. This is to ensure that we
		 * can send messages from any thread without worrying.
		 */
		void sendTextMessage(const QString message) {
			Q_EMIT sendTextMessage_signal(message);
		}


		/**
		* Emits the signal 'sendBinaryMessage_signal', which will be
		* processed in the 'sendBinaryMessage_slot'. This is to ensure that we
		* can send messages from any thread without worrying.
		*/
		void sendBinaryMessage(const QByteArray message) {
			Q_EMIT sendBinaryMessage_signal(message);
		}

	Q_SIGNALS:
		void sendTextMessage_signal(const QString message);
		void sendBinaryMessage_signal(const QByteArray message);

	private Q_SLOTS:
		void sendTextMessage_slot(const QString message) { m_webSocket.sendTextMessage(message); }
		void sendBinaryMessage_slot(const QByteArray message) { m_webSocket.sendBinaryMessage(message); }

	private:
		QWebSocket m_webSocket;
		QUrl m_url;

	};

}
