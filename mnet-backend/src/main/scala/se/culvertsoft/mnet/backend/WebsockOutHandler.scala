package se.culvertsoft.mnet.backend

import java.net.URI
import java.nio.ByteBuffer

import se.culvertsoft.mnet.DataMessage
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.api.Connection
import se.culvertsoft.mnet.api.ConnectionConsolidator
import se.culvertsoft.mnet.backend.util.ReconnectingWebsocket

class WebsockOutHandler(
  handler: ConnectionConsolidator,
  uri: URI,
  useTcpNoDelay: Boolean,
  timeout: Int)
  extends ReconnectingWebsocket(uri, useTcpNoDelay, timeout)
  with Connection {

  private val serializer = new WebsockSerializer

  override def onConnecting() {
  }

  override def onConnect() {
    handler.onConnect(this)
  }

  override def onDisconnect(
    code: Int,
    reason: String,
    remote: Boolean) {
    handler.onDisconnect(reason, this)
  }

  override def onTextMessage(msg: String) {
    handler.onMessage(this, serializer.deserializeJson(msg))
  }

  override def onBinaryMessage(msg: ByteBuffer) {
    handler.onMessage(this, serializer.deserializeBinary(msg.array))
  }

  override def onError(error: Exception) {
    handler.onError(error, this)
  }

  def sendJson(msg: Message) = synchronized {
    sendTextMessage(serializer.serializeJson(msg))
  }

  def sendBinary(msg: Message) = synchronized {
    sendBinaryMessage(serializer.serializeBinary(msg))
  }

  def send(msg: Message) {
    msg match {
      case msg: DataMessage if (msg.hasBinaryData()) => sendBinary(msg)
      case msg => sendJson(msg)
    }
  }

}