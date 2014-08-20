/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/ErrorMessage.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

ErrorMessage::ErrorMessage() : 
		_m_msg_isSet(false),
		_m_exceptionType_isSet(false),
		_m_stackTrace_isSet(false) {
}

ErrorMessage::ErrorMessage(const NodeUUID& senderId, 
			const NodeUUID& targetId, 
			const char& hops, 
			const char& maxHops, 
			const Polymorphic<MessageFilter> & filter, 
			const std::string& msg, 
			const std::string& exceptionType, 
			const std::string& stackTrace) : 
		Message(senderId, targetId, hops, maxHops, filter),
		m_msg(msg),
		m_exceptionType(exceptionType),
		m_stackTrace(stackTrace),
		_m_msg_isSet(true),
		_m_exceptionType_isSet(true),
		_m_stackTrace_isSet(true) {
}

ErrorMessage::~ErrorMessage() {
}

const std::string& ErrorMessage::getMsg() const {
	return m_msg;
}

const std::string& ErrorMessage::getExceptionType() const {
	return m_exceptionType;
}

const std::string& ErrorMessage::getStackTrace() const {
	return m_stackTrace;
}

std::string& ErrorMessage::getMsgMutable() {
	_m_msg_isSet = true;
	return m_msg;
}

std::string& ErrorMessage::getExceptionTypeMutable() {
	_m_exceptionType_isSet = true;
	return m_exceptionType;
}

std::string& ErrorMessage::getStackTraceMutable() {
	_m_stackTrace_isSet = true;
	return m_stackTrace;
}

ErrorMessage& ErrorMessage::setSenderId(const NodeUUID& senderId) {
	Message::setSenderId(senderId);
	return *this;
}

ErrorMessage& ErrorMessage::setTargetId(const NodeUUID& targetId) {
	Message::setTargetId(targetId);
	return *this;
}

ErrorMessage& ErrorMessage::setHops(const char& hops) {
	Message::setHops(hops);
	return *this;
}

ErrorMessage& ErrorMessage::setMaxHops(const char& maxHops) {
	Message::setMaxHops(maxHops);
	return *this;
}

ErrorMessage& ErrorMessage::setFilter(const Polymorphic<MessageFilter> & filter) {
	Message::setFilter(filter);
	return *this;
}

ErrorMessage& ErrorMessage::setFilter(const MessageFilter & filter) {
	Message::setFilter(filter);
	return *this;
}

ErrorMessage& ErrorMessage::setFilter(MessageFilter * filter, const bool managePtr) {
	Message::setFilter(filter);
	return *this;
}

ErrorMessage& ErrorMessage::setMsg(const std::string& msg) {
	m_msg = msg;
	_m_msg_isSet = true;
	return *this;
}

ErrorMessage& ErrorMessage::setExceptionType(const std::string& exceptionType) {
	m_exceptionType = exceptionType;
	_m_exceptionType_isSet = true;
	return *this;
}

