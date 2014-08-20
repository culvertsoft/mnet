/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_CLASSREGISTRY
#define SE_CULVERTSOFT_MNET_CLASSREGISTRY

#include "mgen/classes/ClassRegistryBase.h"
#include "se/culvertsoft/mnet/NodeSettings.h"
#include "se/culvertsoft/mnet/NodeUUID.h"
#include "se/culvertsoft/mnet/MessageFilter.h"
#include "se/culvertsoft/mnet/Message.h"
#include "se/culvertsoft/mnet/IdCreateRequest.h"
#include "se/culvertsoft/mnet/IdCreateReply.h"
#include "se/culvertsoft/mnet/NodeAnnouncement.h"
#include "se/culvertsoft/mnet/DataMessage.h"
#include "se/culvertsoft/mnet/NodeDisconnect.h"
#include "se/culvertsoft/mnet/ErrorMessage.h"

namespace se {
namespace culvertsoft {
namespace mnet {

class ClassRegistry : public mgen::ClassRegistryBase  {
public:

	ClassRegistry();
	virtual ~ClassRegistry();

	template<typename ContextType, typename ReaderType>
	void readObjectFields(mgen::MGenBase& o, ContextType& context, ReaderType& reader) const {

		const std::vector<short>& ids = o._typeIds16Bit();

		std::size_t i = 0;
		switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
			case se::culvertsoft::mnet::NodeSettings::_type_id_16bit:
				reader.readFields(static_cast<se::culvertsoft::mnet::NodeSettings&>(o), context);
				break;
			case se::culvertsoft::mnet::NodeUUID::_type_id_16bit:
				reader.readFields(static_cast<se::culvertsoft::mnet::NodeUUID&>(o), context);
				break;
			case se::culvertsoft::mnet::MessageFilter::_type_id_16bit:
				reader.readFields(static_cast<se::culvertsoft::mnet::MessageFilter&>(o), context);
				break;
			case se::culvertsoft::mnet::Message::_type_id_16bit:
				switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
					case se::culvertsoft::mnet::IdCreateRequest::_type_id_16bit:
						reader.readFields(static_cast<se::culvertsoft::mnet::IdCreateRequest&>(o), context);
						break;
					case se::culvertsoft::mnet::IdCreateReply::_type_id_16bit:
						reader.readFields(static_cast<se::culvertsoft::mnet::IdCreateReply&>(o), context);
						break;
					case se::culvertsoft::mnet::NodeAnnouncement::_type_id_16bit:
						reader.readFields(static_cast<se::culvertsoft::mnet::NodeAnnouncement&>(o), context);
						break;
					case se::culvertsoft::mnet::DataMessage::_type_id_16bit:
						reader.readFields(static_cast<se::culvertsoft::mnet::DataMessage&>(o), context);
						break;
					case se::culvertsoft::mnet::NodeDisconnect::_type_id_16bit:
						reader.readFields(static_cast<se::culvertsoft::mnet::NodeDisconnect&>(o), context);
						break;
					case se::culvertsoft::mnet::ErrorMessage::_type_id_16bit:
						reader.readFields(static_cast<se::culvertsoft::mnet::ErrorMessage&>(o), context);
						break;
					default:
						reader.readFields(static_cast<se::culvertsoft::mnet::Message&>(o), context);
						break;
				}
				break;
			default:
				return;
				break;
		}
		return;
	}

