#include <QtCore/QCoreApplication>
#include "WebSocketThread.h"
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

	mnet::WebSockThread client("ws://localhost:80");
	client.start();

	Sleep(500); // Take some time and wait for MNet connect announcement

	client.stop();
	client.wait();

	return 0;

}