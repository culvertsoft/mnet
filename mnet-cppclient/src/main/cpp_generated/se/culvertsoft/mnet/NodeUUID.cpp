/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/NodeUUID.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

NodeUUID::NodeUUID() : 
		m_lsb(0LL),
		m_msb(0LL),
		_m_lsb_isSet(false),
		_m_msb_isSet(false) {
}

NodeUUID::NodeUUID(const long long& lsb, 
			const long long& msb) : 
		m_lsb(lsb),
		m_msb(msb),
		_m_lsb_isSet(true),
		_m_msb_isSet(true) {
}

NodeUUID::~NodeUUID() {
}

const long long& NodeUUID::getLsb() const {
	return m_lsb;
}

const long long& NodeUUID::getMsb() const {
	return m_msb;
}

long long& NodeUUID::getLsbMutable() {
	_m_lsb_isSet = true;
	return m_lsb;
}

long long& NodeUUID::getMsbMutable() {
	_m_msb_isSet = true;
	return m_msb;
}

NodeUUID& NodeUUID::setLsb(const long long& lsb) {
	m_lsb = lsb;
	_m_lsb_isSet = true;
	return *this;
}

NodeUUID& NodeUUID::setMsb(const long long& msb) {
	m_msb = msb;
	_m_msb_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool NodeUUID::hasLsb() const {
	return _isLsbSet(mgen::SHALLOW);
}

bool NodeUUID::hasMsb() const {
	return _isMsbSet(mgen::SHALLOW);
}

NodeUUID& NodeUUID::unsetLsb() {
	_setLsbSet(false, mgen::SHALLOW);
	return *this;
}

NodeUUID& NodeUUID::unsetMsb() {
	_setMsbSet(false, mgen::SHALLOW);
	return *this;
}

bool NodeUUID::operator==(const NodeUUID& other) const {
	return true
		 && _isLsbSet(mgen::SHALLOW) == other._isLsbSet(mgen::SHALLOW)
		 && _isMsbSet(mgen::SHALLOW) == other._isMsbSet(mgen::SHALLOW)
		 && getLsb() == other.getLsb()
		 && getMsb() == other.getMsb();
}

bool NodeUUID::operator!=(const NodeUUID& other) const {
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
		  
const mgen::Field * NodeUUID::_fieldById(const short id) const {
	switch (id) {
	case _field_lsb_id:
		return &_field_lsb_metadata();
	case _field_msb_id:
		return &_field_msb_metadata();
	default:
		return 0;
	}
}

const mgen::Field * NodeUUID::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("lsb", &NodeUUID::_field_lsb_metadata())("msb", &NodeUUID::_field_msb_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long NodeUUID::_typeId() const {
	return _type_id;
}

const std::string& NodeUUID::_typeName() const {
	return _type_name();
}

const short NodeUUID::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& NodeUUID::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& NodeUUID::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& NodeUUID::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& NodeUUID::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& NodeUUID::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& NodeUUID::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& NodeUUID::_fieldMetadatas() const {
	return _field_metadatas();
}

NodeUUID& NodeUUID::_setLsbSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_lsb = 0LL;
	_m_lsb_isSet = state;
	return *this;
}

NodeUUID& NodeUUID::_setMsbSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_msb = 0LL;
	_m_msb_isSet = state;
	return *this;
}

NodeUUID& NodeUUID::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setLsbSet(state, depth);
	_setMsbSet(state, depth);
	return *this;
}

int NodeUUID::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isLsbSet(depth) ? 1 : 0;
	out += _isMsbSet(depth) ? 1 : 0;
	return out;
}

bool NodeUUID::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
	switch(field.id()) {
		case (_field_lsb_id):
			return _isLsbSet(depth);
		case (_field_msb_id):
			return _isMsbSet(depth);
		default:
			return false;
	}
}

bool NodeUUID::_isLsbSet(const mgen::FieldSetDepth depth) const {
	return _m_lsb_isSet;
}

bool NodeUUID::_isMsbSet(const mgen::FieldSetDepth depth) const {
	return _m_msb_isSet;
}

bool NodeUUID::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true;
	}
}

bool NodeUUID::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const NodeUUID&>(other) == *this;
}

NodeUUID * NodeUUID::_deepCopy() const {
	return new NodeUUID(*this);
}

mgen::MGenBase * NodeUUID::_newInstance() {
	return new NodeUUID;
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
		  
const std::string& NodeUUID::_type_name() {
	static const std::string out("se.culvertsoft.mnet.NodeUUID");
	return out;
}

const std::vector<long long>& NodeUUID::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 4507004109412558583LL;
	return out;
}

const std::vector<short>& NodeUUID::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << 8590;
	return out;
}

const std::vector<std::string>& NodeUUID::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.NodeUUID";
	return out;
}

const std::vector<std::string>& NodeUUID::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "IY4";
	return out;
}

const std::string& NodeUUID::_type_ids_16bit_base64_string() {
	static const std::string out("IY4");
	return out;
}

const std::string& NodeUUID::_type_id_16bit_base64() {
	static const std::string out("IY4");
	return out;
}

const std::vector<mgen::Field>& NodeUUID::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_lsb_metadata() << _field_msb_metadata();
	return out;
}

const mgen::Field& NodeUUID::_field_lsb_metadata() {
	static const mgen::Field out(13176, "lsb");
	return out;
}

const mgen::Field& NodeUUID::_field_msb_metadata() {
	static const mgen::Field out(1096, "msb");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

