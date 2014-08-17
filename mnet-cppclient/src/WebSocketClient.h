#pragma once

#include <iostream>
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

namespace mnet {

	/**
	* Stops this client.
	*/
	class WebsocketClient : public QObject
	{
		Q_OBJECT

	public:

		/**********************************************************
		 *
		 *
		 *			OVERLOAD THESE FOR CALLBACKS
		 *
		 **********************************************************/

		virtual void handleConnect() {
			qDebug() << "WebSocket: connected";
			// m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
		}

		virtual void handleDisconnect() {
			qDebug() << "WebSocket: disconnected";
		}

		virtual void handleTextMessage(const QString message) {
			qDebug() << "Websocket: message received:" << message;
		}

		virtual void handleBinaryMessage(const QByteArray message) {
			qDebug() << "Websocket: message received, size:" << message.size();
		}

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
		WebsocketClient(const QString& url, QObject *parent = Q_NULLPTR) : QObject(parent), m_url(url) {
			connect(&m_webSocket, &QWebSocket::connected, this, &WebsocketClient::onConnect);
			connect(&m_webSocket, &QWebSocket::disconnected, this, &WebsocketClient::onDisconnect);
			connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &WebsocketClient::onTextMessage);
			connect(&m_webSocket, &QWebSocket::binaryMessageReceived, this, &WebsocketClient::onBinaryMessage);
			connect(this, &WebsocketClient::sendTextMessage_signal, this, &WebsocketClient::sendTextMessage_slot);
			connect(this, &WebsocketClient::sendBinaryMessage_signal, this, &WebsocketClient::sendBinaryMessage_slot);
			m_webSocket.open(m_url);
		}

		/**
		 * Closes the underlying socket, which was opened in the constructor.
		 */
		virtual ~WebsocketClient() {
			m_webSocket.close();
		}

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

		void onConnect() { handleConnect(); }
		void onDisconnect() { handleDisconnect(); }
		void onTextMessage(const QString message) { handleTextMessage(message); }
		void onBinaryMessage(const QByteArray message) { handleBinaryMessage(message); }
		void sendTextMessage_slot(const QString message) { m_webSocket.sendTextMessage(message); }
		void sendBinaryMessage_slot(const QByteArray message) { m_webSocket.sendBinaryMessage(message); }

	private:
		QWebSocket m_webSocket;
		QUrl m_url;
	};

}
