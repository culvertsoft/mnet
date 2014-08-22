/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/cppclient/ClientConfiguration.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {
namespace cppclient {

ClientConfiguration::ClientConfiguration() : 
		_m_url_isSet(false) {
}

ClientConfiguration::ClientConfiguration(const std::string& url) : 
		m_url(url),
		_m_url_isSet(true) {
}

ClientConfiguration::~ClientConfiguration() {
}

const std::string& ClientConfiguration::getUrl() const {
	return m_url;
}

std::string& ClientConfiguration::getUrlMutable() {
	_m_url_isSet = true;
	return m_url;
}

ClientConfiguration& ClientConfiguration::setUrl(const std::string& url) {
	m_url = url;
	_m_url_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool ClientConfiguration::hasUrl() const {
	return _isUrlSet(mgen::SHALLOW);
}

ClientConfiguration& ClientConfiguration::unsetUrl() {
	_setUrlSet(false, mgen::SHALLOW);
	return *this;
}

bool ClientConfiguration::operator==(const ClientConfiguration& other) const {
	return true
		 && _isUrlSet(mgen::SHALLOW) == other._isUrlSet(mgen::SHALLOW)
		 && getUrl() == other.getUrl();
}

bool ClientConfiguration::operator!=(const ClientConfiguration& other) const {
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
		  
const mgen::Field * ClientConfiguration::_fieldById(const short id) const {
	switch (id) {
	case _field_url_id:
		return &_field_url_metadata();
	default:
		return 0;
	}
}

const mgen::Field * ClientConfiguration::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("url", &ClientConfiguration::_field_url_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long ClientConfiguration::_typeId() const {
	return _type_id;
}

const std::string& ClientConfiguration::_typeName() const {
	return _type_name();
}

const short ClientConfiguration::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& ClientConfiguration::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& ClientConfiguration::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& ClientConfiguration::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& ClientConfiguration::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& ClientConfiguration::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& ClientConfiguration::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& ClientConfiguration::_fieldMetadatas() const {
	return _field_metadatas();
}

ClientConfiguration& ClientConfiguration::_setUrlSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_url = "";
	_m_url_isSet = state;
	return *this;
}

ClientConfiguration& ClientConfiguration::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setUrlSet(state, depth);
	return *this;
}

int ClientConfiguration::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isUrlSet(depth) ? 1 : 0;
	return out;
}

bool ClientConfiguration::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
	switch(field.id()) {
		case (_field_url_id):
			return _isUrlSet(depth);
		default:
			return false;
	}
}

bool ClientConfiguration::_isUrlSet(const mgen::FieldSetDepth depth) const {
	return _m_url_isSet;
}

bool ClientConfiguration::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true
				&& _isUrlSet(mgen::SHALLOW);
	} else {
		return true
				&& _isUrlSet(mgen::DEEP);
	}
}

bool ClientConfiguration::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const ClientConfiguration&>(other) == *this;
}

ClientConfiguration * ClientConfiguration::_deepCopy() const {
	return new ClientConfiguration(*this);
}

mgen::MGenBase * ClientConfiguration::_newInstance() {
	return new ClientConfiguration;
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
		  
const std::string& ClientConfiguration::_type_name() {
	static const std::string out("se.culvertsoft.mnet.cppclient.ClientConfiguration");
	return out;
}

const std::vector<long long>& ClientConfiguration::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 7110516046795686966LL;
	return out;
}

const std::vector<short>& ClientConfiguration::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << 13927;
	return out;
}

const std::vector<std::string>& ClientConfiguration::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.cppclient.ClientConfiguration";
	return out;
}

const std::vector<std::string>& ClientConfiguration::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "Nmc";
	return out;
}

const std::string& ClientConfiguration::_type_ids_16bit_base64_string() {
	static const std::string out("Nmc");
	return out;
}

const std::string& ClientConfiguration::_type_id_16bit_base64() {
	static const std::string out("Nmc");
	return out;
}

const std::vector<mgen::Field>& ClientConfiguration::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_url_metadata();
	return out;
}

const mgen::Field& ClientConfiguration::_field_url_metadata() {
	static const mgen::Field out(15477, "url", mgen::make_vector<std::string>() << "required");
	return out;
}

} // End namespace cppclient
} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

