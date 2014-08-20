/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/NodeDisconnect.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

NodeDisconnect::NodeDisconnect() : 
		_m_disconnectedNodeId_isSet(false),
		_m_reason_isSet(false) {
}

NodeDisconnect::NodeDisconnect(const NodeUUID& senderId, 
			const NodeUUID& targetId, 
			const char& hops, 
			const char& maxHops, 
			const Polymorphic<MessageFilter> & filter, 
			const NodeUUID& disconnectedNodeId, 
			const std::string& reason) : 
		Message(senderId, targetId, hops, maxHops, filter),
		m_disconnectedNodeId(disconnectedNodeId),
		m_reason(reason),
		_m_disconnectedNodeId_isSet(true),
		_m_reason_isSet(true) {
}

NodeDisconnect::~NodeDisconnect() {
}

const NodeUUID& NodeDisconnect::getDisconnectedNodeId() const {
	return m_disconnectedNodeId;
}

const std::string& NodeDisconnect::getReason() const {
	return m_reason;
}

NodeUUID& NodeDisconnect::getDisconnectedNodeIdMutable() {
	_m_disconnectedNodeId_isSet = true;
	return m_disconnectedNodeId;
}

std::string& NodeDisconnect::getReasonMutable() {
	_m_reason_isSet = true;
	return m_reason;
}

NodeDisconnect& NodeDisconnect::setSenderId(const NodeUUID& senderId) {
	Message::setSenderId(senderId);
	return *this;
}

NodeDisconnect& NodeDisconnect::setTargetId(const NodeUUID& targetId) {
	Message::setTargetId(targetId);
	return *this;
}

NodeDisconnect& NodeDisconnect::setHops(const char& hops) {
	Message::setHops(hops);
	return *this;
}

NodeDisconnect& NodeDisconnect::setMaxHops(const char& maxHops) {
	Message::setMaxHops(maxHops);
	return *this;
}

NodeDisconnect& NodeDisconnect::setFilter(const Polymorphic<MessageFilter> & filter) {
	Message::setFilter(filter);
	return *this;
}

NodeDisconnect& NodeDisconnect::setFilter(const MessageFilter & filter) {
	Message::setFilter(filter);
	return *this;
}

NodeDisconnect& NodeDisconnect::setFilter(MessageFilter * filter, const bool managePtr) {
	Message::setFilter(filter);
	return *this;
}

NodeDisconnect& NodeDisconnect::setDisconnectedNodeId(const NodeUUID& disconnectedNodeId) {
	m_disconnectedNodeId = disconnectedNodeId;
	_m_disconnectedNodeId_isSet = true;
	return *this;
}

NodeDisconnect& NodeDisconnect::setReason(const std::string& reason) {
	m_reason = reason;
	_m_reason_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool NodeDisconnect::hasDisconnectedNodeId() const {
	return _isDisconnectedNodeIdSet(mgen::SHALLOW);
}

bool NodeDisconnect::hasReason() const {
	return _isReasonSet(mgen::SHALLOW);
}

NodeDisconnect& NodeDisconnect::unsetSenderId() {
	_setSenderIdSet(false, mgen::SHALLOW);
	return *this;
}

NodeDisconnect& NodeDisconnect::unsetTargetId() {
	_setTargetIdSet(false, mgen::SHALLOW);
	return *this;
}

NodeDisconnect& NodeDisconnect::unsetHops() {
	_setHopsSet(false, mgen::SHALLOW);
	return *this;
}

NodeDisconnect& NodeDisconnect::unsetMaxHops() {
	_setMaxHopsSet(false, mgen::SHALLOW);
	return *this;
}

NodeDisconnect& NodeDisconnect::unsetFilter() {
	_setFilterSet(false, mgen::SHALLOW);
	return *this;
}

NodeDisconnect& NodeDisconnect::unsetDisconnectedNodeId() {
	_setDisconnectedNodeIdSet(false, mgen::SHALLOW);
	return *this;
}

NodeDisconnect& NodeDisconnect::unsetReason() {
	_setReasonSet(false, mgen::SHALLOW);
	return *this;
}

bool NodeDisconnect::operator==(const NodeDisconnect& other) const {
	return true
		 && _isSenderIdSet(mgen::SHALLOW) == other._isSenderIdSet(mgen::SHALLOW)
		 && _isTargetIdSet(mgen::SHALLOW) == other._isTargetIdSet(mgen::SHALLOW)
		 && _isHopsSet(mgen::SHALLOW) == other._isHopsSet(mgen::SHALLOW)
		 && _isMaxHopsSet(mgen::SHALLOW) == other._isMaxHopsSet(mgen::SHALLOW)
		 && _isFilterSet(mgen::SHALLOW) == other._isFilterSet(mgen::SHALLOW)
		 && _isDisconnectedNodeIdSet(mgen::SHALLOW) == other._isDisconnectedNodeIdSet(mgen::SHALLOW)
		 && _isReasonSet(mgen::SHALLOW) == other._isReasonSet(mgen::SHALLOW)
		 && getSenderId() == other.getSenderId()
		 && getTargetId() == other.getTargetId()
		 && getHops() == other.getHops()
		 && getMaxHops() == other.getMaxHops()
		 && getFilter() == other.getFilter()
		 && getDisconnectedNodeId() == other.getDisconnectedNodeId()
		 && getReason() == other.getReason();
}

bool NodeDisconnect::operator!=(const NodeDisconnect& other) const {
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
		  
const mgen::Field * NodeDisconnect::_fieldById(const short id) const {
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
	case _field_disconnectedNodeId_id:
		return &_field_disconnectedNodeId_metadata();
	case _field_reason_id:
		return &_field_reason_metadata();
	default:
		return 0;
	}
}

const mgen::Field * NodeDisconnect::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("senderId", &NodeDisconnect::_field_senderId_metadata())("targetId", &NodeDisconnect::_field_targetId_metadata())("hops", &NodeDisconnect::_field_hops_metadata())("maxHops", &NodeDisconnect::_field_maxHops_metadata())("filter", &NodeDisconnect::_field_filter_metadata())("disconnectedNodeId", &NodeDisconnect::_field_disconnectedNodeId_metadata())("reason", &NodeDisconnect::_field_reason_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long NodeDisconnect::_typeId() const {
	return _type_id;
}

const std::string& NodeDisconnect::_typeName() const {
	return _type_name();
}

const short NodeDisconnect::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& NodeDisconnect::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& NodeDisconnect::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& NodeDisconnect::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& NodeDisconnect::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& NodeDisconnect::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& NodeDisconnect::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& NodeDisconnect::_fieldMetadatas() const {
	return _field_metadatas();
}

NodeDisconnect& NodeDisconnect::_setDisconnectedNodeIdSet(const bool state, const mgen::FieldSetDepth depth) {
	if (depth == mgen::DEEP)
		m_disconnectedNodeId._setAllFieldsSet(state, mgen::DEEP);
	_m_disconnectedNodeId_isSet = state;
	return *this;
}

NodeDisconnect& NodeDisconnect::_setReasonSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_reason = "";
	_m_reason_isSet = state;
	return *this;
}

NodeDisconnect& NodeDisconnect::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setSenderIdSet(state, depth);
	_setTargetIdSet(state, depth);
	_setHopsSet(state, depth);
	_setMaxHopsSet(state, depth);
	_setFilterSet(state, depth);
	_setDisconnectedNodeIdSet(state, depth);
	_setReasonSet(state, depth);
	return *this;
}

