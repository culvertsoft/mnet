/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "ClassRegistry.h"
#include "se/culvertsoft/mnet/NodeSettings.cpp"
#include "se/culvertsoft/mnet/NodeUUID.cpp"
#include "se/culvertsoft/mnet/MessageFilter.cpp"
#include "se/culvertsoft/mnet/Message.cpp"
#include "se/culvertsoft/mnet/IdCreateRequest.cpp"
#include "se/culvertsoft/mnet/IdCreateReply.cpp"
#include "se/culvertsoft/mnet/NodeAnnouncement.cpp"
#include "se/culvertsoft/mnet/DataMessage.cpp"
#include "se/culvertsoft/mnet/NodeDisconnect.cpp"
#include "se/culvertsoft/mnet/ErrorMessage.cpp"
#include "se/culvertsoft/mnet/Dispatcher.cpp"
#include "se/culvertsoft/mnet/Handler.cpp"

namespace se {
namespace culvertsoft {
namespace mnet {

ClassRegistry::ClassRegistry() {
	add<se::culvertsoft::mnet::NodeSettings>();
	add<se::culvertsoft::mnet::NodeUUID>();
	add<se::culvertsoft::mnet::MessageFilter>();
	add<se::culvertsoft::mnet::Message>();
	add<se::culvertsoft::mnet::IdCreateRequest>();
	add<se::culvertsoft::mnet::IdCreateReply>();
	add<se::culvertsoft::mnet::NodeAnnouncement>();
	add<se::culvertsoft::mnet::DataMessage>();
	add<se::culvertsoft::mnet::NodeDisconnect>();
	add<se::culvertsoft::mnet::ErrorMessage>();
}

ClassRegistry::~ClassRegistry() {
}

const mgen::ClassRegistryEntry * se::culvertsoft::mnet::ClassRegistry::getByIds(const std::vector<short>& ids) const {
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeSettings(se::culvertsoft::mnet::NodeSettings::_type_ids(), se::culvertsoft::mnet::NodeSettings::_type_name(), se::culvertsoft::mnet::NodeSettings::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeUUID(se::culvertsoft::mnet::NodeUUID::_type_ids(), se::culvertsoft::mnet::NodeUUID::_type_name(), se::culvertsoft::mnet::NodeUUID::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_MessageFilter(se::culvertsoft::mnet::MessageFilter::_type_ids(), se::culvertsoft::mnet::MessageFilter::_type_name(), se::culvertsoft::mnet::MessageFilter::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_Message(se::culvertsoft::mnet::Message::_type_ids(), se::culvertsoft::mnet::Message::_type_name(), se::culvertsoft::mnet::Message::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_IdCreateRequest(se::culvertsoft::mnet::IdCreateRequest::_type_ids(), se::culvertsoft::mnet::IdCreateRequest::_type_name(), se::culvertsoft::mnet::IdCreateRequest::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_IdCreateReply(se::culvertsoft::mnet::IdCreateReply::_type_ids(), se::culvertsoft::mnet::IdCreateReply::_type_name(), se::culvertsoft::mnet::IdCreateReply::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeAnnouncement(se::culvertsoft::mnet::NodeAnnouncement::_type_ids(), se::culvertsoft::mnet::NodeAnnouncement::_type_name(), se::culvertsoft::mnet::NodeAnnouncement::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_DataMessage(se::culvertsoft::mnet::DataMessage::_type_ids(), se::culvertsoft::mnet::DataMessage::_type_name(), se::culvertsoft::mnet::DataMessage::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeDisconnect(se::culvertsoft::mnet::NodeDisconnect::_type_ids(), se::culvertsoft::mnet::NodeDisconnect::_type_name(), se::culvertsoft::mnet::NodeDisconnect::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_ErrorMessage(se::culvertsoft::mnet::ErrorMessage::_type_ids(), se::culvertsoft::mnet::ErrorMessage::_type_name(), se::culvertsoft::mnet::ErrorMessage::_newInstance);

	std::size_t i = 0;
	switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
		case se::culvertsoft::mnet::NodeSettings::_type_id_16bit:
			return &se_culvertsoft_mnet_NodeSettings;
			break;
		case se::culvertsoft::mnet::NodeUUID::_type_id_16bit:
			return &se_culvertsoft_mnet_NodeUUID;
			break;
		case se::culvertsoft::mnet::MessageFilter::_type_id_16bit:
			return &se_culvertsoft_mnet_MessageFilter;
			break;
		case se::culvertsoft::mnet::Message::_type_id_16bit:
			switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
				case se::culvertsoft::mnet::IdCreateRequest::_type_id_16bit:
					return &se_culvertsoft_mnet_IdCreateRequest;
					break;
				case se::culvertsoft::mnet::IdCreateReply::_type_id_16bit:
					return &se_culvertsoft_mnet_IdCreateReply;
					break;
				case se::culvertsoft::mnet::NodeAnnouncement::_type_id_16bit:
					return &se_culvertsoft_mnet_NodeAnnouncement;
					break;
				case se::culvertsoft::mnet::DataMessage::_type_id_16bit:
					return &se_culvertsoft_mnet_DataMessage;
					break;
				case se::culvertsoft::mnet::NodeDisconnect::_type_id_16bit:
					return &se_culvertsoft_mnet_NodeDisconnect;
					break;
				case se::culvertsoft::mnet::ErrorMessage::_type_id_16bit:
					return &se_culvertsoft_mnet_ErrorMessage;
					break;
				default:
					return &se_culvertsoft_mnet_Message;
					break;
			}
			break;
		default:
			return 0;
			break;
	}
	return 0;
}

const mgen::ClassRegistryEntry * se::culvertsoft::mnet::ClassRegistry::getByIds(const std::vector<std::string>& ids) const {
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeSettings(se::culvertsoft::mnet::NodeSettings::_type_ids(), se::culvertsoft::mnet::NodeSettings::_type_name(), se::culvertsoft::mnet::NodeSettings::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeUUID(se::culvertsoft::mnet::NodeUUID::_type_ids(), se::culvertsoft::mnet::NodeUUID::_type_name(), se::culvertsoft::mnet::NodeUUID::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_MessageFilter(se::culvertsoft::mnet::MessageFilter::_type_ids(), se::culvertsoft::mnet::MessageFilter::_type_name(), se::culvertsoft::mnet::MessageFilter::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_Message(se::culvertsoft::mnet::Message::_type_ids(), se::culvertsoft::mnet::Message::_type_name(), se::culvertsoft::mnet::Message::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_IdCreateRequest(se::culvertsoft::mnet::IdCreateRequest::_type_ids(), se::culvertsoft::mnet::IdCreateRequest::_type_name(), se::culvertsoft::mnet::IdCreateRequest::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_IdCreateReply(se::culvertsoft::mnet::IdCreateReply::_type_ids(), se::culvertsoft::mnet::IdCreateReply::_type_name(), se::culvertsoft::mnet::IdCreateReply::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeAnnouncement(se::culvertsoft::mnet::NodeAnnouncement::_type_ids(), se::culvertsoft::mnet::NodeAnnouncement::_type_name(), se::culvertsoft::mnet::NodeAnnouncement::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_DataMessage(se::culvertsoft::mnet::DataMessage::_type_ids(), se::culvertsoft::mnet::DataMessage::_type_name(), se::culvertsoft::mnet::DataMessage::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_NodeDisconnect(se::culvertsoft::mnet::NodeDisconnect::_type_ids(), se::culvertsoft::mnet::NodeDisconnect::_type_name(), se::culvertsoft::mnet::NodeDisconnect::_newInstance);
	static const mgen::ClassRegistryEntry se_culvertsoft_mnet_ErrorMessage(se::culvertsoft::mnet::ErrorMessage::_type_ids(), se::culvertsoft::mnet::ErrorMessage::_type_name(), se::culvertsoft::mnet::ErrorMessage::_newInstance);

	std::size_t i = 0;
	switch(i < ids.size() ? getTypeId16bitFromTypeId16BitBase64(ids[i++]) : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
		case se::culvertsoft::mnet::NodeSettings::_type_id_16bit:
			return &se_culvertsoft_mnet_NodeSettings;
			break;
		case se::culvertsoft::mnet::NodeUUID::_type_id_16bit:
			return &se_culvertsoft_mnet_NodeUUID;
			break;
		case se::culvertsoft::mnet::MessageFilter::_type_id_16bit:
			return &se_culvertsoft_mnet_MessageFilter;
			break;
		case se::culvertsoft::mnet::Message::_type_id_16bit:
			switch(i < ids.size() ? getTypeId16bitFromTypeId16BitBase64(ids[i++]) : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
				case se::culvertsoft::mnet::IdCreateRequest::_type_id_16bit:
					return &se_culvertsoft_mnet_IdCreateRequest;
					break;
				case se::culvertsoft::mnet::IdCreateReply::_type_id_16bit:
					return &se_culvertsoft_mnet_IdCreateReply;
					break;
				case se::culvertsoft::mnet::NodeAnnouncement::_type_id_16bit:
					return &se_culvertsoft_mnet_NodeAnnouncement;
					break;
				case se::culvertsoft::mnet::DataMessage::_type_id_16bit:
					return &se_culvertsoft_mnet_DataMessage;
					break;
				case se::culvertsoft::mnet::NodeDisconnect::_type_id_16bit:
					return &se_culvertsoft_mnet_NodeDisconnect;
					break;
				case se::culvertsoft::mnet::ErrorMessage::_type_id_16bit:
					return &se_culvertsoft_mnet_ErrorMessage;
					break;
				default:
					return &se_culvertsoft_mnet_Message;
					break;
			}
			break;
		default:
			return 0;
			break;
	}
	return 0;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

