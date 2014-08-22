#include <iostream>
#include <QtCore/QCoreApplication>
#include <se/culvertsoft/mnet/ClassRegistry.cpp>
#include <mnet/MNetClient.h>
#include "File2Vector.h"

static void noop_deleter(QCoreApplication * app) {}

QSharedPointer<QCoreApplication> ensureQtAppOrCreateNew(int argc, char *argv[]) {
	if (QCoreApplication::instance()) {
		return QSharedPointer<QCoreApplication>(QCoreApplication::instance(), noop_deleter);
	} else {
		return QSharedPointer<QCoreApplication>(new QCoreApplication(argc, argv));
	}
}

using namespace mgen;
using namespace mnet;
using se::culvertsoft::mnet::cppclient::ClientConfiguration;

int main(int argc, char *argv[]) {
	
	QSharedPointer<QCoreApplication> app = ensureQtAppOrCreateNew(argc, argv);

	const std::string cfgFileName = "../src/test/cfg/connect_settings.json";
	const std::vector<char> cfgFileData = file2vector(cfgFileName);

	if (cfgFileData.empty())
		throw new std::runtime_error(std::string("Unable to read configuration from file: ").append(cfgFileName));

	MNetSerializer<ClassRegistry> serializer;
	std::shared_ptr<ClientConfiguration> cfg = 
		serializer.readJson<ClientConfiguration>(cfgFileData.data(), cfgFileData.size());
	
	QEventLoop eventLoop;
	MNetClient client(*cfg);
	eventLoop.exec();
	
	return 0;

}
