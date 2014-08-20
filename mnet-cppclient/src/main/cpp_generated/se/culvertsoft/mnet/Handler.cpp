/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "Handler.h"
#include "se/culvertsoft/mnet/NodeSettings.h"
#include "se/culvertsoft/mnet/NodeUUID.h"
#include "se/culvertsoft/mnet/MessageFilter.h"
#include "se/culvertsoft/mnet/IdCreateRequest.h"
#include "se/culvertsoft/mnet/IdCreateReply.h"
#include "se/culvertsoft/mnet/NodeAnnouncement.h"
#include "se/culvertsoft/mnet/DataMessage.h"
#include "se/culvertsoft/mnet/NodeDisconnect.h"
#include "se/culvertsoft/mnet/ErrorMessage.h"

namespace se {
namespace culvertsoft {
namespace mnet {

Handler::Handler() {}

Handler::~Handler() {}

void Handler::handleDiscard(mgen::MGenBase& o) {
}

void Handler::handleUnknown(mgen::MGenBase& o) {
	handleDiscard(o);
}

void Handler::handle(se::culvertsoft::mnet::NodeSettings& o) {
	handleDiscard(o);
}

void Handler::handle(se::culvertsoft::mnet::NodeUUID& o) {
	handleDiscard(o);
}

void Handler::handle(se::culvertsoft::mnet::MessageFilter& o) {
	handleDiscard(o);
}

void Handler::handle(se::culvertsoft::mnet::Message& o) {
	handleDiscard(o);
}

void Handler::handle(se::culvertsoft::mnet::IdCreateRequest& o) {
	handle(static_cast<se::culvertsoft::mnet::Message&>(o));
}

void Handler::handle(se::culvertsoft::mnet::IdCreateReply& o) {
	handle(static_cast<se::culvertsoft::mnet::Message&>(o));
}

void Handler::handle(se::culvertsoft::mnet::NodeAnnouncement& o) {
	handle(static_cast<se::culvertsoft::mnet::Message&>(o));
}

void Handler::handle(se::culvertsoft::mnet::DataMessage& o) {
	handle(static_cast<se::culvertsoft::mnet::Message&>(o));
}

void Handler::handle(se::culvertsoft::mnet::NodeDisconnect& o) {
	handle(static_cast<se::culvertsoft::mnet::Message&>(o));
}

void Handler::handle(se::culvertsoft::mnet::ErrorMessage& o) {
	handle(static_cast<se::culvertsoft::mnet::Message&>(o));
}


} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

