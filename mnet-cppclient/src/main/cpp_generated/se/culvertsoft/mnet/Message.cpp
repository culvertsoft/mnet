/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/Message.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

Message::Message() : 
		m_hops((char)0),
		m_maxHops((char)3),
		m_filter(0),
		_m_senderId_isSet(false),
		_m_targetId_isSet(false),
		_m_hops_isSet(true),
		_m_maxHops_isSet(true) {
}

Message::Message(const NodeUUID& senderId, 
			const NodeUUID& targetId, 
			const char& hops, 
			const char& maxHops, 
			const Polymorphic<MessageFilter> & filter) : 
		m_senderId(senderId),
		m_targetId(targetId),
		m_hops(hops),
		m_maxHops(maxHops),
		m_filter(filter),
		_m_senderId_isSet(true),
		_m_targetId_isSet(true),
		_m_hops_isSet(true),
		_m_maxHops_isSet(true) {
}

Message::~Message() {
}

const NodeUUID& Message::getSenderId() const {
	return m_senderId;
}

const NodeUUID& Message::getTargetId() const {
	return m_targetId;
}

const char& Message::getHops() const {
	return m_hops;
}

const char& Message::getMaxHops() const {
	return m_maxHops;
}

const Polymorphic<MessageFilter> & Message::getFilter() const {
	return m_filter;
}

NodeUUID& Message::getSenderIdMutable() {
	_m_senderId_isSet = true;
	return m_senderId;
}

NodeUUID& Message::getTargetIdMutable() {
	_m_targetId_isSet = true;
	return m_targetId;
}

char& Message::getHopsMutable() {
	_m_hops_isSet = true;
	return m_hops;
}

char& Message::getMaxHopsMutable() {
	_m_maxHops_isSet = true;
	return m_maxHops;
}

Polymorphic<MessageFilter> & Message::getFilterMutable() {
	return m_filter;
}

Message& Message::setSenderId(const NodeUUID& senderId) {
	m_senderId = senderId;
	_m_senderId_isSet = true;
	return *this;
}

Message& Message::setTargetId(const NodeUUID& targetId) {
	m_targetId = targetId;
	_m_targetId_isSet = true;
	return *this;
}

Message& Message::setHops(const char& hops) {
	m_hops = hops;
	_m_hops_isSet = true;
	return *this;
}

Message& Message::setMaxHops(const char& maxHops) {
	m_maxHops = maxHops;
	_m_maxHops_isSet = true;
	return *this;
}

Message& Message::setFilter(const Polymorphic<MessageFilter> & filter) {
	m_filter = filter;
	return *this;
}

Message& Message::setFilter(const MessageFilter & filter) {
	return setFilter(filter._deepCopy(), true);
}

Message& Message::setFilter(MessageFilter * filter, const bool managePtr) {
	m_filter.set(filter, managePtr);
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool Message::hasSenderId() const {
	return _isSenderIdSet(mgen::SHALLOW);
}

bool Message::hasTargetId() const {
	return _isTargetIdSet(mgen::SHALLOW);
}

bool Message::hasHops() const {
	return _isHopsSet(mgen::SHALLOW);
}

bool Message::hasMaxHops() const {
	return _isMaxHopsSet(mgen::SHALLOW);
}

bool Message::hasFilter() const {
	return _isFilterSet(mgen::SHALLOW);
}

Message& Message::unsetSenderId() {
	_setSenderIdSet(false, mgen::SHALLOW);
	return *this;
}

Message& Message::unsetTargetId() {
	_setTargetIdSet(false, mgen::SHALLOW);
	return *this;
}

Message& Message::unsetHops() {
	_setHopsSet(false, mgen::SHALLOW);
	return *this;
}

Message& Message::unsetMaxHops() {
	_setMaxHopsSet(false, mgen::SHALLOW);
	return *this;
}

Message& Message::unsetFilter() {
	_setFilterSet(false, mgen::SHALLOW);
	return *this;
}

bool Message::operator==(const Message& other) const {
	return true
		 && _isSenderIdSet(mgen::SHALLOW) == other._isSenderIdSet(mgen::SHALLOW)
		 && _isTargetIdSet(mgen::SHALLOW) == other._isTargetIdSet(mgen::SHALLOW)
		 && _isHopsSet(mgen::SHALLOW) == other._isHopsSet(mgen::SHALLOW)
		 && _isMaxHopsSet(mgen::SHALLOW) == other._isMaxHopsSet(mgen::SHALLOW)
		 && _isFilterSet(mgen::SHALLOW) == other._isFilterSet(mgen::SHALLOW)
		 && getSenderId() == other.getSenderId()
		 && getTargetId() == other.getTargetId()
		 && getHops() == other.getHops()
		 && getMaxHops() == other.getMaxHops()
		 && getFilter() == other.getFilter();
}

bool Message::operator!=(const Message& other) const {
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
		  
const mgen::Field * Message::_fieldById(const short id) const {
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
	default:
		return 0;
	}
}

const mgen::Field * Message::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("senderId", &Message::_field_senderId_metadata())("targetId", &Message::_field_targetId_metadata())("hops", &Message::_field_hops_metadata())("maxHops", &Message::_field_maxHops_metadata())("filter", &Message::_field_filter_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long Message::_typeId() const {
	return _type_id;
}

const std::string& Message::_typeName() const {
	return _type_name();
}

const short Message::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& Message::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& Message::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& Message::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& Message::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& Message::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& Message::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& Message::_fieldMetadatas() const {
	return _field_metadatas();
}

Message& Message::_setSenderIdSet(const bool state, const mgen::FieldSetDepth depth) {
	if (depth == mgen::DEEP)
		m_senderId._setAllFieldsSet(state, mgen::DEEP);
	_m_senderId_isSet = state;
	return *this;
}

Message& Message::_setTargetIdSet(const bool state, const mgen::FieldSetDepth depth) {
	if (depth == mgen::DEEP)
		m_targetId._setAllFieldsSet(state, mgen::DEEP);
	_m_targetId_isSet = state;
	return *this;
}

Message& Message::_setHopsSet(const bool state, const mgen::FieldSetDepth depth) {
	if (state && !_isHopsSet(mgen::SHALLOW))
		m_hops = (char)0;
	if (!state)
		m_hops = (char)0;
	_m_hops_isSet = state;
	return *this;
}

Message& Message::_setMaxHopsSet(const bool state, const mgen::FieldSetDepth depth) {
	if (state && !_isMaxHopsSet(mgen::SHALLOW))
		m_maxHops = (char)3;
	if (!state)
		m_maxHops = (char)0;
	_m_maxHops_isSet = state;
	return *this;
}

Message& Message::_setFilterSet(const bool state, const mgen::FieldSetDepth depth) {
	m_filter.ensureIsSet(state);
	if (state && depth == mgen::DEEP)
		mgen::validation::setFieldSetDeep(m_filter);
	return *this;
}

Message& Message::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setSenderIdSet(state, depth);
	_setTargetIdSet(state, depth);
	_setHopsSet(state, depth);
	_setMaxHopsSet(state, depth);
	_setFilterSet(state, depth);
	return *this;
}

int Message::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isSenderIdSet(depth) ? 1 : 0;
	out += _isTargetIdSet(depth) ? 1 : 0;
	out += _isHopsSet(depth) ? 1 : 0;
	out += _isMaxHopsSet(depth) ? 1 : 0;
	out += _isFilterSet(depth) ? 1 : 0;
	return out;
}

