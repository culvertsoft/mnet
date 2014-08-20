/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/NodeSettings.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

NodeSettings::NodeSettings() : 
		m_name("unnamed_node"),
		m_tags(std::vector<std::string>()),
		m_announceInterval(0.5),
		m_maxHopsDefault(3),
		m_maxHopsLimit(4),
		_m_name_isSet(true),
		_m_tags_isSet(true),
		_m_announceInterval_isSet(true),
		_m_maxHopsDefault_isSet(true),
		_m_maxHopsLimit_isSet(true) {
}

NodeSettings::NodeSettings(const std::string& name, 
			const std::vector<std::string> & tags, 
			const double& announceInterval, 
			const int& maxHopsDefault, 
			const int& maxHopsLimit) : 
		m_name(name),
		m_tags(tags),
		m_announceInterval(announceInterval),
		m_maxHopsDefault(maxHopsDefault),
		m_maxHopsLimit(maxHopsLimit),
		_m_name_isSet(true),
		_m_tags_isSet(true),
		_m_announceInterval_isSet(true),
		_m_maxHopsDefault_isSet(true),
		_m_maxHopsLimit_isSet(true) {
}

NodeSettings::~NodeSettings() {
}

const std::string& NodeSettings::getName() const {
	return m_name;
}

const std::vector<std::string> & NodeSettings::getTags() const {
	return m_tags;
}

const double& NodeSettings::getAnnounceInterval() const {
	return m_announceInterval;
}

const int& NodeSettings::getMaxHopsDefault() const {
	return m_maxHopsDefault;
}

const int& NodeSettings::getMaxHopsLimit() const {
	return m_maxHopsLimit;
}

std::string& NodeSettings::getNameMutable() {
	_m_name_isSet = true;
	return m_name;
}

std::vector<std::string> & NodeSettings::getTagsMutable() {
	_m_tags_isSet = true;
	return m_tags;
}

double& NodeSettings::getAnnounceIntervalMutable() {
	_m_announceInterval_isSet = true;
	return m_announceInterval;
}

int& NodeSettings::getMaxHopsDefaultMutable() {
	_m_maxHopsDefault_isSet = true;
	return m_maxHopsDefault;
}

int& NodeSettings::getMaxHopsLimitMutable() {
	_m_maxHopsLimit_isSet = true;
	return m_maxHopsLimit;
}

NodeSettings& NodeSettings::setName(const std::string& name) {
	m_name = name;
	_m_name_isSet = true;
	return *this;
}

NodeSettings& NodeSettings::setTags(const std::vector<std::string> & tags) {
	m_tags = tags;
	_m_tags_isSet = true;
	return *this;
}

NodeSettings& NodeSettings::setAnnounceInterval(const double& announceInterval) {
	m_announceInterval = announceInterval;
	_m_announceInterval_isSet = true;
	return *this;
}

NodeSettings& NodeSettings::setMaxHopsDefault(const int& maxHopsDefault) {
	m_maxHopsDefault = maxHopsDefault;
	_m_maxHopsDefault_isSet = true;
	return *this;
}

