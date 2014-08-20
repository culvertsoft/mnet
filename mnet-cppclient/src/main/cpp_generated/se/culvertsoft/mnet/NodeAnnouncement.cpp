/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/NodeAnnouncement.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

NodeAnnouncement::NodeAnnouncement() : 
		_m_name_isSet(false),
		_m_tags_isSet(false) {
}

NodeAnnouncement::NodeAnnouncement(const NodeUUID& senderId, 
			const NodeUUID& targetId, 
			const char& hops, 
			const char& maxHops, 
			const Polymorphic<MessageFilter> & filter, 
			const std::string& name, 
			const std::vector<std::string> & tags) : 
		Message(senderId, targetId, hops, maxHops, filter),
		m_name(name),
		m_tags(tags),
		_m_name_isSet(true),
		_m_tags_isSet(true) {
}

NodeAnnouncement::~NodeAnnouncement() {
}

const std::string& NodeAnnouncement::getName() const {
	return m_name;
}

const std::vector<std::string> & NodeAnnouncement::getTags() const {
	return m_tags;
}

std::string& NodeAnnouncement::getNameMutable() {
	_m_name_isSet = true;
	return m_name;
}

std::vector<std::string> & NodeAnnouncement::getTagsMutable() {
	_m_tags_isSet = true;
	return m_tags;
}

