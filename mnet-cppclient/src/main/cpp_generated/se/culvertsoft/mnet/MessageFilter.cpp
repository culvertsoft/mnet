/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/MessageFilter.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

MessageFilter::MessageFilter() {
}

MessageFilter::~MessageFilter() {
}

/*custom_methods_begin*//*custom_methods_end*/

bool MessageFilter::operator==(const MessageFilter& other) const {
	return true;
}

bool MessageFilter::operator!=(const MessageFilter& other) const {
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
		  
const mgen::Field * MessageFilter::_fieldById(const short id) const {
	return 0;
}

const mgen::Field * MessageFilter::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta;
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long MessageFilter::_typeId() const {
	return _type_id;
}

const std::string& MessageFilter::_typeName() const {
	return _type_name();
}

const short MessageFilter::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& MessageFilter::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& MessageFilter::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& MessageFilter::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& MessageFilter::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& MessageFilter::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& MessageFilter::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& MessageFilter::_fieldMetadatas() const {
	return _field_metadatas();
}

MessageFilter& MessageFilter::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	return *this;
}

int MessageFilter::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	return out;
}

bool MessageFilter::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
	return false;
}

bool MessageFilter::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true;
	}
}

bool MessageFilter::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const MessageFilter&>(other) == *this;
}

MessageFilter * MessageFilter::_deepCopy() const {
	return new MessageFilter(*this);
}

mgen::MGenBase * MessageFilter::_newInstance() {
	return new MessageFilter;
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
		  
const std::string& MessageFilter::_type_name() {
	static const std::string out("se.culvertsoft.mnet.MessageFilter");
	return out;
}

const std::vector<long long>& MessageFilter::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 3349473122850819639LL;
	return out;
}

const std::vector<short>& MessageFilter::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -29951;
	return out;
}

const std::vector<std::string>& MessageFilter::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.MessageFilter";
	return out;
}

const std::vector<std::string>& MessageFilter::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "iwE";
	return out;
}

const std::string& MessageFilter::_type_ids_16bit_base64_string() {
	static const std::string out("iwE");
	return out;
}

const std::string& MessageFilter::_type_id_16bit_base64() {
	static const std::string out("iwE");
	return out;
}

const std::vector<mgen::Field>& MessageFilter::_field_metadatas() {
	static const std::vector<mgen::Field> out;
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

