/********************************************************************************************************************
 ********************************************************************************************************************
 **********************************************************************************************************	
           *****                                                                                      *****
           *****                               GENERATED WITH MGEN                                    *****
           *****                                                                                      *****		
 ********************************************************************************************************************
 ********************************************************************************************************************/

#include "se/culvertsoft/mnet/DataMessage.h"
#include "mgen/util/validation.h"
#include "mgen/util/stlLiteral.h"
/*custom_includes_begin*//*custom_includes_end*/

namespace se {
namespace culvertsoft {
namespace mnet {

DataMessage::DataMessage() : 
		_m_binaryData_isSet(false),
		_m_stringData_isSet(false),
		_m_metaData_isSet(false) {
}

DataMessage::DataMessage(const NodeUUID& senderId, 
			const NodeUUID& targetId, 
			const char& hops, 
			const char& maxHops, 
			const Polymorphic<MessageFilter> & filter, 
			const std::vector<char> & binaryData, 
			const std::string& stringData, 
			const std::string& metaData) : 
		Message(senderId, targetId, hops, maxHops, filter),
		m_binaryData(binaryData),
		m_stringData(stringData),
		m_metaData(metaData),
		_m_binaryData_isSet(true),
		_m_stringData_isSet(true),
		_m_metaData_isSet(true) {
}

DataMessage::~DataMessage() {
}

const std::vector<char> & DataMessage::getBinaryData() const {
	return m_binaryData;
}

const std::string& DataMessage::getStringData() const {
	return m_stringData;
}

const std::string& DataMessage::getMetaData() const {
	return m_metaData;
}

std::vector<char> & DataMessage::getBinaryDataMutable() {
	_m_binaryData_isSet = true;
	return m_binaryData;
}

std::string& DataMessage::getStringDataMutable() {
	_m_stringData_isSet = true;
	return m_stringData;
}

std::string& DataMessage::getMetaDataMutable() {
	_m_metaData_isSet = true;
	return m_metaData;
}

DataMessage& DataMessage::setSenderId(const NodeUUID& senderId) {
	Message::setSenderId(senderId);
	return *this;
}

DataMessage& DataMessage::setTargetId(const NodeUUID& targetId) {
	Message::setTargetId(targetId);
	return *this;
}

DataMessage& DataMessage::setHops(const char& hops) {
	Message::setHops(hops);
	return *this;
}

DataMessage& DataMessage::setMaxHops(const char& maxHops) {
	Message::setMaxHops(maxHops);
	return *this;
}

DataMessage& DataMessage::setFilter(const Polymorphic<MessageFilter> & filter) {
	Message::setFilter(filter);
	return *this;
}

DataMessage& DataMessage::setFilter(const MessageFilter & filter) {
	Message::setFilter(filter);
	return *this;
}

DataMessage& DataMessage::setFilter(MessageFilter * filter, const bool managePtr) {
	Message::setFilter(filter);
	return *this;
}

DataMessage& DataMessage::setBinaryData(const std::vector<char> & binaryData) {
	m_binaryData = binaryData;
	_m_binaryData_isSet = true;
	return *this;
}

DataMessage& DataMessage::setStringData(const std::string& stringData) {
	m_stringData = stringData;
	_m_stringData_isSet = true;
	return *this;
}

DataMessage& DataMessage::setMetaData(const std::string& metaData) {
	m_metaData = metaData;
	_m_metaData_isSet = true;
	return *this;
}

/*custom_methods_begin*//*custom_methods_end*/

bool DataMessage::hasBinaryData() const {
	return _isBinaryDataSet(mgen::SHALLOW);
}

bool DataMessage::hasStringData() const {
	return _isStringDataSet(mgen::SHALLOW);
}

bool DataMessage::hasMetaData() const {
	return _isMetaDataSet(mgen::SHALLOW);
}

DataMessage& DataMessage::unsetSenderId() {
	_setSenderIdSet(false, mgen::SHALLOW);
	return *this;
}

DataMessage& DataMessage::unsetTargetId() {
	_setTargetIdSet(false, mgen::SHALLOW);
	return *this;
}

DataMessage& DataMessage::unsetHops() {
	_setHopsSet(false, mgen::SHALLOW);
	return *this;
}

DataMessage& DataMessage::unsetMaxHops() {
	_setMaxHopsSet(false, mgen::SHALLOW);
	return *this;
}

DataMessage& DataMessage::unsetFilter() {
	_setFilterSet(false, mgen::SHALLOW);
	return *this;
}

DataMessage& DataMessage::unsetBinaryData() {
	_setBinaryDataSet(false, mgen::SHALLOW);
	return *this;
}

DataMessage& DataMessage::unsetStringData() {
	_setStringDataSet(false, mgen::SHALLOW);
	return *this;
}

DataMessage& DataMessage::unsetMetaData() {
	_setMetaDataSet(false, mgen::SHALLOW);
	return *this;
}

bool DataMessage::operator==(const DataMessage& other) const {
	return true
		 && _isSenderIdSet(mgen::SHALLOW) == other._isSenderIdSet(mgen::SHALLOW)
		 && _isTargetIdSet(mgen::SHALLOW) == other._isTargetIdSet(mgen::SHALLOW)
		 && _isHopsSet(mgen::SHALLOW) == other._isHopsSet(mgen::SHALLOW)
		 && _isMaxHopsSet(mgen::SHALLOW) == other._isMaxHopsSet(mgen::SHALLOW)
		 && _isFilterSet(mgen::SHALLOW) == other._isFilterSet(mgen::SHALLOW)
		 && _isBinaryDataSet(mgen::SHALLOW) == other._isBinaryDataSet(mgen::SHALLOW)
		 && _isStringDataSet(mgen::SHALLOW) == other._isStringDataSet(mgen::SHALLOW)
		 && _isMetaDataSet(mgen::SHALLOW) == other._isMetaDataSet(mgen::SHALLOW)
		 && getSenderId() == other.getSenderId()
		 && getTargetId() == other.getTargetId()
		 && getHops() == other.getHops()
		 && getMaxHops() == other.getMaxHops()
		 && getFilter() == other.getFilter()
		 && getBinaryData() == other.getBinaryData()
		 && getStringData() == other.getStringData()
		 && getMetaData() == other.getMetaData();
}

bool DataMessage::operator!=(const DataMessage& other) const {
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
		  
const mgen::Field * DataMessage::_fieldById(const short id) const {
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
	case _field_binaryData_id:
		return &_field_binaryData_metadata();
	case _field_stringData_id:
		return &_field_stringData_metadata();
	case _field_metaData_id:
		return &_field_metaData_metadata();
	default:
		return 0;
	}
}

const mgen::Field * DataMessage::_fieldByName(const std::string& name) const {
	static const std::map<std::string, const mgen::Field*> name2meta = mgen::make_map<std::string, const mgen::Field*>()("senderId", &DataMessage::_field_senderId_metadata())("targetId", &DataMessage::_field_targetId_metadata())("hops", &DataMessage::_field_hops_metadata())("maxHops", &DataMessage::_field_maxHops_metadata())("filter", &DataMessage::_field_filter_metadata())("binaryData", &DataMessage::_field_binaryData_metadata())("stringData", &DataMessage::_field_stringData_metadata())("metaData", &DataMessage::_field_metaData_metadata());
	const std::map<std::string, const mgen::Field*>::const_iterator it = name2meta.find(name);
	return it != name2meta.end() ? it->second : 0;
}

const long long DataMessage::_typeId() const {
	return _type_id;
}

const std::string& DataMessage::_typeName() const {
	return _type_name();
}

const short DataMessage::_typeId16Bit() const {
	return _type_id_16bit;
}

const std::vector<long long>& DataMessage::_typeIds() const {
	return _type_ids();
}

const std::vector<short>& DataMessage::_typeIds16Bit() const {
	return _type_ids_16bit();
}

const std::string& DataMessage::_typeId16BitBase64() const {
	return _type_id_16bit_base64();
}

const std::vector<std::string>& DataMessage::_typeNames() const {
	return _type_names();
}

const std::vector<std::string>& DataMessage::_typeIds16BitBase64() const {
	return _type_ids_16bit_base64();
}

const std::string& DataMessage::_typeIds16BitBase64String() const {
	return _type_ids_16bit_base64_string();
}

const std::vector<mgen::Field>& DataMessage::_fieldMetadatas() const {
	return _field_metadatas();
}

DataMessage& DataMessage::_setBinaryDataSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_binaryData.clear();
	else if (depth == mgen::DEEP)
		mgen::validation::setFieldSetDeep(m_binaryData);
	_m_binaryData_isSet = state;
	return *this;
}

DataMessage& DataMessage::_setStringDataSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_stringData = "";
	_m_stringData_isSet = state;
	return *this;
}

DataMessage& DataMessage::_setMetaDataSet(const bool state, const mgen::FieldSetDepth depth) {
	if (!state)
		m_metaData = "";
	_m_metaData_isSet = state;
	return *this;
}

DataMessage& DataMessage::_setAllFieldsSet(const bool state, const mgen::FieldSetDepth depth) { 
	_setSenderIdSet(state, depth);
	_setTargetIdSet(state, depth);
	_setHopsSet(state, depth);
	_setMaxHopsSet(state, depth);
	_setFilterSet(state, depth);
	_setBinaryDataSet(state, depth);
	_setStringDataSet(state, depth);
	_setMetaDataSet(state, depth);
	return *this;
}

int DataMessage::_numFieldsSet(const mgen::FieldSetDepth depth, const bool includeTransient) const {
	int out = 0;
	out += _isSenderIdSet(depth) ? 1 : 0;
	out += _isTargetIdSet(depth) ? 1 : 0;
	out += _isHopsSet(depth) ? 1 : 0;
	out += _isMaxHopsSet(depth) ? 1 : 0;
	out += _isFilterSet(depth) ? 1 : 0;
	out += _isBinaryDataSet(depth) ? 1 : 0;
	out += _isStringDataSet(depth) ? 1 : 0;
	out += _isMetaDataSet(depth) ? 1 : 0;
	return out;
}

bool DataMessage::_isFieldSet(const mgen::Field& field, const mgen::FieldSetDepth depth) const {
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
		case (_field_binaryData_id):
			return _isBinaryDataSet(depth);
		case (_field_stringData_id):
			return _isStringDataSet(depth);
		case (_field_metaData_id):
			return _isMetaDataSet(depth);
		default:
			return false;
	}
}