ErrorMessage& ErrorMessage::setStackTrace(const std::string& stackTrace) {
	m_stackTrace = stackTrace;
	_m_stackTrace_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool ErrorMessage::hasMsg() const {
	return _isMsgSet(mgen::SHALLOW);
}

bool ErrorMessage::hasExceptionType() const {
	return _isExceptionTypeSet(mgen::SHALLOW);
}

bool ErrorMessage::hasStackTrace() const {
	return _isStackTraceSet(mgen::SHALLOW);
}

ErrorMessage& ErrorMessage::unsetSenderId() {
	_setSenderIdSet(false, mgen::SHALLOW);
	return *this;
}

ErrorMessage& ErrorMessage::unsetTargetId() {
	_setTargetIdSet(false, mgen::SHALLOW);
	return *this;
}

ErrorMessage& ErrorMessage::unsetHops() {
	_setHopsSet(false, mgen::SHALLOW);
	return *this;
}

ErrorMessage& ErrorMessage::unsetMaxHops() {
	_setMaxHopsSet(false, mgen::SHALLOW);
	return *this;
}

ErrorMessage& ErrorMessage::unsetFilter() {
	_setFilterSet(false, mgen::SHALLOW);
	return *this;
}

ErrorMessage& ErrorMessage::unsetMsg() {
	_setMsgSet(false, mgen::SHALLOW);
	return *this;
}

ErrorMessage& ErrorMessage::unsetExceptionType() {
	_setExceptionTypeSet(false, mgen::SHALLOW);
	return *this;
}

ErrorMessage& ErrorMessage::unsetStackTrace() {
	_setStackTraceSet(false, mgen::SHALLOW);
	return *this;
}

bool ErrorMessage::operator==(const ErrorMessage& other) const {
	return true
		 && _isSenderIdSet(mgen::SHALLOW) == other._isSenderIdSet(mgen::SHALLOW)
		 && _isTargetIdSet(mgen::SHALLOW) == other._isTargetIdSet(mgen::SHALLOW)
		 && _isHopsSet(mgen::SHALLOW) == other._isHopsSet(mgen::SHALLOW)
		 && _isMaxHopsSet(mgen::SHALLOW) == other._isMaxHopsSet(mgen::SHALLOW)
		 && _isFilterSet(mgen::SHALLOW) == other._isFilterSet(mgen::SHALLOW)
		 && _isMsgSet(mgen::SHALLOW) == other._isMsgSet(mgen::SHALLOW)
		 && _isExceptionTypeSet(mgen::SHALLOW) == other._isExceptionTypeSet(mgen::SHALLOW)
		 && _isStackTraceSet(mgen::SHALLOW) == other._isStackTraceSet(mgen::SHALLOW)
		 && getSenderId() == other.getSenderId()
		 && getTargetId() == other.getTargetId()
		 && getHops() == other.getHops()
		 && getMaxHops() == other.getMaxHops()
		 && getFilter() == other.getFilter()
		 && getMsg() == other.getMsg()
		 && getExceptionType() == other.getExceptionType()
		 && getStackTrace() == other.getStackTrace();
}

bool ErrorMessage::operator!=(const ErrorMessage& other) const {
	return !(*this == other);
}


							
/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                    TYPE METADATA ACCESS AND SERIALIZATION METHODS                    *****
           *****          (accessed primarily by (de-)serializers and for ORM functionality)          *****	
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/	 		  
		  
const mgen::Field * ErrorMessage::_fieldById(const short id) const {
	switch (id) {
	case _field_senderId_id:
		return &_field_senderId_metadata();
	case _field_targetId_id:
		return &_field_targetId_metadata();
	case _field_hops_id:
		return &_field_hops_metadata();
	case _field_maxHops_id:
		return &_field_maxHops_metadata();
	case _field_filter_id:
		return &_field_filter_metadata();
	case _field_msg_id:
		return &_field_msg_metadata();
	case _field_exceptionType_id:
		return &_field_exceptionType_metadata();
	case _field_stackTrace_id:
		return &_field_stackTrace_metadata();
	default:
		return 0;
	}
}

const mgen::Field * ErrorMessage::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("senderId", &ErrorMessage::_field_senderId_metadata())("targetId", &ErrorMessage::_field_targetId_metadata())("hops", &ErrorMessage::_field_hops_metadata())("maxHops", &ErrorMessage::_field_maxHops_metadata())("filter", &ErrorMessage::_field_filter_metadata())("msg", &ErrorMessage::_field_msg_metadata())("exceptionType", &ErrorMessage::_field_exceptionType_metadata())("stackTrace", &ErrorMessage::_field_stackTrace_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long ErrorMessage::_typeId() const {
	return _type_id;
}

const std::string& ErrorMessage::_typeName() const {
	return _type_name();
}

const short ErrorMessage::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& ErrorMessage::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& ErrorMessage::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& ErrorMessage::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& ErrorMessage::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& ErrorMessage::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& ErrorMessage::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& ErrorMessage::_fieldMetadatas() const {
	return _field_metadatas();
}

ErrorMessage& ErrorMessage::_setMsgSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_msg = "";
	_m_msg_isSet = state;
	return *this;
}

ErrorMessage& ErrorMessage::_setExceptionTypeSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_exceptionType = "";
	_m_exceptionType_isSet = state;
	return *this;
}

ErrorMessage& ErrorMessage::_setStackTraceSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_stackTrace = "";
	_m_stackTrace_isSet = state;
	return *this;
}

