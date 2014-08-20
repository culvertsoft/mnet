/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_MESSAGE
#define SE_CULVERTSOFT_MNET_MESSAGE

#include "mgen/classes/MGenBase.h"
#include "se/culvertsoft/mnet/MessageFilter.h"
#include "se/culvertsoft/mnet/NodeUUID.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

using mgen::Polymorphic;

class Message : public mgen::MGenBase /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	NodeUUID m_senderId;
	NodeUUID m_targetId;
	char m_hops;
	char m_maxHops;
	Polymorphic<MessageFilter>  m_filter;
	bool _m_senderId_isSet;
	bool _m_targetId_isSet;
	bool _m_hops_isSet;
	bool _m_maxHops_isSet;

public:
	Message();
	Message(const NodeUUID& senderId,
			const NodeUUID& targetId,
			const char& hops,
			const char& maxHops,
			const Polymorphic<MessageFilter> & filter);
	virtual ~Message();

	const NodeUUID& getSenderId() const;
	const NodeUUID& getTargetId() const;
	const char& getHops() const;
	const char& getMaxHops() const;
	const Polymorphic<MessageFilter> & getFilter() const;

	NodeUUID& getSenderIdMutable();
	NodeUUID& getTargetIdMutable();
	char& getHopsMutable();
	char& getMaxHopsMutable();
	Polymorphic<MessageFilter> & getFilterMutable();

	Message& setSenderId(const NodeUUID& senderId);
	Message& setTargetId(const NodeUUID& targetId);
	Message& setHops(const char& hops);
	Message& setMaxHops(const char& maxHops);
	Message& setFilter(const Polymorphic<MessageFilter> & filter);
	Message& setFilter(const MessageFilter & filter);
	Message& setFilter(MessageFilter * filter, const bool managePtr = true);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasSenderId() const;
	bool hasTargetId() const;
	bool hasHops() const;
	bool hasMaxHops() const;
	bool hasFilter() const;

	Message& unsetSenderId();
	Message& unsetTargetId();
	Message& unsetHops();
	Message& unsetMaxHops();
	Message& unsetFilter();

	bool operator==(const Message& other) const;
	bool operator!=(const Message& other) const;


							
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
		default:
			reader.handleUnknownField(fieldId, context);
			break;
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) const {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 5);
				visitor.visit(getSenderId(), _field_senderId_metadata());
				visitor.visit(getTargetId(), _field_targetId_metadata());
				visitor.visit(getHops(), _field_hops_metadata());
				visitor.visit(getMaxHops(), _field_maxHops_metadata());
				visitor.visit(getFilter(), _field_filter_metadata());
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
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 5);
				visitor.visit(getSenderIdMutable(), _field_senderId_metadata());
				visitor.visit(getTargetIdMutable(), _field_targetId_metadata());
				visitor.visit(getHopsMutable(), _field_hops_metadata());
				visitor.visit(getMaxHopsMutable(), _field_maxHops_metadata());
				visitor.visit(getFilterMutable(), _field_filter_metadata());
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

	Message& _setSenderIdSet(const bool state, const mgen::FieldSetDepth depth);
	Message& _setTargetIdSet(const bool state, const mgen::FieldSetDepth depth);
	Message& _setHopsSet(const bool state, const mgen::FieldSetDepth depth);
	Message& _setMaxHopsSet(const bool state, const mgen::FieldSetDepth depth);
	Message& _setFilterSet(const bool state, const mgen::FieldSetDepth depth);

	Message& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isSenderIdSet(const mgen::FieldSetDepth depth) const;
	bool _isTargetIdSet(const mgen::FieldSetDepth depth) const;
	bool _isHopsSet(const mgen::FieldSetDepth depth) const;
	bool _isMaxHopsSet(const mgen::FieldSetDepth depth) const;
	bool _isFilterSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	Message * _deepCopy() const;

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
		  
	static const long long _type_id = 513154294965126267LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = -28540;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_senderId_metadata();
	static const mgen::Field& _field_targetId_metadata();
	static const mgen::Field& _field_hops_metadata();
	static const mgen::Field& _field_maxHops_metadata();
	static const mgen::Field& _field_filter_metadata();

	static const short _field_senderId_id = 1042;
	static const short _field_targetId_id = 20441;
	static const short _field_hops_id = -22234;
	static const short _field_maxHops_id = -18587;
	static const short _field_filter_id = -10901;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class Message

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