int NodeDisconnect::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isSenderIdSet(depth) ? 1 : 0;
	out += _isTargetIdSet(depth) ? 1 : 0;
	out += _isHopsSet(depth) ? 1 : 0;
	out += _isMaxHopsSet(depth) ? 1 : 0;
	out += _isFilterSet(depth) ? 1 : 0;
	out += _isDisconnectedNodeIdSet(depth) ? 1 : 0;
	out += _isReasonSet(depth) ? 1 : 0;
	return out;
}

bool NodeDisconnect::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
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
		case (_field_disconnectedNodeId_id):
			return _isDisconnectedNodeIdSet(depth);
		case (_field_reason_id):
			return _isReasonSet(depth);
		default:
			return false;
	}
}

bool NodeDisconnect::_isDisconnectedNodeIdSet(const mgen::FieldSetDepth depth) const {
	if (depth == mgen::SHALLOW) {
		return _m_disconnectedNodeId_isSet;
	} else {
		return _m_disconnectedNodeId_isSet && mgen::validation::validateFieldDeep(getDisconnectedNodeId());
	}
}

bool NodeDisconnect::_isReasonSet(const mgen::FieldSetDepth depth) const {
	return _m_reason_isSet;
}

bool NodeDisconnect::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true
				&& (!_isSenderIdSet(mgen::SHALLOW) || _isSenderIdSet(mgen::DEEP))
				&& (!_isTargetIdSet(mgen::SHALLOW) || _isTargetIdSet(mgen::DEEP))
				&& (!_isFilterSet(mgen::SHALLOW) || _isFilterSet(mgen::DEEP))
				&& (!_isDisconnectedNodeIdSet(mgen::SHALLOW) || _isDisconnectedNodeIdSet(mgen::DEEP));
	}
}

bool NodeDisconnect::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const NodeDisconnect&>(other) == *this;
}

NodeDisconnect * NodeDisconnect::_deepCopy() const {
	return new NodeDisconnect(*this);
}

mgen::MGenBase * NodeDisconnect::_newInstance() {
	return new NodeDisconnect;
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
		  
const std::string& NodeDisconnect::_type_name() {
	static const std::string out("se.culvertsoft.mnet.NodeDisconnect");
	return out;
}

const std::vector<long long>& NodeDisconnect::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 513154294965126267LL << 6206250929262320441LL;
	return out;
}

const std::vector<short>& NodeDisconnect::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -28540 << 8213;
	return out;
}

const std::vector<std::string>& NodeDisconnect::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.Message" << "se.culvertsoft.mnet.NodeDisconnect";
	return out;
}

const std::vector<std::string>& NodeDisconnect::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "kIQ" << "IBU";
	return out;
}

const std::string& NodeDisconnect::_type_ids_16bit_base64_string() {
	static const std::string out("kIQIBU");
	return out;
}

const std::string& NodeDisconnect::_type_id_16bit_base64() {
	static const std::string out("IBU");
	return out;
}

const std::vector<mgen::Field>& NodeDisconnect::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_senderId_metadata() << _field_targetId_metadata() << _field_hops_metadata() << _field_maxHops_metadata() << _field_filter_metadata() << _field_disconnectedNodeId_metadata() << _field_reason_metadata();
	return out;
}

const mgen::Field& NodeDisconnect::_field_disconnectedNodeId_metadata() {
	static const mgen::Field out(-19498, "disconnectedNodeId");
	return out;
}

const mgen::Field& NodeDisconnect::_field_reason_metadata() {
	static const mgen::Field out(-15867, "reason");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