NodeAnnouncement& NodeAnnouncement::setSenderId(const NodeUUID& senderId) {
	Message::setSenderId(senderId);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setTargetId(const NodeUUID& targetId) {
	Message::setTargetId(targetId);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setHops(const char& hops) {
	Message::setHops(hops);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setMaxHops(const char& maxHops) {
	Message::setMaxHops(maxHops);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setFilter(const Polymorphic<MessageFilter> & filter) {
	Message::setFilter(filter);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setFilter(const MessageFilter & filter) {
	Message::setFilter(filter);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setFilter(MessageFilter * filter, const bool managePtr) {
	Message::setFilter(filter);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setName(const std::string& name) {
	m_name = name;
	_m_name_isSet = true;
	return *this;
}

NodeAnnouncement& NodeAnnouncement::setTags(const std::vector<std::string> & tags) {
	m_tags = tags;
	_m_tags_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool NodeAnnouncement::hasName() const {
	return _isNameSet(mgen::SHALLOW);
}

bool NodeAnnouncement::hasTags() const {
	return _isTagsSet(mgen::SHALLOW);
}

NodeAnnouncement& NodeAnnouncement::unsetSenderId() {
	_setSenderIdSet(false, mgen::SHALLOW);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::unsetTargetId() {
	_setTargetIdSet(false, mgen::SHALLOW);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::unsetHops() {
	_setHopsSet(false, mgen::SHALLOW);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::unsetMaxHops() {
	_setMaxHopsSet(false, mgen::SHALLOW);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::unsetFilter() {
	_setFilterSet(false, mgen::SHALLOW);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::unsetName() {
	_setNameSet(false, mgen::SHALLOW);
	return *this;
}

NodeAnnouncement& NodeAnnouncement::unsetTags() {
	_setTagsSet(false, mgen::SHALLOW);
	return *this;
}

bool NodeAnnouncement::operator==(const NodeAnnouncement& other) const {
	return true
		 && _isSenderIdSet(mgen::SHALLOW) == other._isSenderIdSet(mgen::SHALLOW)
		 && _isTargetIdSet(mgen::SHALLOW) == other._isTargetIdSet(mgen::SHALLOW)
		 && _isHopsSet(mgen::SHALLOW) == other._isHopsSet(mgen::SHALLOW)
		 && _isMaxHopsSet(mgen::SHALLOW) == other._isMaxHopsSet(mgen::SHALLOW)
		 && _isFilterSet(mgen::SHALLOW) == other._isFilterSet(mgen::SHALLOW)
		 && _isNameSet(mgen::SHALLOW) == other._isNameSet(mgen::SHALLOW)
		 && _isTagsSet(mgen::SHALLOW) == other._isTagsSet(mgen::SHALLOW)
		 && getSenderId() == other.getSenderId()
		 && getTargetId() == other.getTargetId()
		 && getHops() == other.getHops()
		 && getMaxHops() == other.getMaxHops()
		 && getFilter() == other.getFilter()
		 && getName() == other.getName()
		 && getTags() == other.getTags();
}

bool NodeAnnouncement::operator!=(const NodeAnnouncement& other) const {
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
		  
const mgen::Field * NodeAnnouncement::_fieldById(const short id) const {
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
	case _field_name_id:
		return &_field_name_metadata();
	case _field_tags_id:
		return &_field_tags_metadata();
	default:
		return 0;
	}
}

const mgen::Field * NodeAnnouncement::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("senderId", &NodeAnnouncement::_field_senderId_metadata())("targetId", &NodeAnnouncement::_field_targetId_metadata())("hops", &NodeAnnouncement::_field_hops_metadata())("maxHops", &NodeAnnouncement::_field_maxHops_metadata())("filter", &NodeAnnouncement::_field_filter_metadata())("name", &NodeAnnouncement::_field_name_metadata())("tags", &NodeAnnouncement::_field_tags_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long NodeAnnouncement::_typeId() const {
	return _type_id;
}

const std::string& NodeAnnouncement::_typeName() const {
	return _type_name();
}

const short NodeAnnouncement::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& NodeAnnouncement::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& NodeAnnouncement::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& NodeAnnouncement::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& NodeAnnouncement::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& NodeAnnouncement::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& NodeAnnouncement::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& NodeAnnouncement::_fieldMetadatas() const {
	return _field_metadatas();
}

NodeAnnouncement& NodeAnnouncement::_setNameSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_name = "";
	_m_name_isSet = state;
	return *this;
}

NodeAnnouncement& NodeAnnouncement::_setTagsSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_tags.clear();
	else if (depth == mgen::DEEP)
		mgen::validation::setFieldSetDeep(m_tags);
	_m_tags_isSet = state;
	return *this;
}

NodeAnnouncement& NodeAnnouncement::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setSenderIdSet(state, depth);
	_setTargetIdSet(state, depth);
	_setHopsSet(state, depth);
	_setMaxHopsSet(state, depth);
	_setFilterSet(state, depth);
	_setNameSet(state, depth);
	_setTagsSet(state, depth);
	return *this;
}

int NodeAnnouncement::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isSenderIdSet(depth) ? 1 : 0;
	out += _isTargetIdSet(depth) ? 1 : 0;
	out += _isHopsSet(depth) ? 1 : 0;
	out += _isMaxHopsSet(depth) ? 1 : 0;
	out += _isFilterSet(depth) ? 1 : 0;
	out += _isNameSet(depth) ? 1 : 0;
	out += _isTagsSet(depth) ? 1 : 0;
	return out;
}

bool NodeAnnouncement::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
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
		case (_field_name_id):
			return _isNameSet(depth);
		case (_field_tags_id):
			return _isTagsSet(depth);
		default:
			return false;
	}
}

bool NodeAnnouncement::_isNameSet(const mgen::FieldSetDepth depth) const {
	return _m_name_isSet;
}

bool NodeAnnouncement::_isTagsSet(const mgen::FieldSetDepth depth) const {
	return _m_tags_isSet;
}

bool NodeAnnouncement::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true
				&& (!_isSenderIdSet(mgen::SHALLOW) || _isSenderIdSet(mgen::DEEP))
				&& (!_isTargetIdSet(mgen::SHALLOW) || _isTargetIdSet(mgen::DEEP))
				&& (!_isFilterSet(mgen::SHALLOW) || _isFilterSet(mgen::DEEP));
	}
}

bool NodeAnnouncement::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const NodeAnnouncement&>(other) == *this;
}

NodeAnnouncement * NodeAnnouncement::_deepCopy() const {
	return new NodeAnnouncement(*this);
}

mgen::MGenBase * NodeAnnouncement::_newInstance() {
	return new NodeAnnouncement;
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
		  
const std::string& NodeAnnouncement::_type_name() {
	static const std::string out("se.culvertsoft.mnet.NodeAnnouncement");
	return out;
}

const std::vector<long long>& NodeAnnouncement::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 513154294965126267LL << 6374302276601972660LL;
	return out;
}

const std::vector<short>& NodeAnnouncement::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -28540 << -6041;
	return out;
}

const std::vector<std::string>& NodeAnnouncement::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.Message" << "se.culvertsoft.mnet.NodeAnnouncement";
	return out;
}

const std::vector<std::string>& NodeAnnouncement::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "kIQ" << "6Gc";
	return out;
}

const std::string& NodeAnnouncement::_type_ids_16bit_base64_string() {
	static const std::string out("kIQ6Gc");
	return out;
}

const std::string& NodeAnnouncement::_type_id_16bit_base64() {
	static const std::string out("6Gc");
	return out;
}

const std::vector<mgen::Field>& NodeAnnouncement::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_senderId_metadata() << _field_targetId_metadata() << _field_hops_metadata() << _field_maxHops_metadata() << _field_filter_metadata() << _field_name_metadata() << _field_tags_metadata();
	return out;
}

const mgen::Field& NodeAnnouncement::_field_name_metadata() {
	static const mgen::Field out(-28058, "name");
	return out;
}

const mgen::Field& NodeAnnouncement::_field_tags_metadata() {
	static const mgen::Field out(31830, "tags");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