ErrorMessage& ErrorMessage::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setSenderIdSet(state, depth);
	_setTargetIdSet(state, depth);
	_setHopsSet(state, depth);
	_setMaxHopsSet(state, depth);
	_setFilterSet(state, depth);
	_setMsgSet(state, depth);
	_setExceptionTypeSet(state, depth);
	_setStackTraceSet(state, depth);
	return *this;
}

int ErrorMessage::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isSenderIdSet(depth) ? 1 : 0;
	out += _isTargetIdSet(depth) ? 1 : 0;
	out += _isHopsSet(depth) ? 1 : 0;
	out += _isMaxHopsSet(depth) ? 1 : 0;
	out += _isFilterSet(depth) ? 1 : 0;
	out += _isMsgSet(depth) ? 1 : 0;
	out += _isExceptionTypeSet(depth) ? 1 : 0;
	out += _isStackTraceSet(depth) ? 1 : 0;
	return out;
}

bool ErrorMessage::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
	switch(field.id()) {
		case (_field_senderId_id):
			return _isSenderIdSet(depth);
		case (_field_targetId_id):
			return _isTargetIdSet(depth);
		case (_field_hops_id):
			return _isHopsSet(depth);
		case (_field_maxHops_id):
			return _isMaxHopsSet(depth);
		case (_field_filter_id):
			return _isFilterSet(depth);
		case (_field_msg_id):
			return _isMsgSet(depth);
		case (_field_exceptionType_id):
			return _isExceptionTypeSet(depth);
		case (_field_stackTrace_id):
			return _isStackTraceSet(depth);
		default:
			return false;
	}
}

bool ErrorMessage::_isMsgSet(const mgen::FieldSetDepth depth) const {
	return _m_msg_isSet;
}

bool ErrorMessage::_isExceptionTypeSet(const mgen::FieldSetDepth depth) const {
	return _m_exceptionType_isSet;
}

bool ErrorMessage::_isStackTraceSet(const mgen::FieldSetDepth depth) const {
	return _m_stackTrace_isSet;
}

bool ErrorMessage::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true
				&& (!_isSenderIdSet(mgen::SHALLOW) || _isSenderIdSet(mgen::DEEP))
				&& (!_isTargetIdSet(mgen::SHALLOW) || _isTargetIdSet(mgen::DEEP))
				&& (!_isFilterSet(mgen::SHALLOW) || _isFilterSet(mgen::DEEP));
	}
}

bool ErrorMessage::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const ErrorMessage&>(other) == *this;
}

ErrorMessage * ErrorMessage::_deepCopy() const {
	return new ErrorMessage(*this);
}

mgen::MGenBase * ErrorMessage::_newInstance() {
	return new ErrorMessage;
}


							
/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                                    TYPE METADATA                                     *****
           *****             (generally speaking, it's a bad idea to edit this manually)              *****	
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/	 		  
		  
const std::string& ErrorMessage::_type_name() {
	static const std::string out("se.culvertsoft.mnet.ErrorMessage");
	return out;
}

const std::vector<long long>& ErrorMessage::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 513154294965126267LL << 489319923879967512LL;
	return out;
}

const std::vector<short>& ErrorMessage::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -28540 << -24671;
	return out;
}

const std::vector<std::string>& ErrorMessage::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.Message" << "se.culvertsoft.mnet.ErrorMessage";
	return out;
}

const std::vector<std::string>& ErrorMessage::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "kIQ" << "n6E";
	return out;
}

const std::string& ErrorMessage::_type_ids_16bit_base64_string() {
	static const std::string out("kIQn6E");
	return out;
}

const std::string& ErrorMessage::_type_id_16bit_base64() {
	static const std::string out("n6E");
	return out;
}

const std::vector<mgen::Field>& ErrorMessage::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_senderId_metadata() << _field_targetId_metadata() << _field_hops_metadata() << _field_maxHops_metadata() << _field_filter_metadata() << _field_msg_metadata() << _field_exceptionType_metadata() << _field_stackTrace_metadata();
	return out;
}

const mgen::Field& ErrorMessage::_field_msg_metadata() {
	static const mgen::Field out(21741, "msg");
	return out;
}

const mgen::Field& ErrorMessage::_field_exceptionType_metadata() {
	static const mgen::Field out(-28070, "exceptionType");
	return out;
}

const mgen::Field& ErrorMessage::_field_stackTrace_metadata() {
	static const mgen::Field out(30722, "stackTrace");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

