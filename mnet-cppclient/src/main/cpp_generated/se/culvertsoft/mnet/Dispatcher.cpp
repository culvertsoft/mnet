/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "Dispatcher.h"
#include "ClassRegistry.h"

namespace se {
namespace culvertsoft {
namespace mnet {

void dispatch(mgen::MGenBase& object, se::culvertsoft::mnet::Handler& handler) {
	const std::vector<short>& ids = object._typeIds16Bit();
	std::size_t i = 0;
	switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
		case se::culvertsoft::mnet::NodeSettings::_type_id_16bit:
			handler.handle(static_cast<se::culvertsoft::mnet::NodeSettings&>(object));
			break;
		case se::culvertsoft::mnet::NodeUUID::_type_id_16bit:
			handler.handle(static_cast<se::culvertsoft::mnet::NodeUUID&>(object));
			break;
		case se::culvertsoft::mnet::MessageFilter::_type_id_16bit:
			handler.handle(static_cast<se::culvertsoft::mnet::MessageFilter&>(object));
			break;
		case se::culvertsoft::mnet::Message::_type_id_16bit:
			switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
				case se::culvertsoft::mnet::IdCreateRequest::_type_id_16bit:
					handler.handle(static_cast<se::culvertsoft::mnet::IdCreateRequest&>(object));
					break;
				case se::culvertsoft::mnet::IdCreateReply::_type_id_16bit:
					handler.handle(static_cast<se::culvertsoft::mnet::IdCreateReply&>(object));
					break;
				case se::culvertsoft::mnet::NodeAnnouncement::_type_id_16bit:
					handler.handle(static_cast<se::culvertsoft::mnet::NodeAnnouncement&>(object));
					break;
				case se::culvertsoft::mnet::DataMessage::_type_id_16bit:
					handler.handle(static_cast<se::culvertsoft::mnet::DataMessage&>(object));
					break;
				case se::culvertsoft::mnet::NodeDisconnect::_type_id_16bit:
					handler.handle(static_cast<se::culvertsoft::mnet::NodeDisconnect&>(object));
					break;
				case se::culvertsoft::mnet::ErrorMessage::_type_id_16bit:
					handler.handle(static_cast<se::culvertsoft::mnet::ErrorMessage&>(object));
					break;
				default:
					handler.handle(static_cast<se::culvertsoft::mnet::Message&>(object));
					break;
			}
			break;
		case se::culvertsoft::mnet::cppclient::ClientConfiguration::_type_id_16bit:
			handler.handle(static_cast<se::culvertsoft::mnet::cppclient::ClientConfiguration&>(object));
			break;
		default:
			handler.handleUnknown(object);
			break;
	}
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

