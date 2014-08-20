/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_NODEUUID
#define SE_CULVERTSOFT_MNET_NODEUUID

#include "mgen/classes/MGenBase.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

class NodeUUID : public mgen::MGenBase /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	long long m_lsb;
	long long m_msb;
	bool _m_lsb_isSet;
	bool _m_msb_isSet;

public:
	NodeUUID();
	NodeUUID(const long long& lsb,
			const long long& msb);
	virtual ~NodeUUID();

	const long long& getLsb() const;
	const long long& getMsb() const;

	long long& getLsbMutable();
	long long& getMsbMutable();

	NodeUUID& setLsb(const long long& lsb);
	NodeUUID& setMsb(const long long& msb);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasLsb() const;
	bool hasMsb() const;

	NodeUUID& unsetLsb();
	NodeUUID& unsetMsb();

	bool operator==(const NodeUUID& other) const;
	bool operator!=(const NodeUUID& other) const;


							
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
		case _field_lsb_id:
			reader.readField(_field_lsb_metadata(), context, getLsbMutable());
			break;
		case _field_msb_id:
			reader.readField(_field_msb_metadata(), context, getMsbMutable());
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
				visitor.beginVisit(*this, 2);
				visitor.visit(getLsb(), _field_lsb_metadata());
				visitor.visit(getMsb(), _field_msb_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isLsbSet(mgen::SHALLOW))
					visitor.visit(getLsb(), _field_lsb_metadata());
				if (_isMsbSet(mgen::SHALLOW))
					visitor.visit(getMsb(), _field_msb_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 2);
				visitor.visit(getLsbMutable(), _field_lsb_metadata());
				visitor.visit(getMsbMutable(), _field_msb_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isLsbSet(mgen::SHALLOW))
					visitor.visit(getLsbMutable(), _field_lsb_metadata());
				if (_isMsbSet(mgen::SHALLOW))
					visitor.visit(getMsbMutable(), _field_msb_metadata());
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

	NodeUUID& _setLsbSet(const bool state, const mgen::FieldSetDepth depth);
	NodeUUID& _setMsbSet(const bool state, const mgen::FieldSetDepth depth);

	NodeUUID& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isLsbSet(const mgen::FieldSetDepth depth) const;
	bool _isMsbSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	NodeUUID * _deepCopy() const;

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
		  
	static const long long _type_id = 4507004109412558583LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = 8590;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_lsb_metadata();
	static const mgen::Field& _field_msb_metadata();

	static const short _field_lsb_id = 13176;
	static const short _field_msb_id = 1096;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class NodeUUID

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