bool DataMessage::_isBinaryDataSet(const mgen::FieldSetDepth depth) const {
	return _m_binaryData_isSet;
}

bool DataMessage::_isStringDataSet(const mgen::FieldSetDepth depth) const {
	return _m_stringData_isSet;
}

bool DataMessage::_isMetaDataSet(const mgen::FieldSetDepth depth) const {
	return _m_metaData_isSet;
}

bool DataMessage::_validate(const mgen::FieldSetDepth depth) const { 
	if (depth == mgen::SHALLOW) {
		return true;
	} else {
		return true
				&& (!_isSenderIdSet(mgen::SHALLOW) || _isSenderIdSet(mgen::DEEP))
				&& (!_isTargetIdSet(mgen::SHALLOW) || _isTargetIdSet(mgen::DEEP))
				&& (!_isFilterSet(mgen::SHALLOW) || _isFilterSet(mgen::DEEP));
	}
}

bool DataMessage::_equals(const mgen::MGenBase& other) const {
	return _type_id == other._typeId() && static_cast<const DataMessage&>(other) == *this;
}

DataMessage * DataMessage::_deepCopy() const {
	return new DataMessage(*this);
}

mgen::MGenBase * DataMessage::_newInstance() {
	return new DataMessage;
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
		  
const std::string& DataMessage::_type_name() {
	static const std::string out("se.culvertsoft.mnet.DataMessage");
	return out;
}

const std::vector<long long>& DataMessage::_type_ids() {
	static const std::vector<long long> out = mgen::make_vector<long long>() << 513154294965126267LL << 7039459695819845027LL;
	return out;
}

const std::vector<short>& DataMessage::_type_ids_16bit() {
	static const std::vector<short> out = mgen::make_vector<short>() << -28540 << 20480;
	return out;
}

const std::vector<std::string>& DataMessage::_type_names() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "se.culvertsoft.mnet.Message" << "se.culvertsoft.mnet.DataMessage";
	return out;
}

