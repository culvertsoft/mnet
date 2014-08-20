/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/IdCreateReply.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

IdCreateReply::IdCreateReply() : 
		_m_createdId_isSet(false) {
}

IdCreateReply::IdCreateReply(const NodeUUID& senderId, 
			const NodeUUID& targetId, 
			const char& hops, 
			const char& maxHops, 
			const Polymorphic<MessageFilter> & filter, 
			const NodeUUID& createdId) : 
		Message(senderId, targetId, hops, maxHops, filter),
		m_createdId(createdId),
		_m_createdId_isSet(true) {
}

IdCreateReply::~IdCreateReply() {
}

const NodeUUID& IdCreateReply::getCreatedId() const {
	return m_createdId;
}

NodeUUID& IdCreateReply::getCreatedIdMutable() {
	_m_createdId_isSet = true;
	return m_createdId;
}

IdCreateReply& IdCreateReply::setSenderId(const NodeUUID& senderId) {
	Message::setSenderId(senderId);
	return *this;
}

IdCreateReply& IdCreateReply::setTargetId(const NodeUUID& targetId) {
	Message::setTargetId(targetId);
	return *this;
}

IdCreateReply& IdCreateReply::setHops(const char& hops) {
	Message::setHops(hops);
	return *this;
}

IdCreateReply& IdCreateReply::setMaxHops(const char& maxHops) {
	Message::setMaxHops(maxHops);
	return *this;
}

IdCreateReply& IdCreateReply::setFilter(const Polymorphic<MessageFilter> & filter) {
	Message::setFilter(filter);
	return *this;
}

IdCreateReply& IdCreateReply::setFilter(const MessageFilter & filter) {
	Message::setFilter(filter);
	return *this;
}

IdCreateReply& IdCreateReply::setFilter(MessageFilter * filter, const bool managePtr) {
	Message::setFilter(filter);
	return *this;
}

