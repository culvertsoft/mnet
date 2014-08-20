/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#ifndef SE_CULVERTSOFT_MNET_DATAMESSAGE
#define SE_CULVERTSOFT_MNET_DATAMESSAGE

#include "se/culvertsoft/mnet/Message.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

class DataMessage : public Message /*custom_ifcs_begin*//*custom_ifcs_end*/ {
private:
	std::vector<char>  m_binaryData;
	std::string m_stringData;
	std::string m_metaData;
	bool _m_binaryData_isSet;
	bool _m_stringData_isSet;
	bool _m_metaData_isSet;

public:
	DataMessage();
	DataMessage(const NodeUUID& senderId,
			const NodeUUID& targetId,
			const char& hops,
			const char& maxHops,
			const Polymorphic<MessageFilter> & filter,
			const std::vector<char> & binaryData,
			const std::string& stringData,
			const std::string& metaData);
	virtual ~DataMessage();

	const std::vector<char> & getBinaryData() const;
	const std::string& getStringData() const;
	const std::string& getMetaData() const;

	std::vector<char> & getBinaryDataMutable();
	std::string& getStringDataMutable();
	std::string& getMetaDataMutable();

	DataMessage& setSenderId(const NodeUUID& senderId);
	DataMessage& setTargetId(const NodeUUID& targetId);
	DataMessage& setHops(const char& hops);
	DataMessage& setMaxHops(const char& maxHops);
	DataMessage& setFilter(const Polymorphic<MessageFilter> & filter);
	DataMessage& setFilter(const MessageFilter & filter);
	DataMessage& setFilter(MessageFilter * filter, const bool managePtr = true);
	DataMessage& setBinaryData(const std::vector<char> & binaryData);
	DataMessage& setStringData(const std::string& stringData);
	DataMessage& setMetaData(const std::string& metaData);

	/*custom_methods_begin*//*custom_methods_end*/

	bool hasBinaryData() const;
	bool hasStringData() const;
	bool hasMetaData() const;

	DataMessage& unsetSenderId();
	DataMessage& unsetTargetId();
	DataMessage& unsetHops();
	DataMessage& unsetMaxHops();
	DataMessage& unsetFilter();
	DataMessage& unsetBinaryData();
	DataMessage& unsetStringData();
	DataMessage& unsetMetaData();