bool Message::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
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
		default:
			return false;
	}
}

bool Message::_isSenderIdSet(const mgen::FieldSetDepth depth) const {
	if (depth == mgen::SHALLOW) {
		return _m_senderId_isSet;
	} else {
		return _m_senderId_isSet && mgen::validation::validateFieldDeep(getSenderId());
	}
}

bool Message::_isTargetIdSet(const mgen::FieldSetDepth depth) const {
	if (depth == mgen::SHALLOW) {
		return _m_targetId_isSet;
	} else {
		return _m_targetId_isSet && mgen::validation::validateFieldDeep(getTargetId());
	}
}

bool Message::_isHopsSet(const mgen::FieldSetDepth depth) const {
	return _m_hops_isSet;
}

bool Message::_isMaxHopsSet(const mgen::FieldSetDepth depth) const {
	return _m_maxHops_isSet;
}

bool Message::_isFilterSet(const mgen::FieldSetDepth depth) const {
	if (depth == mgen::SHALLOW) {
		return m_filter.get() != 0;
	} else {
		return m_filter.get() != 0 && mgen::validation::validateFieldDeep(getFilter());
	}
}

bool Message::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true
				&& (!_isSenderIdSet(mgen::SHALLOW) || _isSenderIdSet(mgen::DEEP))
				&& (!_isTargetIdSet(mgen::SHALLOW) || _isTargetIdSet(mgen::DEEP))
				&& (!_isFilterSet(mgen::SHALLOW) || _isFilterSet(mgen::DEEP));
	}
}

bool Message::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const Message&>(other) == *this;
}

Message * Message::_deepCopy() const {
	return new Message(*this);
}

mgen::MGenBase * Message::_newInstance() {
	return new Message;
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
		  
const std::string& Message::_type_name() {
	static const std::string out("se.culvertsoft.mnet.Message");
	return out;
}

const std::vector<long long>& Message::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 513154294965126267LL;
	return out;
}

const std::vector<short>& Message::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -28540;
	return out;
}

const std::vector<std::string>& Message::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.Message";
	return out;
}

const std::vector<std::string>& Message::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "kIQ";
	return out;
}

const std::string& Message::_type_ids_16bit_base64_string() {
	static const std::string out("kIQ");
	return out;
}

const std::string& Message::_type_id_16bit_base64() {
	static const std::string out("kIQ");
	return out;
}

const std::vector<mgen::Field>& Message::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_senderId_metadata() << _field_targetId_metadata() << _field_hops_metadata() << _field_maxHops_metadata() << _field_filter_metadata();
	return out;
}

const mgen::Field& Message::_field_senderId_metadata() {
	static const mgen::Field out(1042, "senderId");
	return out;
}

const mgen::Field& Message::_field_targetId_metadata() {
	static const mgen::Field out(20441, "targetId");
	return out;
}

const mgen::Field& Message::_field_hops_metadata() {
	static const mgen::Field out(-22234, "hops");
	return out;
}

const mgen::Field& Message::_field_maxHops_metadata() {
	static const mgen::Field out(-18587, "maxHops");
	return out;
}

const mgen::Field& Message::_field_filter_metadata() {
	static const mgen::Field out(-10901, "filter", mgen::make_vector<std::string>() << "polymorphic");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

