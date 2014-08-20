/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/IdCreateRequest.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

IdCreateRequest::IdCreateRequest() {
}

IdCreateRequest::IdCreateRequest(const NodeUUID& senderId, 
			const NodeUUID& targetId, 
			const char& hops, 
			const char& maxHops, 
			const Polymorphic<MessageFilter> & filter) : 
		Message(senderId, targetId, hops, maxHops, filter) {
}

IdCreateRequest::~IdCreateRequest() {
}

IdCreateRequest& IdCreateRequest::setSenderId(const NodeUUID& senderId) {
	Message::setSenderId(senderId);
	return *this;
}

IdCreateRequest& IdCreateRequest::setTargetId(const NodeUUID& targetId) {
	Message::setTargetId(targetId);
	return *this;
}

IdCreateRequest& IdCreateRequest::setHops(const char& hops) {
	Message::setHops(hops);
	return *this;
}

IdCreateRequest& IdCreateRequest::setMaxHops(const char& maxHops) {
	Message::setMaxHops(maxHops);
	return *this;
}

IdCreateRequest& IdCreateRequest::setFilter(const Polymorphic<MessageFilter> & filter) {
	Message::setFilter(filter);
	return *this;
}

IdCreateRequest& IdCreateRequest::setFilter(const MessageFilter & filter) {
	Message::setFilter(filter);
	return *this;
}

IdCreateRequest& IdCreateRequest::setFilter(MessageFilter * filter, const bool managePtr) {
	Message::setFilter(filter);
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

IdCreateRequest& IdCreateRequest::unsetSenderId() {
	_setSenderIdSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateRequest& IdCreateRequest::unsetTargetId() {
	_setTargetIdSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateRequest& IdCreateRequest::unsetHops() {
	_setHopsSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateRequest& IdCreateRequest::unsetMaxHops() {
	_setMaxHopsSet(false, mgen::SHALLOW);
	return *this;
}

IdCreateRequest& IdCreateRequest::unsetFilter() {
	_setFilterSet(false, mgen::SHALLOW);
	return *this;
}

bool IdCreateRequest::operator==(const IdCreateRequest& other) const {
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

bool IdCreateRequest::operator!=(const IdCreateRequest& other) const {
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
		  
const mgen::Field * IdCreateRequest::_fieldById(const short id) const {
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

const mgen::Field * IdCreateRequest::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("senderId", &IdCreateRequest::_field_senderId_metadata())("targetId", &IdCreateRequest::_field_targetId_metadata())("hops", &IdCreateRequest::_field_hops_metadata())("maxHops", &IdCreateRequest::_field_maxHops_metadata())("filter", &IdCreateRequest::_field_filter_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long IdCreateRequest::_typeId() const {
	return _type_id;
}

const std::string& IdCreateRequest::_typeName() const {
	return _type_name();
}

const short IdCreateRequest::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& IdCreateRequest::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& IdCreateRequest::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& IdCreateRequest::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& IdCreateRequest::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& IdCreateRequest::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& IdCreateRequest::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& IdCreateRequest::_fieldMetadatas() const {
	return _field_metadatas();
}

IdCreateRequest& IdCreateRequest::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setSenderIdSet(state, depth);
	_setTargetIdSet(state, depth);
	_setHopsSet(state, depth);
	_setMaxHopsSet(state, depth);
	_setFilterSet(state, depth);
	return *this;
}

int IdCreateRequest::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isSenderIdSet(depth) ? 1 : 0;
	out += _isTargetIdSet(depth) ? 1 : 0;
	out += _isHopsSet(depth) ? 1 : 0;
	out += _isMaxHopsSet(depth) ? 1 : 0;
	out += _isFilterSet(depth) ? 1 : 0;
	return out;
}

bool IdCreateRequest::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
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

bool IdCreateRequest::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true
				&& (!_isSenderIdSet(mgen::SHALLOW) || _isSenderIdSet(mgen::DEEP))
				&& (!_isTargetIdSet(mgen::SHALLOW) || _isTargetIdSet(mgen::DEEP))
				&& (!_isFilterSet(mgen::SHALLOW) || _isFilterSet(mgen::DEEP));
	}
}

bool IdCreateRequest::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const IdCreateRequest&>(other) == *this;
}

IdCreateRequest * IdCreateRequest::_deepCopy() const {
	return new IdCreateRequest(*this);
}

mgen::MGenBase * IdCreateRequest::_newInstance() {
	return new IdCreateRequest;
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
		  
const std::string& IdCreateRequest::_type_name() {
	static const std::string out("se.culvertsoft.mnet.IdCreateRequest");
	return out;
}

const std::vector<long long>& IdCreateRequest::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 513154294965126267LL << 4713557690089238540LL;
	return out;
}

const std::vector<short>& IdCreateRequest::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -28540 << -7845;
	return out;
}

const std::vector<std::string>& IdCreateRequest::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.Message" << "se.culvertsoft.mnet.IdCreateRequest";
	return out;
}

const std::vector<std::string>& IdCreateRequest::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "kIQ" << "4Vs";
	return out;
}

const std::string& IdCreateRequest::_type_ids_16bit_base64_string() {
	static const std::string out("kIQ4Vs");
	return out;
}

const std::string& IdCreateRequest::_type_id_16bit_base64() {
	static const std::string out("4Vs");
	return out;
}

const std::vector<mgen::Field>& IdCreateRequest::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_senderId_metadata() << _field_targetId_metadata() << _field_hops_metadata() << _field_maxHops_metadata() << _field_filter_metadata();
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

