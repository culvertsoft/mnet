/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_NODESETTINGS
#define SE_CULVERTSOFT_MNET_NODESETTINGS

#include "mgen/classes/MGenBase.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

class NodeSettings : public mgen::MGenBase /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	std::string m_name;
	std::vector<std::string>  m_tags;
	double m_announceInterval;
	int m_maxHopsDefault;
	int m_maxHopsLimit;
	bool _m_name_isSet;
	bool _m_tags_isSet;
	bool _m_announceInterval_isSet;
	bool _m_maxHopsDefault_isSet;
	bool _m_maxHopsLimit_isSet;

public:
	NodeSettings();
	NodeSettings(const std::string& name,
			const std::vector<std::string> & tags,
			const double& announceInterval,
			const int& maxHopsDefault,
			const int& maxHopsLimit);
	virtual ~NodeSettings();

	const std::string& getName() const;
	const std::vector<std::string> & getTags() const;
	const double& getAnnounceInterval() const;
	const int& getMaxHopsDefault() const;
	const int& getMaxHopsLimit() const;

	std::string& getNameMutable();
	std::vector<std::string> & getTagsMutable();
	double& getAnnounceIntervalMutable();
	int& getMaxHopsDefaultMutable();
	int& getMaxHopsLimitMutable();

	NodeSettings& setName(const std::string& name);
	NodeSettings& setTags(const std::vector<std::string> & tags);
	NodeSettings& setAnnounceInterval(const double& announceInterval);
	NodeSettings& setMaxHopsDefault(const int& maxHopsDefault);
	NodeSettings& setMaxHopsLimit(const int& maxHopsLimit);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasName() const;
	bool hasTags() const;
	bool hasAnnounceInterval() const;
	bool hasMaxHopsDefault() const;
	bool hasMaxHopsLimit() const;

	NodeSettings& unsetName();
	NodeSettings& unsetTags();
	NodeSettings& unsetAnnounceInterval();
	NodeSettings& unsetMaxHopsDefault();
	NodeSettings& unsetMaxHopsLimit();

	bool operator==(const NodeSettings& other) const;
	bool operator!=(const NodeSettings& other) const;


							
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
		case _field_name_id:
			reader.readField(_field_name_metadata(), context, getNameMutable());
			break;
		case _field_tags_id:
			reader.readField(_field_tags_metadata(), context, getTagsMutable());
			break;
		case _field_announceInterval_id:
			reader.readField(_field_announceInterval_metadata(), context, getAnnounceIntervalMutable());
			break;
		case _field_maxHopsDefault_id:
			reader.readField(_field_maxHopsDefault_metadata(), context, getMaxHopsDefaultMutable());
			break;
		case _field_maxHopsLimit_id:
			reader.readField(_field_maxHopsLimit_metadata(), context, getMaxHopsLimitMutable());
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
				visitor.beginVisit(*this, 5);
				visitor.visit(getName(), _field_name_metadata());
				visitor.visit(getTags(), _field_tags_metadata());
				visitor.visit(getAnnounceInterval(), _field_announceInterval_metadata());
				visitor.visit(getMaxHopsDefault(), _field_maxHopsDefault_metadata());
				visitor.visit(getMaxHopsLimit(), _field_maxHopsLimit_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isNameSet(mgen::SHALLOW))
					visitor.visit(getName(), _field_name_metadata());
				if (_isTagsSet(mgen::SHALLOW))
					visitor.visit(getTags(), _field_tags_metadata());
				if (_isAnnounceIntervalSet(mgen::SHALLOW))
					visitor.visit(getAnnounceInterval(), _field_announceInterval_metadata());
				if (_isMaxHopsDefaultSet(mgen::SHALLOW))
					visitor.visit(getMaxHopsDefault(), _field_maxHopsDefault_metadata());
				if (_isMaxHopsLimitSet(mgen::SHALLOW))
					visitor.visit(getMaxHopsLimit(), _field_maxHopsLimit_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 5);
				visitor.visit(getNameMutable(), _field_name_metadata());
				visitor.visit(getTagsMutable(), _field_tags_metadata());
				visitor.visit(getAnnounceIntervalMutable(), _field_announceInterval_metadata());
				visitor.visit(getMaxHopsDefaultMutable(), _field_maxHopsDefault_metadata());
				visitor.visit(getMaxHopsLimitMutable(), _field_maxHopsLimit_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isNameSet(mgen::SHALLOW))
					visitor.visit(getNameMutable(), _field_name_metadata());
				if (_isTagsSet(mgen::SHALLOW))
					visitor.visit(getTagsMutable(), _field_tags_metadata());
				if (_isAnnounceIntervalSet(mgen::SHALLOW))
					visitor.visit(getAnnounceIntervalMutable(), _field_announceInterval_metadata());
				if (_isMaxHopsDefaultSet(mgen::SHALLOW))
					visitor.visit(getMaxHopsDefaultMutable(), _field_maxHopsDefault_metadata());
				if (_isMaxHopsLimitSet(mgen::SHALLOW))
					visitor.visit(getMaxHopsLimitMutable(), _field_maxHopsLimit_metadata());
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

	NodeSettings& _setNameSet(const bool state, const mgen::FieldSetDepth depth);
	NodeSettings& _setTagsSet(const bool state, const mgen::FieldSetDepth depth);
	NodeSettings& _setAnnounceIntervalSet(const bool state, const mgen::FieldSetDepth depth);
	NodeSettings& _setMaxHopsDefaultSet(const bool state, const mgen::FieldSetDepth depth);
	NodeSettings& _setMaxHopsLimitSet(const bool state, const mgen::FieldSetDepth depth);

	NodeSettings& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isNameSet(const mgen::FieldSetDepth depth) const;
	bool _isTagsSet(const mgen::FieldSetDepth depth) const;
	bool _isAnnounceIntervalSet(const mgen::FieldSetDepth depth) const;
	bool _isMaxHopsDefaultSet(const mgen::FieldSetDepth depth) const;
	bool _isMaxHopsLimitSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	NodeSettings * _deepCopy() const;

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
		  
	static const long long _type_id = 8357426928295150751LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = 9024;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_name_metadata();
	static const mgen::Field& _field_tags_metadata();
	static const mgen::Field& _field_announceInterval_metadata();
	static const mgen::Field& _field_maxHopsDefault_metadata();
	static const mgen::Field& _field_maxHopsLimit_metadata();

	static const short _field_name_id = -28058;
	static const short _field_tags_id = 31830;
	static const short _field_announceInterval_id = -5317;
	static const short _field_maxHopsDefault_id = 20361;
	static const short _field_maxHopsLimit_id = -13824;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class NodeSettings

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
