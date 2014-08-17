#include <QtCore/QCoreApplication>
#include "ReconnectingWebSocket.h"
#include <Windows.h>

static void noop_deleter(QCoreApplication * app) {}

QSharedPointer<QCoreApplication> ensureQtAppOrCreateNew(int argc, char *argv[]) {
	if (QCoreApplication::instance()) {
		return QSharedPointer<QCoreApplication>(QCoreApplication::instance(), noop_deleter);
	} else {
		return QSharedPointer<QCoreApplication>(new QCoreApplication(argc, argv));
	}
}

int main(int argc, char *argv[]) {

	QSharedPointer<QCoreApplication> app = ensureQtAppOrCreateNew(argc, argv);

	QEventLoop eventLoop;

	mnet::ReconnectingWebSocket client("ws://localhost:80", Qt::DirectConnection);
	client.start();

	Sleep(1000);
	client.stop();

	client.wait();

	return 0;

}