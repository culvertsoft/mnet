#include <QtCore/QCoreApplication>
#include <se/culvertsoft/mnet/ClassRegistry.cpp>
#include "MNetClient.h"
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

	mnet::MNetClient client("ws://localhost:80");
	client.start();

	Sleep(10000);
	client.stop();

	client.join();

	return 0;

}