IdCreateReply& IdCreateReply::setCreatedId(const NodeUUID& createdId) {
	m_createdId = createdId;
	_m_createdId_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool IdCreateReply::hasCreatedId() const {
	return _isCreatedIdSet(mgen::SHALLOW);
}

IdCreateReply& IdCreateReply::unsetSenderId() {
	_setSenderIdSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateReply& IdCreateReply::unsetTargetId() {
	_setTargetIdSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateReply& IdCreateReply::unsetHops() {
	_setHopsSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateReply& IdCreateReply::unsetMaxHops() {
	_setMaxHopsSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateReply& IdCreateReply::unsetFilter() {
	_setFilterSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateReply& IdCreateReply::unsetCreatedId() {
	_setCreatedIdSet(false, mgen::SHALLOW);
	return *this;
}

bool IdCreateReply::operator==(const IdCreateReply& other) const {
	return true
		 && _isSenderIdSet(mgen::SHALLOW) == other._isSenderIdSet(mgen::SHALLOW)
		 && _isTargetIdSet(mgen::SHALLOW) == other._isTargetIdSet(mgen::SHALLOW)
		 && _isHopsSet(mgen::SHALLOW) == other._isHopsSet(mgen::SHALLOW)
		 && _isMaxHopsSet(mgen::SHALLOW) == other._isMaxHopsSet(mgen::SHALLOW)
		 && _isFilterSet(mgen::SHALLOW) == other._isFilterSet(mgen::SHALLOW)
		 && _isCreatedIdSet(mgen::SHALLOW) == other._isCreatedIdSet(mgen::SHALLOW)
		 && getSenderId() == other.getSenderId()
		 && getTargetId() == other.getTargetId()
		 && getHops() == other.getHops()
		 && getMaxHops() == other.getMaxHops()
		 && getFilter() == other.getFilter()
		 && getCreatedId() == other.getCreatedId();
}

bool IdCreateReply::operator!=(const IdCreateReply& other) const {
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
		  
const mgen::Field * IdCreateReply::_fieldById(const short id) const {
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
	case _field_createdId_id:
		return &_field_createdId_metadata();
	default:
		return 0;
	}
}

const mgen::Field * IdCreateReply::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("senderId", &IdCreateReply::_field_senderId_metadata())("targetId", &IdCreateReply::_field_targetId_metadata())("hops", &IdCreateReply::_field_hops_metadata())("maxHops", &IdCreateReply::_field_maxHops_metadata())("filter", &IdCreateReply::_field_filter_metadata())("createdId", &IdCreateReply::_field_createdId_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long IdCreateReply::_typeId() const {
	return _type_id;
}

const std::string& IdCreateReply::_typeName() const {
	return _type_name();
}

const short IdCreateReply::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& IdCreateReply::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& IdCreateReply::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& IdCreateReply::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& IdCreateReply::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& IdCreateReply::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& IdCreateReply::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& IdCreateReply::_fieldMetadatas() const {
	return _field_metadatas();
}

IdCreateReply& IdCreateReply::_setCreatedIdSet(const bool state, const mgen::FieldSetDepth depth) {
	if (depth == mgen::DEEP)
		m_createdId._setAllFieldsSet(state, mgen::DEEP);
	_m_createdId_isSet = state;
	return *this;
}

IdCreateReply& IdCreateReply::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setSenderIdSet(state, depth);
	_setTargetIdSet(state, depth);
	_setHopsSet(state, depth);
	_setMaxHopsSet(state, depth);
	_setFilterSet(state, depth);
	_setCreatedIdSet(state, depth);
	return *this;
}

int IdCreateReply::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isSenderIdSet(depth) ? 1 : 0;
	out += _isTargetIdSet(depth) ? 1 : 0;
	out += _isHopsSet(depth) ? 1 : 0;
	out += _isMaxHopsSet(depth) ? 1 : 0;
	out += _isFilterSet(depth) ? 1 : 0;
	out += _isCreatedIdSet(depth) ? 1 : 0;
	return out;
}

bool IdCreateReply::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
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
		case (_field_createdId_id):
			return _isCreatedIdSet(depth);
		default:
			return false;
	}
}

bool IdCreateReply::_isCreatedIdSet(const mgen::FieldSetDepth depth) const {
	if (depth == mgen::SHALLOW) {
		return _m_createdId_isSet;
	} else {
		return _m_createdId_isSet && mgen::validation::validateFieldDeep(getCreatedId());
	}
}

bool IdCreateReply::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true
				&& (!_isSenderIdSet(mgen::SHALLOW) || _isSenderIdSet(mgen::DEEP))
				&& (!_isTargetIdSet(mgen::SHALLOW) || _isTargetIdSet(mgen::DEEP))
				&& (!_isFilterSet(mgen::SHALLOW) || _isFilterSet(mgen::DEEP))
				&& (!_isCreatedIdSet(mgen::SHALLOW) || _isCreatedIdSet(mgen::DEEP));
	}
}

bool IdCreateReply::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const IdCreateReply&>(other) == *this;
}

IdCreateReply * IdCreateReply::_deepCopy() const {
	return new IdCreateReply(*this);
}

mgen::MGenBase * IdCreateReply::_newInstance() {
	return new IdCreateReply;
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
		  
const std::string& IdCreateReply::_type_name() {
	static const std::string out("se.culvertsoft.mnet.IdCreateReply");
	return out;
}

const std::vector<long long>& IdCreateReply::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 513154294965126267LL << 378799129893336095LL;
	return out;
}

const std::vector<short>& IdCreateReply::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -28540 << -20136;
	return out;
}

const std::vector<std::string>& IdCreateReply::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.Message" << "se.culvertsoft.mnet.IdCreateReply";
	return out;
}

const std::vector<std::string>& IdCreateReply::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "kIQ" << "sVg";
	return out;
}

const std::string& IdCreateReply::_type_ids_16bit_base64_string() {
	static const std::string out("kIQsVg");
	return out;
}

const std::string& IdCreateReply::_type_id_16bit_base64() {
	static const std::string out("sVg");
	return out;
}

const std::vector<mgen::Field>& IdCreateReply::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_senderId_metadata() << _field_targetId_metadata() << _field_hops_metadata() << _field_maxHops_metadata() << _field_filter_metadata() << _field_createdId_metadata();
	return out;
}

const mgen::Field& IdCreateReply::_field_createdId_metadata() {
	static const mgen::Field out(-28810, "createdId");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

