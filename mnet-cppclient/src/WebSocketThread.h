#pragma once

#include <QtCore/QEventLoop>
#include <QtCore/QThread>
#include <QtCore/QSharedPointer>
#include "WebsocketClient.h"

namespace mnet {
	
	class WebSockThread : public QThread {
		Q_OBJECT

	public:

		WebSockThread(const QString& url) : 
				m_url(url) {
		}

		/**
		 * May be called from any thread. Will cause this thread to stop running.
		 */
		void stop() {
			m_toLive = false;
			Q_EMIT stopCurrentConnetion();
		}

	public Q_SLOTS:
	
		/**
		 * This is Qt, remember: 
		 * You will need an external event loop to receive this. 
		 */
		virtual void onConnect() {
			qDebug() << "WebSocket: connected";
		}

		/**
		* This is Qt, remember:
		* You will need an external event loop to receive this.
		*/
		virtual void onDisconnect() {
			qDebug() << "WebSocket: disconnected";
			Q_EMIT stopCurrentConnetion();
		}

		/**
		* This is Qt, remember:
		* You will need an external event loop to receive this.
		*/
		virtual void onTextMessage(const QString message) {
			qDebug() << "WebSocket: got text: " << message;
		}

		/**
		* This is Qt, remember:
		* You will need an external event loop to receive this.
		*/
		virtual void onBinaryMessage(const QByteArray message) {
			qDebug() << "WebSocket: got binary of size: " << message.size();
		}

	Q_SIGNALS:
		void stopCurrentConnetion();

	protected:
		void run() override {
			while (m_toLive) {
				std::cout << "Trying to connect" << std::endl;
				QEventLoop eventLoop;
				connect(this, &WebSockThread::stopCurrentConnetion, &eventLoop, &QEventLoop::quit);
				mnet::WebsocketClient currentClient(m_url, this);
				eventLoop.exec();
			}
			std::cout << "Thread done!" << std::endl;
		}

	private:
		QString m_url;
		volatile bool m_toLive;

	};

}