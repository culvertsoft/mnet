/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_CPPCLIENT_CLIENTCONFIGURATION
#define SE_CULVERTSOFT_MNET_CPPCLIENT_CLIENTCONFIGURATION

#include "mgen/classes/MGenBase.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {
namespace cppclient {

class ClientConfiguration : public mgen::MGenBase /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	std::string m_url;
	std::string m_name;
	std::vector<std::string>  m_tags;
	bool _m_url_isSet;
	bool _m_name_isSet;
	bool _m_tags_isSet;

public:
	ClientConfiguration();
	ClientConfiguration(const std::string& url,
			const std::string& name,
			const std::vector<std::string> & tags);
	virtual ~ClientConfiguration();

	const std::string& getUrl() const;
	const std::string& getName() const;
	const std::vector<std::string> & getTags() const;

	std::string& getUrlMutable();
	std::string& getNameMutable();
	std::vector<std::string> & getTagsMutable();

	ClientConfiguration& setUrl(const std::string& url);
	ClientConfiguration& setName(const std::string& name);
	ClientConfiguration& setTags(const std::vector<std::string> & tags);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasUrl() const;
	bool hasName() const;
	bool hasTags() const;

	ClientConfiguration& unsetUrl();
	ClientConfiguration& unsetName();
	ClientConfiguration& unsetTags();

	bool operator==(const ClientConfiguration& other) const;
	bool operator!=(const ClientConfiguration& other) const;


							
/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                    TYPE METADATA ACCESS AND SERIALIZATION METHODS                    *****
           *****          (accessed primarily by (de-)serializers and for ORM functionality)          *****	
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/	 		  
		  
public:
	template<typename ReaderType, typename ReadContextType>
	void _readField(const short fieldId, ReadContextType& context, ReaderType& reader) {
		switch (fieldId) {
		case _field_url_id:
			reader.readField(_field_url_metadata(), context, getUrlMutable());
			break;
		case _field_name_id:
			reader.readField(_field_name_metadata(), context, getNameMutable());
			break;
		case _field_tags_id:
			reader.readField(_field_tags_metadata(), context, getTagsMutable());
			break;
		default:
			reader.handleUnknownField(fieldId, context);
			break;
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) const {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 3);
				visitor.visit(getUrl(), _field_url_metadata());
				visitor.visit(getName(), _field_name_metadata());
				visitor.visit(getTags(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isUrlSet(mgen::SHALLOW))
					visitor.visit(getUrl(), _field_url_metadata());
				if (_isNameSet(mgen::SHALLOW))
					visitor.visit(getName(), _field_name_metadata());
				if (_isTagsSet(mgen::SHALLOW))
					visitor.visit(getTags(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 3);
				visitor.visit(getUrlMutable(), _field_url_metadata());
				visitor.visit(getNameMutable(), _field_name_metadata());
				visitor.visit(getTagsMutable(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isUrlSet(mgen::SHALLOW))
					visitor.visit(getUrlMutable(), _field_url_metadata());
				if (_isNameSet(mgen::SHALLOW))
					visitor.visit(getNameMutable(), _field_name_metadata());
				if (_isTagsSet(mgen::SHALLOW))
					visitor.visit(getTagsMutable(), _field_tags_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	const mgen::Field * _fieldById(const short id) const;
	const mgen::Field * _fieldByName(const std::string& name) const;
	const long long _typeId() const;
	const short _typeId16Bit() const;
	const std::string& _typeId16BitBase64() const;
	const std::string& _typeName() const;

	const std::vector<long long>& _typeIds() const;
	const std::vector<short>& _typeIds16Bit() const;
	const std::vector<std::string>& _typeIds16BitBase64() const;
	const std::string& _typeIds16BitBase64String() const;
	const std::vector<std::string>& _typeNames() const;

	const std::vector<mgen::Field>& _fieldMetadatas() const;

	bool _isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const;

	ClientConfiguration& _setUrlSet(const bool state, const mgen::FieldSetDepth depth);
	ClientConfiguration& _setNameSet(const bool state, const mgen::FieldSetDepth depth);
	ClientConfiguration& _setTagsSet(const bool state, const mgen::FieldSetDepth depth);

	ClientConfiguration& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isUrlSet(const mgen::FieldSetDepth depth) const;
	bool _isNameSet(const mgen::FieldSetDepth depth) const;
	bool _isTagsSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	ClientConfiguration * _deepCopy() const;

	static mgen::MGenBase * _newInstance();

							
/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                                    TYPE METADATA                                     *****
           *****             (generally speaking, it's a bad idea to edit this manually)              *****	
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/	 		  
		  
	static const long long _type_id = 7110516046795686966LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = 13927;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_url_metadata();
	static const mgen::Field& _field_name_metadata();
	static const mgen::Field& _field_tags_metadata();

	static const short _field_url_id = 15477;
	static const short _field_name_id = -28058;
	static const short _field_tags_id = 31830;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class ClientConfiguration

} // End namespace cppclient
} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