NodeSettings& NodeSettings::setMaxHopsLimit(const int& maxHopsLimit) {
	m_maxHopsLimit = maxHopsLimit;
	_m_maxHopsLimit_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool NodeSettings::hasName() const {
	return _isNameSet(mgen::SHALLOW);
}

bool NodeSettings::hasTags() const {
	return _isTagsSet(mgen::SHALLOW);
}

bool NodeSettings::hasAnnounceInterval() const {
	return _isAnnounceIntervalSet(mgen::SHALLOW);
}

bool NodeSettings::hasMaxHopsDefault() const {
	return _isMaxHopsDefaultSet(mgen::SHALLOW);
}

bool NodeSettings::hasMaxHopsLimit() const {
	return _isMaxHopsLimitSet(mgen::SHALLOW);
}

NodeSettings& NodeSettings::unsetName() {
	_setNameSet(false, mgen::SHALLOW);
	return *this;
}

NodeSettings& NodeSettings::unsetTags() {
	_setTagsSet(false, mgen::SHALLOW);
	return *this;
}

NodeSettings& NodeSettings::unsetAnnounceInterval() {
	_setAnnounceIntervalSet(false, mgen::SHALLOW);
	return *this;
}

NodeSettings& NodeSettings::unsetMaxHopsDefault() {
	_setMaxHopsDefaultSet(false, mgen::SHALLOW);
	return *this;
}

NodeSettings& NodeSettings::unsetMaxHopsLimit() {
	_setMaxHopsLimitSet(false, mgen::SHALLOW);
	return *this;
}

bool NodeSettings::operator==(const NodeSettings& other) const {
	return true
		 && _isNameSet(mgen::SHALLOW) == other._isNameSet(mgen::SHALLOW)
		 && _isTagsSet(mgen::SHALLOW) == other._isTagsSet(mgen::SHALLOW)
		 && _isAnnounceIntervalSet(mgen::SHALLOW) == other._isAnnounceIntervalSet(mgen::SHALLOW)
		 && _isMaxHopsDefaultSet(mgen::SHALLOW) == other._isMaxHopsDefaultSet(mgen::SHALLOW)
		 && _isMaxHopsLimitSet(mgen::SHALLOW) == other._isMaxHopsLimitSet(mgen::SHALLOW)
		 && getName() == other.getName()
		 && getTags() == other.getTags()
		 && getAnnounceInterval() == other.getAnnounceInterval()
		 && getMaxHopsDefault() == other.getMaxHopsDefault()
		 && getMaxHopsLimit() == other.getMaxHopsLimit();
}

bool NodeSettings::operator!=(const NodeSettings& other) const {
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
		  
const mgen::Field * NodeSettings::_fieldById(const short id) const {
	switch (id) {
	case _field_name_id:
		return &_field_name_metadata();
	case _field_tags_id:
		return &_field_tags_metadata();
	case _field_announceInterval_id:
		return &_field_announceInterval_metadata();
	case _field_maxHopsDefault_id:
		return &_field_maxHopsDefault_metadata();
	case _field_maxHopsLimit_id:
		return &_field_maxHopsLimit_metadata();
	default:
		return 0;
	}
}

const mgen::Field * NodeSettings::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("name", &NodeSettings::_field_name_metadata())("tags", &NodeSettings::_field_tags_metadata())("announceInterval", &NodeSettings::_field_announceInterval_metadata())("maxHopsDefault", &NodeSettings::_field_maxHopsDefault_metadata())("maxHopsLimit", &NodeSettings::_field_maxHopsLimit_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long NodeSettings::_typeId() const {
	return _type_id;
}

const std::string& NodeSettings::_typeName() const {
	return _type_name();
}

const short NodeSettings::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& NodeSettings::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& NodeSettings::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& NodeSettings::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& NodeSettings::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& NodeSettings::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& NodeSettings::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& NodeSettings::_fieldMetadatas() const {
	return _field_metadatas();
}

NodeSettings& NodeSettings::_setNameSet(const bool state, const mgen::FieldSetDepth depth) {
	if (state && !_isNameSet(mgen::SHALLOW))
		m_name = "unnamed_node";
	if (!state)
		m_name = "";
	_m_name_isSet = state;
	return *this;
}

NodeSettings& NodeSettings::_setTagsSet(const bool state, const mgen::FieldSetDepth depth) {
	if (state && !_isTagsSet(mgen::SHALLOW))
		m_tags = std::vector<std::string>();
	if (!state)
		m_tags.clear();
	else if (depth == mgen::DEEP)
		mgen::validation::setFieldSetDeep(m_tags);
	_m_tags_isSet = state;
	return *this;
}

NodeSettings& NodeSettings::_setAnnounceIntervalSet(const bool state, const mgen::FieldSetDepth depth) {
	if (state && !_isAnnounceIntervalSet(mgen::SHALLOW))
		m_announceInterval = 0.5;
	if (!state)
		m_announceInterval = 0.0;
	_m_announceInterval_isSet = state;
	return *this;
}

NodeSettings& NodeSettings::_setMaxHopsDefaultSet(const bool state, const mgen::FieldSetDepth depth) {
	if (state && !_isMaxHopsDefaultSet(mgen::SHALLOW))
		m_maxHopsDefault = 3;
	if (!state)
		m_maxHopsDefault = 0;
	_m_maxHopsDefault_isSet = state;
	return *this;
}

NodeSettings& NodeSettings::_setMaxHopsLimitSet(const bool state, const mgen::FieldSetDepth depth) {
	if (state && !_isMaxHopsLimitSet(mgen::SHALLOW))
		m_maxHopsLimit = 4;
	if (!state)
		m_maxHopsLimit = 0;
	_m_maxHopsLimit_isSet = state;
	return *this;
}

NodeSettings& NodeSettings::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setNameSet(state, depth);
	_setTagsSet(state, depth);
	_setAnnounceIntervalSet(state, depth);
	_setMaxHopsDefaultSet(state, depth);
	_setMaxHopsLimitSet(state, depth);
	return *this;
}

int NodeSettings::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isNameSet(depth) ? 1 : 0;
	out += _isTagsSet(depth) ? 1 : 0;
	out += _isAnnounceIntervalSet(depth) ? 1 : 0;
	out += _isMaxHopsDefaultSet(depth) ? 1 : 0;
	out += _isMaxHopsLimitSet(depth) ? 1 : 0;
	return out;
}

bool NodeSettings::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
	switch(field.id()) {
		case (_field_name_id):
			return _isNameSet(depth);
		case (_field_tags_id):
			return _isTagsSet(depth);
		case (_field_announceInterval_id):
			return _isAnnounceIntervalSet(depth);
		case (_field_maxHopsDefault_id):
			return _isMaxHopsDefaultSet(depth);
		case (_field_maxHopsLimit_id):
			return _isMaxHopsLimitSet(depth);
		default:
			return false;
	}
}

