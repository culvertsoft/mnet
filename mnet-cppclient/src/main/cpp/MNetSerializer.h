#pragma once

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
			return readMessage(m_jsonReader, data, length);
		}

		std::shared_ptr<Message> readBinary(const char * data, const int length) {
			return readMessage(m_binaryReader, data, length);
		}

		std::vector<char> writeJson(const Message& msg) {
			return writeMessage(m_jsonWriter, msg);
		}

		std::vector<char> writeBinary(const Message& msg) {
			return writeMessage(m_binaryWriter, msg);
		}

	private:

		template <typename WriterType>
		std::vector<char> writeMessage(WriterType& writer, const Message& msg) {
			m_outputStream.reset();
			m_outputBuffer.clear();
			writer.template writeObject(msg);
			return m_outputBuffer;
		}

		template <typename ReaderType>
		std::shared_ptr<Message> readMessage(
			ReaderType& reader,
			const char * data, 
			const int length) {
			m_inputStream.reset();
			m_inputBuffer.clear();
			m_inputBuffer.insert(m_inputBuffer.end(), data, data + length);
			return std::shared_ptr<Message>(reader.template readObject<Message>());
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