#pragma once

#include <QtWebSockets/QWebSocket>

namespace mnet {

	class WebSocket : public QObject
	{
		Q_OBJECT

	public:

		template <typename ReceiverType>
		WebSocket(const std::string& url, ReceiverType * receiver) : m_url(QString(url.c_str())) {
			connect(&m_webSocket, &QWebSocket::connected, receiver, &ReceiverType::onConnect);
			connect(&m_webSocket, &QWebSocket::disconnected, receiver, &ReceiverType::onDisconnect);
			connect(&m_webSocket, &QWebSocket::textMessageReceived, receiver, &ReceiverType::onTextMessage);
			connect(&m_webSocket, &QWebSocket::binaryMessageReceived, receiver, &ReceiverType::onBinaryMessage);
			connect(&m_webSocket, static_cast<void (QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), receiver, &ReceiverType::onError);
			reconnect();
		}
		
		void reconnect() {
			qDebug() << "WebSocket: Connecting to " << m_url;
			m_webSocket.open(m_url);
		}

		virtual ~WebSocket() {
		}

	public Q_SLOTS:

		void sendTextMessage(const QString message) {
			m_webSocket.sendTextMessage(message);
		}

		void sendBinaryMessage(const QByteArray message) {
			m_webSocket.sendBinaryMessage(message);
		}

	private:
		QWebSocket m_webSocket;
		QUrl m_url;

	};

}
