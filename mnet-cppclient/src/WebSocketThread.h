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

		void stop() {
			Q_EMIT stopSignal();
		}

	Q_SIGNALS:
		void stopSignal();

	protected:
		void run() override {
			QEventLoop eventLoop;
			mnet::WebsocketClient currentClient(m_url);
			connect(this, &WebSockThread::stopSignal, &eventLoop, &QEventLoop::quit, Qt::QueuedConnection);
			eventLoop.exec();
			std::cout << "Thread done!" << std::endl;
		}

	private:
		QString m_url;

	};

}