	template<typename VisitorType>
	void visitObject(mgen::MGenBase& o, VisitorType& visitor, const mgen::FieldVisitSelection selection) const {

		const std::vector<short>& ids = o._typeIds16Bit();

		std::size_t i = 0;
		switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
			case se::culvertsoft::mnet::NodeSettings::_type_id_16bit:
				static_cast<se::culvertsoft::mnet::NodeSettings&>(o)._accept<VisitorType>(visitor, selection);
				break;
			case se::culvertsoft::mnet::NodeUUID::_type_id_16bit:
				static_cast<se::culvertsoft::mnet::NodeUUID&>(o)._accept<VisitorType>(visitor, selection);
				break;
			case se::culvertsoft::mnet::MessageFilter::_type_id_16bit:
				static_cast<se::culvertsoft::mnet::MessageFilter&>(o)._accept<VisitorType>(visitor, selection);
				break;
			case se::culvertsoft::mnet::Message::_type_id_16bit:
				switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
					case se::culvertsoft::mnet::IdCreateRequest::_type_id_16bit:
						static_cast<se::culvertsoft::mnet::IdCreateRequest&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::IdCreateReply::_type_id_16bit:
						static_cast<se::culvertsoft::mnet::IdCreateReply&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::NodeAnnouncement::_type_id_16bit:
						static_cast<se::culvertsoft::mnet::NodeAnnouncement&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::DataMessage::_type_id_16bit:
						static_cast<se::culvertsoft::mnet::DataMessage&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::NodeDisconnect::_type_id_16bit:
						static_cast<se::culvertsoft::mnet::NodeDisconnect&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::ErrorMessage::_type_id_16bit:
						static_cast<se::culvertsoft::mnet::ErrorMessage&>(o)._accept<VisitorType>(visitor, selection);
						break;
					default:
						static_cast<se::culvertsoft::mnet::Message&>(o)._accept<VisitorType>(visitor, selection);
						break;
				}
				break;
			default:
				return;
				break;
		}
		return;
	}

	template<typename VisitorType>
	void visitObject(const mgen::MGenBase& o, VisitorType& visitor, const mgen::FieldVisitSelection selection) const {

		const std::vector<short>& ids = o._typeIds16Bit();

		std::size_t i = 0;
		switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
			case se::culvertsoft::mnet::NodeSettings::_type_id_16bit:
				static_cast<const se::culvertsoft::mnet::NodeSettings&>(o)._accept<VisitorType>(visitor, selection);
				break;
			case se::culvertsoft::mnet::NodeUUID::_type_id_16bit:
				static_cast<const se::culvertsoft::mnet::NodeUUID&>(o)._accept<VisitorType>(visitor, selection);
				break;
			case se::culvertsoft::mnet::MessageFilter::_type_id_16bit:
				static_cast<const se::culvertsoft::mnet::MessageFilter&>(o)._accept<VisitorType>(visitor, selection);
				break;
			case se::culvertsoft::mnet::Message::_type_id_16bit:
				switch(i < ids.size() ? ids[i++] : mgen::ClassRegistryBase::INVALID_16BIT_ID) {
					case se::culvertsoft::mnet::IdCreateRequest::_type_id_16bit:
						static_cast<const se::culvertsoft::mnet::IdCreateRequest&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::IdCreateReply::_type_id_16bit:
						static_cast<const se::culvertsoft::mnet::IdCreateReply&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::NodeAnnouncement::_type_id_16bit:
						static_cast<const se::culvertsoft::mnet::NodeAnnouncement&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::DataMessage::_type_id_16bit:
						static_cast<const se::culvertsoft::mnet::DataMessage&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::NodeDisconnect::_type_id_16bit:
						static_cast<const se::culvertsoft::mnet::NodeDisconnect&>(o)._accept<VisitorType>(visitor, selection);
						break;
					case se::culvertsoft::mnet::ErrorMessage::_type_id_16bit:
						static_cast<const se::culvertsoft::mnet::ErrorMessage&>(o)._accept<VisitorType>(visitor, selection);
						break;
					default:
						static_cast<const se::culvertsoft::mnet::Message&>(o)._accept<VisitorType>(visitor, selection);
						break;
				}
				break;
			default:
				return;
				break;
		}
		return;
	}

	const mgen::ClassRegistryEntry * getByIds(const std::vector<short>& ids) const;

	const mgen::ClassRegistryEntry * getByIds(const std::vector<std::string>& ids) const;

}; // End class ClassRegistry

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
