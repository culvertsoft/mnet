/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_HANDLER
#define SE_CULVERTSOFT_MNET_HANDLER

#include "ForwardDeclare.h"

namespace se {
namespace culvertsoft {
namespace mnet {

class Handler  {
	public:

	Handler();
	virtual ~Handler();
	virtual void handleDiscard(mgen::MGenBase& o);
	virtual void handleUnknown(mgen::MGenBase& o);
	virtual void handle(se::culvertsoft::mnet::NodeSettings& o);
	virtual void handle(se::culvertsoft::mnet::NodeUUID& o);
	virtual void handle(se::culvertsoft::mnet::MessageFilter& o);
	virtual void handle(se::culvertsoft::mnet::Message& o);
	virtual void handle(se::culvertsoft::mnet::IdCreateRequest& o);
	virtual void handle(se::culvertsoft::mnet::IdCreateReply& o);
	virtual void handle(se::culvertsoft::mnet::NodeAnnouncement& o);
	virtual void handle(se::culvertsoft::mnet::DataMessage& o);
	virtual void handle(se::culvertsoft::mnet::NodeDisconnect& o);
	virtual void handle(se::culvertsoft::mnet::ErrorMessage& o);

}; // End class Handler

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