	bool operator==(const DataMessage& other) const;
	bool operator!=(const DataMessage& other) const;


							
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
		case _field_senderId_id:
			reader.readField(_field_senderId_metadata(), context, getSenderIdMutable());
			break;
		case _field_targetId_id:
			reader.readField(_field_targetId_metadata(), context, getTargetIdMutable());
			break;
		case _field_hops_id:
			reader.readField(_field_hops_metadata(), context, getHopsMutable());
			break;
		case _field_maxHops_id:
			reader.readField(_field_maxHops_metadata(), context, getMaxHopsMutable());
			break;
		case _field_filter_id:
			reader.readField(_field_filter_metadata(), context, getFilterMutable());
			break;
		case _field_binaryData_id:
			reader.readField(_field_binaryData_metadata(), context, getBinaryDataMutable());
			break;
		case _field_stringData_id:
			reader.readField(_field_stringData_metadata(), context, getStringDataMutable());
			break;
		case _field_metaData_id:
			reader.readField(_field_metaData_metadata(), context, getMetaDataMutable());
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
				visitor.beginVisit(*this, 8);
				visitor.visit(getSenderId(), _field_senderId_metadata());
				visitor.visit(getTargetId(), _field_targetId_metadata());
				visitor.visit(getHops(), _field_hops_metadata());
				visitor.visit(getMaxHops(), _field_maxHops_metadata());
				visitor.visit(getFilter(), _field_filter_metadata());
				visitor.visit(getBinaryData(), _field_binaryData_metadata());
				visitor.visit(getStringData(), _field_stringData_metadata());
				visitor.visit(getMetaData(), _field_metaData_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isSenderIdSet(mgen::SHALLOW))
					visitor.visit(getSenderId(), _field_senderId_metadata());
				if (_isTargetIdSet(mgen::SHALLOW))
					visitor.visit(getTargetId(), _field_targetId_metadata());
				if (_isHopsSet(mgen::SHALLOW))
					visitor.visit(getHops(), _field_hops_metadata());
				if (_isMaxHopsSet(mgen::SHALLOW))
					visitor.visit(getMaxHops(), _field_maxHops_metadata());
				if (_isFilterSet(mgen::SHALLOW))
					visitor.visit(getFilter(), _field_filter_metadata());
				if (_isBinaryDataSet(mgen::SHALLOW))
					visitor.visit(getBinaryData(), _field_binaryData_metadata());
				if (_isStringDataSet(mgen::SHALLOW))
					visitor.visit(getStringData(), _field_stringData_metadata());
				if (_isMetaDataSet(mgen::SHALLOW))
					visitor.visit(getMetaData(), _field_metaData_metadata());
				visitor.endVisit();
				break;
			}
		}
	}

	template<typename VisitorType>
	void _accept(VisitorType& visitor, const mgen::FieldVisitSelection selection) {
		switch(selection) {
			case mgen::ALL: {
				visitor.beginVisit(*this, 8);
				visitor.visit(getSenderIdMutable(), _field_senderId_metadata());
				visitor.visit(getTargetIdMutable(), _field_targetId_metadata());
				visitor.visit(getHopsMutable(), _field_hops_metadata());
				visitor.visit(getMaxHopsMutable(), _field_maxHops_metadata());
				visitor.visit(getFilterMutable(), _field_filter_metadata());
				visitor.visit(getBinaryDataMutable(), _field_binaryData_metadata());
				visitor.visit(getStringDataMutable(), _field_stringData_metadata());
				visitor.visit(getMetaDataMutable(), _field_metaData_metadata());
				visitor.endVisit();
				break;
			}
			default /* case mgen::ALL_SET_NONTRANSIENT */ : {
				visitor.beginVisit(*this, _numFieldsSet(mgen::SHALLOW, false));
				if (_isSenderIdSet(mgen::SHALLOW))
					visitor.visit(getSenderIdMutable(), _field_senderId_metadata());
				if (_isTargetIdSet(mgen::SHALLOW))
					visitor.visit(getTargetIdMutable(), _field_targetId_metadata());
				if (_isHopsSet(mgen::SHALLOW))
					visitor.visit(getHopsMutable(), _field_hops_metadata());
				if (_isMaxHopsSet(mgen::SHALLOW))
					visitor.visit(getMaxHopsMutable(), _field_maxHops_metadata());
				if (_isFilterSet(mgen::SHALLOW))
					visitor.visit(getFilterMutable(), _field_filter_metadata());
				if (_isBinaryDataSet(mgen::SHALLOW))
					visitor.visit(getBinaryDataMutable(), _field_binaryData_metadata());
				if (_isStringDataSet(mgen::SHALLOW))
					visitor.visit(getStringDataMutable(), _field_stringData_metadata());
				if (_isMetaDataSet(mgen::SHALLOW))
					visitor.visit(getMetaDataMutable(), _field_metaData_metadata());
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

	DataMessage& _setBinaryDataSet(const bool state, const mgen::FieldSetDepth depth);
	DataMessage& _setStringDataSet(const bool state, const mgen::FieldSetDepth depth);
	DataMessage& _setMetaDataSet(const bool state, const mgen::FieldSetDepth depth);

	DataMessage& _setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth);

	int _numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const;

	bool _isBinaryDataSet(const mgen::FieldSetDepth depth) const;
	bool _isStringDataSet(const mgen::FieldSetDepth depth) const;
	bool _isMetaDataSet(const mgen::FieldSetDepth depth) const;

	bool _validate(const mgen::FieldSetDepth depth) const;

	bool _equals(const mgen::MGenBase& other) const;

	DataMessage * _deepCopy() const;

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
		  
	static const long long _type_id = 7039459695819845027LL;
	static const std::vector<long long>& _type_ids();

	static const short _type_id_16bit = 20480;
	static const std::vector<short>& _type_ids_16bit();

	static const std::string& _type_id_16bit_base64();
	static const std::vector<std::string>& _type_ids_16bit_base64();

	static const std::string& _type_ids_16bit_base64_string();

	static const std::string& _type_name();
	static const std::vector<std::string>& _type_names();

	static const mgen::Field& _field_binaryData_metadata();
	static const mgen::Field& _field_stringData_metadata();
	static const mgen::Field& _field_metaData_metadata();

	static const short _field_binaryData_id = -25211;
	static const short _field_stringData_id = 3744;
	static const short _field_metaData_id = 24771;

	static const std::vector<mgen::Field>& _field_metadatas();

}; // End class DataMessage

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

#endif
