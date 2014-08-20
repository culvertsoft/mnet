/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_NODEANNOUNCEMENT
#define SE_CULVERTSOFT_MNET_NODEANNOUNCEMENT

#include "se/culvertsoft/mnet/Message.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

class NodeAnnouncement : public Message /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	std::string m_name;
	std::vector<std::string>  m_tags;
	bool _m_name_isSet;
	bool _m_tags_isSet;

public:
	NodeAnnouncement();
	NodeAnnouncement(const NodeUUID& senderId,
			const NodeUUID& targetId,
			const char& hops,
			const char& maxHops,
			const Polymorphic<MessageFilter> & filter,
			const std::string& name,
			const std::vector<std::string> & tags);
	virtual ~NodeAnnouncement();

	const std::string& getName() const;
	const std::vector<std::string> & getTags() const;

	std::string& getNameMutable();
	std::vector<std::string> & getTagsMutable();

	NodeAnnouncement& setSenderId(const NodeUUID& senderId);
	NodeAnnouncement& setTargetId(const NodeUUID& targetId);
	NodeAnnouncement& setHops(const char& hops);
	NodeAnnouncement& setMaxHops(const char& maxHops);
	NodeAnnouncement& setFilter(const Polymorphic<MessageFilter> & filter);
	NodeAnnouncement& setFilter(const MessageFilter & filter);
	NodeAnnouncement& setFilter(MessageFilter * filter, const bool managePtr = true);
	NodeAnnouncement& setName(const std::string& name);
	NodeAnnouncement& setTags(const std::vector<std::string> & tags);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasName() const;
	bool hasTags() const;

	NodeAnnouncement& unsetSenderId();
	NodeAnnouncement& unsetTargetId();
	NodeAnnouncement& unsetHops();
	NodeAnnouncement& unsetMaxHops();
	NodeAnnouncement& unsetFilter();
	NodeAnnouncement& unsetName();
	NodeAnnouncement& unsetTags();

	bool operator==(const NodeAnnouncement& other) const;
	bool operator!=(const NodeAnnouncement& other) const;


							
/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                    TYPE METADATA ACCESS AND SERIALIZATION METHODS                    *****
           *****          (accessed primarily by (de-)serializers and for ORM functionality)          *****	
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/	 		  
		  
public:
	template<typename ReaderType, typename ReadContextType>
	void _readField(const short fieldId, ReadContextType& context, ReaderType& reader) {
		switch (fieldId) {
		case _field_senderId_id:
			reader.readField(_field_senderId_metadata(), context, getSenderIdMutable());
			break;
		case _field_targetId_id:
			reader.readField(_field_targetId_metadata(), context, getTargetIdMutable());
			break;
		case _field_hops_id:
			reader.readField(_field_hops_metadata(), context, getHopsMutable());
			break;
		case _field_maxHops_id:
			reader.readField(_field_maxHops_metadata(), context, getMaxHopsMutable());
			break;
		case _field_filter_id:
			reader.readField(_field_filter_metadata(), context, getFilterMutable());
			break;
		case _field_name_id:
			reader.readField(_field_name_metadata(), context, getNameMutable());
			break;
		case _field_tags_id:
			reader.readField(_field_tags_metadata(), context, getTagsMutable());
			break;
		default:
			reader.handleUnknownField(fieldId, context);
			break;
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) const {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 7);
				visitor.visit(getSenderId(), _field_senderId_metadata());
				visitor.visit(getTargetId(), _field_targetId_metadata());
				visitor.visit(getHops(), _field_hops_metadata());
				visitor.visit(getMaxHops(), _field_maxHops_metadata());
				visitor.visit(getFilter(), _field_filter_metadata());
				visitor.visit(getName(), _field_name_metadata());
				visitor.visit(getTags(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isSenderIdSet(mgen::SHALLOW))
					visitor.visit(getSenderId(), _field_senderId_metadata());
				if (_isTargetIdSet(mgen::SHALLOW))
					visitor.visit(getTargetId(), _field_targetId_metadata());
				if (_isHopsSet(mgen::SHALLOW))
					visitor.visit(getHops(), _field_hops_metadata());
				if (_isMaxHopsSet(mgen::SHALLOW))
					visitor.visit(getMaxHops(), _field_maxHops_metadata());
				if (_isFilterSet(mgen::SHALLOW))
					visitor.visit(getFilter(), _field_filter_metadata());
				if (_isNameSet(mgen::SHALLOW))
					visitor.visit(getName(), _field_name_metadata());
				if (_isTagsSet(mgen::SHALLOW))
					visitor.visit(getTags(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 7);
				visitor.visit(getSenderIdMutable(), _field_senderId_metadata());
				visitor.visit(getTargetIdMutable(), _field_targetId_metadata());
				visitor.visit(getHopsMutable(), _field_hops_metadata());
				visitor.visit(getMaxHopsMutable(), _field_maxHops_metadata());
				visitor.visit(getFilterMutable(), _field_filter_metadata());
				visitor.visit(getNameMutable(), _field_name_metadata());
				visitor.visit(getTagsMutable(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isSenderIdSet(mgen::SHALLOW))
					visitor.visit(getSenderIdMutable(), _field_senderId_metadata());
				if (_isTargetIdSet(mgen::SHALLOW))
					visitor.visit(getTargetIdMutable(), _field_targetId_metadata());
				if (_isHopsSet(mgen::SHALLOW))
					visitor.visit(getHopsMutable(), _field_hops_metadata());
				if (_isMaxHopsSet(mgen::SHALLOW))
					visitor.visit(getMaxHopsMutable(), _field_maxHops_metadata());
				if (_isFilterSet(mgen::SHALLOW))
					visitor.visit(getFilterMutable(), _field_filter_metadata());
				if (_isNameSet(mgen::SHALLOW))
					visitor.visit(getNameMutable(), _field_name_metadata());
				if (_isTagsSet(mgen::SHALLOW))
					visitor.visit(getTagsMutable(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	const mgen::Field * _fieldById(const short id) const;
	const mgen::Field * _fieldByName(const std::string& name) const;
	const long long _typeId() const;
	const short _typeId16Bit() const;
	const std::string& _typeId16BitBase64() const;
	const std::string& _typeName() const;

	const std::vector<long long>& _typeIds() const;
	const std::vector<short>& _typeIds16Bit() const;
	const std::vector<std::string>& _typeIds16BitBase64() const;
	const std::string& _typeIds16BitBase64String() const;
	const std::vector<std::string>& _typeNames() const;

	const std::vector<mgen::Field>& _fieldMetadatas() const;

	bool _isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const;

	NodeAnnouncement& _setNameSet(const bool state, const mgen::FieldSetDepth depth);
	NodeAnnouncement& _setTagsSet(const bool state, const mgen::FieldSetDepth depth);

	NodeAnnouncement& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isNameSet(const mgen::FieldSetDepth depth) const;
	bool _isTagsSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	NodeAnnouncement * _deepCopy() const;

	static mgen::MGenBase * _newInstance();

							
/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                                    TYPE METADATA                                     *****
           *****             (generally speaking, it's a bad idea to edit this manually)              *****	
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/	 		  
		  
	static const long long _type_id = 6374302276601972660LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = -6041;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_name_metadata();
	static const mgen::Field& _field_tags_metadata();

	static const short _field_name_id = -28058;
	static const short _field_tags_id = 31830;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class NodeAnnouncement

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
