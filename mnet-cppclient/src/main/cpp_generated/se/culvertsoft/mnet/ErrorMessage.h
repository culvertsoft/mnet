/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_ERRORMESSAGE
#define SE_CULVERTSOFT_MNET_ERRORMESSAGE

#include "se/culvertsoft/mnet/Message.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

class ErrorMessage : public Message /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	std::string m_msg;
	std::string m_exceptionType;
	std::string m_stackTrace;
	bool _m_msg_isSet;
	bool _m_exceptionType_isSet;
	bool _m_stackTrace_isSet;

public:
	ErrorMessage();
	ErrorMessage(const NodeUUID& senderId,
			const NodeUUID& targetId,
			const char& hops,
			const char& maxHops,
			const Polymorphic<MessageFilter> & filter,
			const std::string& msg,
			const std::string& exceptionType,
			const std::string& stackTrace);
	virtual ~ErrorMessage();

	const std::string& getMsg() const;
	const std::string& getExceptionType() const;
	const std::string& getStackTrace() const;

	std::string& getMsgMutable();
	std::string& getExceptionTypeMutable();
	std::string& getStackTraceMutable();

	ErrorMessage& setSenderId(const NodeUUID& senderId);
	ErrorMessage& setTargetId(const NodeUUID& targetId);
	ErrorMessage& setHops(const char& hops);
	ErrorMessage& setMaxHops(const char& maxHops);
	ErrorMessage& setFilter(const Polymorphic<MessageFilter> & filter);
	ErrorMessage& setFilter(const MessageFilter & filter);
	ErrorMessage& setFilter(MessageFilter * filter, const bool managePtr = true);
	ErrorMessage& setMsg(const std::string& msg);
	ErrorMessage& setExceptionType(const std::string& exceptionType);
	ErrorMessage& setStackTrace(const std::string& stackTrace);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasMsg() const;
	bool hasExceptionType() const;
	bool hasStackTrace() const;

	ErrorMessage& unsetSenderId();
	ErrorMessage& unsetTargetId();
	ErrorMessage& unsetHops();
	ErrorMessage& unsetMaxHops();
	ErrorMessage& unsetFilter();
	ErrorMessage& unsetMsg();
	ErrorMessage& unsetExceptionType();
	ErrorMessage& unsetStackTrace();

	bool operator==(const ErrorMessage& other) const;
	bool operator!=(const ErrorMessage& other) const;


							
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
		case _field_msg_id:
			reader.readField(_field_msg_metadata(), context, getMsgMutable());
			break;
		case _field_exceptionType_id:
			reader.readField(_field_exceptionType_metadata(), context, getExceptionTypeMutable());
			break;
		case _field_stackTrace_id:
			reader.readField(_field_stackTrace_metadata(), context, getStackTraceMutable());
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
				visitor.beginVisit(*this, 8);
				visitor.visit(getSenderId(), _field_senderId_metadata());
				visitor.visit(getTargetId(), _field_targetId_metadata());
				visitor.visit(getHops(), _field_hops_metadata());
				visitor.visit(getMaxHops(), _field_maxHops_metadata());
				visitor.visit(getFilter(), _field_filter_metadata());
				visitor.visit(getMsg(), _field_msg_metadata());
				visitor.visit(getExceptionType(), _field_exceptionType_metadata());
				visitor.visit(getStackTrace(), _field_stackTrace_metadata());
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
				if (_isMsgSet(mgen::SHALLOW))
					visitor.visit(getMsg(), _field_msg_metadata());
				if (_isExceptionTypeSet(mgen::SHALLOW))
					visitor.visit(getExceptionType(), _field_exceptionType_metadata());
				if (_isStackTraceSet(mgen::SHALLOW))
					visitor.visit(getStackTrace(), _field_stackTrace_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 8);
				visitor.visit(getSenderIdMutable(), _field_senderId_metadata());
				visitor.visit(getTargetIdMutable(), _field_targetId_metadata());
				visitor.visit(getHopsMutable(), _field_hops_metadata());
				visitor.visit(getMaxHopsMutable(), _field_maxHops_metadata());
				visitor.visit(getFilterMutable(), _field_filter_metadata());
				visitor.visit(getMsgMutable(), _field_msg_metadata());
				visitor.visit(getExceptionTypeMutable(), _field_exceptionType_metadata());
				visitor.visit(getStackTraceMutable(), _field_stackTrace_metadata());
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
				if (_isMsgSet(mgen::SHALLOW))
					visitor.visit(getMsgMutable(), _field_msg_metadata());
				if (_isExceptionTypeSet(mgen::SHALLOW))
					visitor.visit(getExceptionTypeMutable(), _field_exceptionType_metadata());
				if (_isStackTraceSet(mgen::SHALLOW))
					visitor.visit(getStackTraceMutable(), _field_stackTrace_metadata());
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

	ErrorMessage& _setMsgSet(const bool state, const mgen::FieldSetDepth depth);
	ErrorMessage& _setExceptionTypeSet(const bool state, const mgen::FieldSetDepth depth);
	ErrorMessage& _setStackTraceSet(const bool state, const mgen::FieldSetDepth depth);

	ErrorMessage& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isMsgSet(const mgen::FieldSetDepth depth) const;
	bool _isExceptionTypeSet(const mgen::FieldSetDepth depth) const;
	bool _isStackTraceSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	ErrorMessage * _deepCopy() const;

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
		  
	static const long long _type_id = 489319923879967512LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = -24671;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_msg_metadata();
	static const mgen::Field& _field_exceptionType_metadata();
	static const mgen::Field& _field_stackTrace_metadata();

	static const short _field_msg_id = 21741;
	static const short _field_exceptionType_id = -28070;
	static const short _field_stackTrace_id = 30722;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class ErrorMessage

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
