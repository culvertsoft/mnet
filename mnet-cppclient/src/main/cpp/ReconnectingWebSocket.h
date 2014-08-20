#pragma once

#include <QtCore/QEventLoop>
#include <QtCore/QSharedPointer>
#include <QtCore/QThread>
#include <QtCore/QTimer>
#include "WebSocket.h"

namespace mnet {
	
	class ReconnectingWebSocket : public QThread {
		Q_OBJECT
		friend class WebSocket; // for callbacks

	public:

		/**
		* Provide a url and a callback policy. The callback policy determines
		* whether callbacks are run on the internal socket thread or sent as
		* messages to an external qt event loop (that you must start).
		*/
		ReconnectingWebSocket(const QString& url, Qt::ConnectionType callbackPolicy = Qt::DirectConnection) :
				m_url(url),
				m_toLive(true),
				m_callbackPolicy(callbackPolicy) {
		}


		/**
		* Signals this thread to send a text message.
		* May be called from any thread
		*/
		void sendTextMessage(const QString& message) {
			Q_EMIT sendTextMessage_signal(message);
		}

		/**
		* Signals this thread to send a binary message.
		* May be called from any thread
		*/
		void sendBinaryMessage(const QByteArray& message) {
			Q_EMIT sendBinaryMessage_signal(message);
		}

		/**
		 * Signals this thread to stop running.
		 * May be called from any thread
		 */
		void stop() {
			m_toLive = false;
			Q_EMIT reconnectOrQuit_signal();
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
			Q_EMIT reconnectOrQuit_signal();
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

		// Iteration method
		virtual void step() {
			if (!m_toLive) {
				Q_EMIT reconnectOrQuit_signal();
			}
		}

	Q_SIGNALS:
		void reconnectOrQuit_signal();
		void sendTextMessage_signal(const QString message);
		void sendBinaryMessage_signal(const QByteArray message);

	protected:
		void run() override {

			// Create our event loop
			QEventLoop eventLoop;
			connect(this, &ReconnectingWebSocket::reconnectOrQuit_signal, &eventLoop, &QEventLoop::quit);

			// Create a thread which checks for missed stop events
			QTimer timer;
			connect(&timer, &QTimer::timeout, this, &ReconnectingWebSocket::step, m_callbackPolicy);
			timer.start(100);

			// Now run our reconnecting client
			// If any stop signals are emitted when the event loop is not running,
			// we will be able to catch them using the timer above
			while (m_toLive) {
				qDebug() << "WebSocket: Connecting to " << m_url;

				// Create a websocket
				mnet::WebSocket socket(m_url, this, m_callbackPolicy);

				// Connect send functions
				QMetaObject::Connection textSendConnection = connect(this, &ReconnectingWebSocket::sendTextMessage_signal, &socket, &WebSocket::sendTextMessage);
				QMetaObject::Connection binarySendConnection = connect(this, &ReconnectingWebSocket::sendBinaryMessage_signal, &socket, &WebSocket::sendBinaryMessage);

				// Enter loop execution
				eventLoop.exec();

				// Disconnect send functions before the socked is destructed
				disconnect(textSendConnection);
				disconnect(binarySendConnection);

			}

			qDebug() << "WebSocket: finished";
		}


	private:
		QString m_url;
		volatile bool m_toLive;
		Qt::ConnectionType m_callbackPolicy;


	};

}