const std::vector<std::string>& DataMessage::_type_ids_16bit_base64() {
	static const std::vector<std::string> out = mgen::make_vector<std::string>() << "kIQ" << "UAA";
	return out;
}

const std::string& DataMessage::_type_ids_16bit_base64_string() {
	static const std::string out("kIQUAA");
	return out;
}

const std::string& DataMessage::_type_id_16bit_base64() {
	static const std::string out("UAA");
	return out;
}

const std::vector<mgen::Field>& DataMessage::_field_metadatas() {
	static const std::vector<mgen::Field> out = mgen::make_vector<mgen::Field>() << _field_senderId_metadata() << _field_targetId_metadata() << _field_hops_metadata() << _field_maxHops_metadata() << _field_filter_metadata() << _field_binaryData_metadata() << _field_stringData_metadata() << _field_metaData_metadata();
	return out;
}

const mgen::Field& DataMessage::_field_binaryData_metadata() {
	static const mgen::Field out(-25211, "binaryData");
	return out;
}

const mgen::Field& DataMessage::_field_stringData_metadata() {
	static const mgen::Field out(3744, "stringData");
	return out;
}

const mgen::Field& DataMessage::_field_metaData_metadata() {
	static const mgen::Field out(24771, "metaData");
	return out;
}

} // End namespace mnet
} // End namespace culvertsoft
} // End namespace se

