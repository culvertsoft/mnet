/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_IDCREATEREPLY
#define SE_CULVERTSOFT_MNET_IDCREATEREPLY

#include "se/culvertsoft/mnet/Message.h"
#include "se/culvertsoft/mnet/NodeUUID.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

class IdCreateReply : public Message /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	NodeUUID m_createdId;
	bool _m_createdId_isSet;

public:
	IdCreateReply();
	IdCreateReply(const NodeUUID& senderId,
			const NodeUUID& targetId,
			const char& hops,
			const char& maxHops,
			const Polymorphic<MessageFilter> & filter,
			const NodeUUID& createdId);
	virtual ~IdCreateReply();

	const NodeUUID& getCreatedId() const;

	NodeUUID& getCreatedIdMutable();

	IdCreateReply& setSenderId(const NodeUUID& senderId);
	IdCreateReply& setTargetId(const NodeUUID& targetId);
	IdCreateReply& setHops(const char& hops);
	IdCreateReply& setMaxHops(const char& maxHops);
	IdCreateReply& setFilter(const Polymorphic<MessageFilter> & filter);
	IdCreateReply& setFilter(const MessageFilter & filter);
	IdCreateReply& setFilter(MessageFilter * filter, const bool managePtr = true);
	IdCreateReply& setCreatedId(const NodeUUID& createdId);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasCreatedId() const;

	IdCreateReply& unsetSenderId();
	IdCreateReply& unsetTargetId();
	IdCreateReply& unsetHops();
	IdCreateReply& unsetMaxHops();
	IdCreateReply& unsetFilter();
	IdCreateReply& unsetCreatedId();

	bool operator==(const IdCreateReply& other) const;
	bool operator!=(const IdCreateReply& other) const;


							
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
		case _field_createdId_id:
			reader.readField(_field_createdId_metadata(), context, getCreatedIdMutable());
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
				visitor.beginVisit(*this, 6);
				visitor.visit(getSenderId(), _field_senderId_metadata());
				visitor.visit(getTargetId(), _field_targetId_metadata());
				visitor.visit(getHops(), _field_hops_metadata());
				visitor.visit(getMaxHops(), _field_maxHops_metadata());
				visitor.visit(getFilter(), _field_filter_metadata());
				visitor.visit(getCreatedId(), _field_createdId_metadata());
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
				if (_isCreatedIdSet(mgen::SHALLOW))
					visitor.visit(getCreatedId(), _field_createdId_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 6);
				visitor.visit(getSenderIdMutable(), _field_senderId_metadata());
				visitor.visit(getTargetIdMutable(), _field_targetId_metadata());
				visitor.visit(getHopsMutable(), _field_hops_metadata());
				visitor.visit(getMaxHopsMutable(), _field_maxHops_metadata());
				visitor.visit(getFilterMutable(), _field_filter_metadata());
				visitor.visit(getCreatedIdMutable(), _field_createdId_metadata());
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
				if (_isCreatedIdSet(mgen::SHALLOW))
					visitor.visit(getCreatedIdMutable(), _field_createdId_metadata());
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

	IdCreateReply& _setCreatedIdSet(const bool state, const mgen::FieldSetDepth depth);

	IdCreateReply& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isCreatedIdSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	IdCreateReply * _deepCopy() const;

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
		  
	static const long long _type_id = 378799129893336095LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = -20136;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_createdId_metadata();

	static const short _field_createdId_id = -28810;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class IdCreateReply

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
