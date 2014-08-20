/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_NODEDISCONNECT
#define SE_CULVERTSOFT_MNET_NODEDISCONNECT

#include "se/culvertsoft/mnet/Message.h"
#include "se/culvertsoft/mnet/NodeUUID.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

class NodeDisconnect : public Message /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	NodeUUID m_disconnectedNodeId;
	std::string m_reason;
	bool _m_disconnectedNodeId_isSet;
	bool _m_reason_isSet;

public:
	NodeDisconnect();
	NodeDisconnect(const NodeUUID& senderId,
			const NodeUUID& targetId,
			const char& hops,
			const char& maxHops,
			const Polymorphic<MessageFilter> & filter,
			const NodeUUID& disconnectedNodeId,
			const std::string& reason);
	virtual ~NodeDisconnect();

	const NodeUUID& getDisconnectedNodeId() const;
	const std::string& getReason() const;

	NodeUUID& getDisconnectedNodeIdMutable();
	std::string& getReasonMutable();

	NodeDisconnect& setSenderId(const NodeUUID& senderId);
	NodeDisconnect& setTargetId(const NodeUUID& targetId);
	NodeDisconnect& setHops(const char& hops);
	NodeDisconnect& setMaxHops(const char& maxHops);
	NodeDisconnect& setFilter(const Polymorphic<MessageFilter> & filter);
	NodeDisconnect& setFilter(const MessageFilter & filter);
	NodeDisconnect& setFilter(MessageFilter * filter, const bool managePtr = true);
	NodeDisconnect& setDisconnectedNodeId(const NodeUUID& disconnectedNodeId);
	NodeDisconnect& setReason(const std::string& reason);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasDisconnectedNodeId() const;
	bool hasReason() const;

	NodeDisconnect& unsetSenderId();
	NodeDisconnect& unsetTargetId();
	NodeDisconnect& unsetHops();
	NodeDisconnect& unsetMaxHops();
	NodeDisconnect& unsetFilter();
	NodeDisconnect& unsetDisconnectedNodeId();
	NodeDisconnect& unsetReason();

	bool operator==(const NodeDisconnect& other) const;
	bool operator!=(const NodeDisconnect& other) const;


							
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
		case _field_disconnectedNodeId_id:
			reader.readField(_field_disconnectedNodeId_metadata(), context, getDisconnectedNodeIdMutable());
			break;
		case _field_reason_id:
			reader.readField(_field_reason_metadata(), context, getReasonMutable());
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
				visitor.visit(getDisconnectedNodeId(), _field_disconnectedNodeId_metadata());
				visitor.visit(getReason(), _field_reason_metadata());
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
				if (_isDisconnectedNodeIdSet(mgen::SHALLOW))
					visitor.visit(getDisconnectedNodeId(), _field_disconnectedNodeId_metadata());
				if (_isReasonSet(mgen::SHALLOW))
					visitor.visit(getReason(), _field_reason_metadata());
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
				visitor.visit(getDisconnectedNodeIdMutable(), _field_disconnectedNodeId_metadata());
				visitor.visit(getReasonMutable(), _field_reason_metadata());
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
				if (_isDisconnectedNodeIdSet(mgen::SHALLOW))
					visitor.visit(getDisconnectedNodeIdMutable(), _field_disconnectedNodeId_metadata());
				if (_isReasonSet(mgen::SHALLOW))
					visitor.visit(getReasonMutable(), _field_reason_metadata());
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

	NodeDisconnect& _setDisconnectedNodeIdSet(const bool state, const mgen::FieldSetDepth depth);
	NodeDisconnect& _setReasonSet(const bool state, const mgen::FieldSetDepth depth);

	NodeDisconnect& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isDisconnectedNodeIdSet(const mgen::FieldSetDepth depth) const;
	bool _isReasonSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	NodeDisconnect * _deepCopy() const;

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
		  
	static const long long _type_id = 6206250929262320441LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = 8213;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_disconnectedNodeId_metadata();
	static const mgen::Field& _field_reason_metadata();

	static const short _field_disconnectedNodeId_id = -19498;
	static const short _field_reason_id = -15867;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class NodeDisconnect

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
