#pragma once

#include <memory>
#include <se/culvertsoft/mnet/Message.h>

#include <mgen/serialization/VectorInputStream.h>
#include <mgen/serialization/VectorOutputStream.h>
#include <mgen/serialization/JsonReader.h>
#include <mgen/serialization/JsonPrettyWriter.h>
#include <mgen/serialization/BinaryReader.h>
#include <mgen/serialization/BinaryWriter.h>

namespace mnet {

	template <typename ClassRegistryType>
	class MNetSerializer {
		typedef se::culvertsoft::mnet::Message Message;

	public:

		MNetSerializer() :
			m_inputStream(m_inputBuffer),
			m_outputStream(m_outputBuffer),
			m_jsonReader(m_inputStream, m_classRegistry),
			m_jsonWriter(m_outputStream, m_classRegistry),
			m_binaryReader(m_inputStream, m_classRegistry),
			m_binaryWriter(m_outputStream, m_classRegistry) {

		}

		std::shared_ptr<Message> readJson(const char * data, const int length) {
			return readJson<Message>(data, length);
		}

		template <typename ObjectType>
		std::shared_ptr<ObjectType> readJson(const char * data, const int length) {
			return readObject<ObjectType>(m_jsonReader, data, length);
		}

		std::shared_ptr<Message> readBinary(const char * data, const int length) {
			return readBinary<Message>(data, length);
		}

		template <typename ObjectType>
		std::shared_ptr<ObjectType> readBinary(const char * data, const int length) {
			return readObject<ObjectType>(m_binaryReader, data, length);
		}

		std::vector<char> writeJson(const mgen::MGenBase& msg) {
			return writeMessage(m_jsonWriter, msg);
		}

		std::vector<char> writeBinary(const mgen::MGenBase& msg) {
			return writeMessage(m_binaryWriter, msg);
		}

	private:

		template <typename WriterType>
		std::vector<char> writeMessage(WriterType& writer, const mgen::MGenBase& msg) {
			m_outputStream.reset();
			m_outputBuffer.clear();
			writer.writeObject(msg);
			return m_outputBuffer;
		}

		template <typename ObjectType, typename ReaderType>
		std::shared_ptr<ObjectType> readObject(
			ReaderType& reader,
			const char * data, 
			const int length) {
			m_inputStream.reset();
			m_inputBuffer.clear();
			m_inputBuffer.insert(m_inputBuffer.end(), data, data + length);
			return std::shared_ptr<ObjectType>(reader.template readObject<ObjectType>());
		}

		ClassRegistryType m_classRegistry;
		std::vector<char> m_inputBuffer;
		std::vector<char> m_outputBuffer;
		mgen::VectorInputStream m_inputStream;
		mgen::VectorOutputStream m_outputStream;
		mgen::JsonReader<mgen::VectorInputStream, ClassRegistryType> m_jsonReader;
		mgen::JsonPrettyWriter<mgen::VectorOutputStream, ClassRegistryType> m_jsonWriter;
		mgen::BinaryReader<mgen::VectorInputStream, ClassRegistryType> m_binaryReader;
		mgen::BinaryWriter<mgen::VectorOutputStream, ClassRegistryType> m_binaryWriter;

		// MNetClient is noncopyable
		MNetSerializer(const MNetSerializer& other);
		MNetSerializer& operator=(const MNetSerializer& other);
	};

}