package se.culvertsoft.mnet.backend

import java.io.ByteArrayInputStream
import java.io.ByteArrayOutputStream
import java.net.InetSocketAddress
import java.nio.ByteBuffer
import java.util.UUID

import scala.collection.JavaConversions.asScalaBuffer
import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import scala.collection.mutable.HashSet

import org.java_websocket.WebSocket
import org.java_websocket.handshake.ClientHandshake

import se.culvertsoft.mgen.javapack.classes.MGenBase
import se.culvertsoft.mgen.javapack.serialization.BinaryReader
import se.culvertsoft.mgen.javapack.serialization.BinaryWriter
import se.culvertsoft.mgen.javapack.serialization.JsonReader
import se.culvertsoft.mgen.javapack.serialization.JsonWriter
import se.culvertsoft.mnet.NetworkId

class BackEnd(settings: BackendConfiguration = new BackendConfiguration) {

  val id = mkLocalId()
  val port = settings.getPort()

  private var closed = false

  // Valid entities
  private val nodes = new HashSet[Node]
  private val clients = new HashSet[Client]

  // Pending entities
  private val pending = new HashMap[WebSocket, AnyRef]

  // Kept so we can close them (they have slave threads)
  private val listeningIfcs = new ArrayBuffer[ListeningIfc]
  private val connectingTo = new ArrayBuffer[OutboundNodeConnection]

  // Stuff for serialization
  private val classRegistry = new ClassRegistry
  private val writeBuffer = new ByteArrayOutputStream
  private val jsonWriter = new JsonWriter(writeBuffer, classRegistry)
  private val binaryWriter = new BinaryWriter(writeBuffer, classRegistry)
  private val jsonReader = new JsonReader(classRegistry)
  private val binaryReader = new BinaryReader(new ByteArrayInputStream(Array[Byte]()), classRegistry)

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  def start(): BackEnd = {
    if (listeningIfcs.nonEmpty)
      throw new RuntimeException("Tried to start BackEnd Twice!")

    if (settings.hasListeningInterfaces()) {
      ???
    } else {
      listeningIfcs += new ListeningIfc(this, new InetSocketAddress(port))
    }

    listeningIfcs.foreach(_.start())

    for (addr <- settings.getRemoteNodes) {
      connectingTo += new OutboundNodeConnection(addr, this)
    }

    this
  }

  def close() {
    synchronized(closed = true)
    listeningIfcs.foreach(_.stop())
    nodes.foreach(_.close())
    pending.foreach(_._1.close())
    clients.foreach(_.close())
    connectingTo.foreach(_.close())
  }

  def handleError(source: AnyRef,
    connection: WebSocket,
    error: Exception) {
    error.printStackTrace()
  }

  def handleMsg(msg: String, client: Client) {}
  def handleMsg(msg: Array[Byte], client: Client) {}
  def handleMsg(msg: Array[Byte], client: Node) {}
  def handleMsg(msg: String, client: Node) {}

  def handleMsgForPendingConnection(
    source: AnyRef,
    connection: WebSocket,
    message: MGenBase) {
    println(s"Got ${message._typeName} from $connection")
  }

  def handleMsgForClientOrNode(
    source: AnyRef,
    connection: WebSocket,
    message: MGenBase) {
    println(s"Got ${message._typeName} from $connection")
  }

  /**
   * **********************************************
   * These may be called from virtually any thread.
   * We'll collect all calls here
   * **********************************************
   */

  private[backend] final def onOpen(
    source: AnyRef,
    connection: WebSocket,
    handshake: ClientHandshake): Unit = synchronized {
    if (closed) {
      connection.close()
      return
    }
    pending += ((connection, source))
  }

  private[backend] final def onClose(
    source: AnyRef,
    connection: WebSocket,
    code: Int,
    reason: String,
    remote: Boolean): Unit = synchronized {
    source match {
      case source: Client =>
        clients -= source
      case source: Node =>
        source.removeConnection(connection)
      // Remove node if node connections is empty, or?, should we ?
    }
  }

  private[backend] final def onMessage(
    source: AnyRef,
    connection: WebSocket,
    message: String): Unit = synchronized {
    if (closed)
      return
    onMessage(source, connection, deserializeJson(message))
  }

  private[backend] final def onMessage(
    source: AnyRef,
    connection: WebSocket,
    message: ByteBuffer): Unit = synchronized {
    if (closed)
      return
    onMessage(source, connection, deserializeBinary(message.array))
  }

  private[backend] final def onError(
    source: AnyRef,
    connection: WebSocket,
    error: Exception): Unit = synchronized {
    if (closed)
      return
    handleError(source, connection, error)
  }

  private[backend] final def onMessage(
    source: AnyRef,
    connection: WebSocket,
    message: MGenBase) {
    pending.get(connection) match {
      case Some(source) =>
        handleMsgForPendingConnection(source, connection, message)
      case _ =>
        handleMsgForClientOrNode(source, connection, message)
    }
  }

  private def mkLocalId(): NetworkId = {
    val uuid = UUID.randomUUID()
    new NetworkId(uuid.getLeastSignificantBits, uuid.getMostSignificantBits)
  }

  private def deserializeJson(msg: String): MGenBase = {
    jsonReader.readObject(msg)
  }

  private def deserializeBinary(msg: Array[Byte]): MGenBase = {
    binaryReader.setInput(new ByteArrayInputStream(msg)).readObject()
  }

  private def serializeJson(msg: MGenBase): String = {
    jsonWriter.writeObjectToString(msg)
  }

  private def serializeBinary(msg: MGenBase): Array[Byte] = {
    binaryWriter.writeObject(msg)
    val out = writeBuffer.toByteArray()
    writeBuffer.reset()
    out
  }
}