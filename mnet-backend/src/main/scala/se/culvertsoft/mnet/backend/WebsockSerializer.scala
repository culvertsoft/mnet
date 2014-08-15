package se.culvertsoft.mnet.backend

import java.io.ByteArrayInputStream
import java.io.ByteArrayOutputStream

import se.culvertsoft.mgen.javapack.serialization.BinaryReader
import se.culvertsoft.mgen.javapack.serialization.BinaryWriter
import se.culvertsoft.mgen.javapack.serialization.JsonReader
import se.culvertsoft.mgen.javapack.serialization.JsonWriter
import se.culvertsoft.mnet.Message

class WebsockSerializer {

  // Stuff for serialization
  private val classRegistry = new ClassRegistry
  private val writeBuffer = new ByteArrayOutputStream
  private val jsonWriter = new JsonWriter(writeBuffer, classRegistry)
  private val binaryWriter = new BinaryWriter(writeBuffer, classRegistry)
  private val jsonReader = new JsonReader(classRegistry)
  private val binaryReader = new BinaryReader(new ByteArrayInputStream(Array[Byte]()), classRegistry)

  def deserializeJson(msg: String): Message = synchronized {
    jsonReader.readObject(msg, classOf[Message])
  }

  def deserializeBinary(msg: Array[Byte]): Message = synchronized {
    binaryReader.setInput(new ByteArrayInputStream(msg)).readObject(classOf[Message])
  }

  def serializeJson(msg: Message): String = synchronized {
    jsonWriter.writeObjectToString(msg)
  }

  def serializeBinary(msg: Message): Array[Byte] = synchronized {
    binaryWriter.writeObject(msg)
    val out = writeBuffer.toByteArray()
    writeBuffer.reset()
    out
  }

}