bool NodeSettings::_isNameSet(const mgen::FieldSetDepth depth) const {
	return _m_name_isSet;
}

bool NodeSettings::_isTagsSet(const mgen::FieldSetDepth depth) const {
	return _m_tags_isSet;
}

bool NodeSettings::_isAnnounceIntervalSet(const mgen::FieldSetDepth depth) const {
	return _m_announceInterval_isSet;
}

bool NodeSettings::_isMaxHopsDefaultSet(const mgen::FieldSetDepth depth) const {
	return _m_maxHopsDefault_isSet;
}

bool NodeSettings::_isMaxHopsLimitSet(const mgen::FieldSetDepth depth) const {
	return _m_maxHopsLimit_isSet;
}

bool NodeSettings::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true;
	}
}

bool NodeSettings::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const NodeSettings&>(other) == *this;
}

NodeSettings * NodeSettings::_deepCopy() const {
	return new NodeSettings(*this);
}

mgen::MGenBase * NodeSettings::_newInstance() {
	return new NodeSettings;
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
		  
const std::string& NodeSettings::_type_name() {
	static const std::string out("se.culvertsoft.mnet.NodeSettings");
	return out;
}

const std::vector<long long>& NodeSettings::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 8357426928295150751LL;
	return out;
}

const std::vector<short>& NodeSettings::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << 9024;
	return out;
}

const std::vector<std::string>& NodeSettings::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.NodeSettings";
	return out;
}

const std::vector<std::string>& NodeSettings::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "I0A";
	return out;
}

const std::string& NodeSettings::_type_ids_16bit_base64_string() {
	static const std::string out("I0A");
	return out;
}

const std::string& NodeSettings::_type_id_16bit_base64() {
	static const std::string out("I0A");
	return out;
}

const std::vector<mgen::Field>& NodeSettings::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_name_metadata() << _field_tags_metadata() << _field_announceInterval_metadata() << _field_maxHopsDefault_metadata() << _field_maxHopsLimit_metadata();
	return out;
}

const mgen::Field& NodeSettings::_field_name_metadata() {
	static const mgen::Field out(-28058, "name");
	return out;
}

const mgen::Field& NodeSettings::_field_tags_metadata() {
	static const mgen::Field out(31830, "tags");
	return out;
}

const mgen::Field& NodeSettings::_field_announceInterval_metadata() {
	static const mgen::Field out(-5317, "announceInterval");
	return out;
}

const mgen::Field& NodeSettings::_field_maxHopsDefault_metadata() {
	static const mgen::Field out(20361, "maxHopsDefault");
	return out;
}

const mgen::Field& NodeSettings::_field_maxHopsLimit_metadata() {
	static const mgen::Field out(-13824, "maxHopsLimit");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

