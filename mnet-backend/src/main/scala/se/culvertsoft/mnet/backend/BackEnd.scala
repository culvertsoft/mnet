package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.nio.ByteBuffer

import scala.collection.JavaConversions.asScalaBuffer
import scala.collection.mutable.ArrayBuffer

import org.java_websocket.WebSocket
import org.java_websocket.handshake.ClientHandshake

class BackEnd(settings: BackendConfiguration) {

  val port = settings.getPort()
  val listeningIfcs = new ArrayBuffer[ListeningIfc]
  val outboundNodes = new ArrayBuffer[OutboundNode]
  val inboundNodes = new ArrayBuffer[InboundNode]
  val clients = new ArrayBuffer[Client]
  val pending = new ArrayBuffer[WebSocket]

  def start() {
    if (listeningIfcs.nonEmpty)
      throw new RuntimeException("Tried to start BackEnd Twice!")

    if (settings.hasListeningInterfaces()) {
      ???
    } else {
      listeningIfcs += new ListeningIfc(this, new InetSocketAddress(port))
    }

    listeningIfcs.foreach(_.start())

    for (addr <- settings.getRemoteNodes) {
      outboundNodes += new OutboundNode(addr, this)
    }
  }

  /**
   * **********************************************
   * These may be called from virtually any thread.
   * We'll collect all calls here
   * **********************************************
   */

  def onOpen(
    sourceType: SourceType,
    connection: WebSocket,
    handshake: ClientHandshake): Unit = synchronized {
  }

  def onClose(
    sourceType: SourceType,
    connection: WebSocket,
    code: Int,
    reason: String,
    remote: Boolean): Unit = synchronized {
  }

  def onMessage(
    sourceType: SourceType,
    connection: WebSocket,
    message: String): Unit = synchronized {
  }

  def onMessage(
    sourceType: SourceType,
    connection: WebSocket,
    message: ByteBuffer): Unit = synchronized {
  }

  def onError(
    sourceType: SourceType,
    connection: WebSocket,
    error: Exception): Unit = synchronized {
  }

}