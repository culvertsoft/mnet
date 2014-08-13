package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.nio.ByteBuffer

import scala.collection.mutable.ArrayBuffer

import org.java_websocket.WebSocket
import org.java_websocket.handshake.ClientHandshake

object BackEnd {

  val DEFAULT_PORT = 6537

  def main(args: Array[String]) {
    //TODO: Parse args...maybe just a config file name?
    val settings = new BackendConfiguration
    new BackEnd(settings).start()
  }

}

class BackEnd(settings: BackendConfiguration) {
  val port = if (settings.hasPort) settings.getPort else BackEnd.DEFAULT_PORT
  val servers = new ArrayBuffer[Server]

  def start() {
    if (servers.nonEmpty)
      throw new RuntimeException("Tried to start BackEnd Twice!")

    if (settings.hasListeningInterfaces()) {
      ???
    } else {
      servers += new Server(this, new InetSocketAddress(port))
    }

    servers.foreach(_.start())
  }

  def onOpen(
    server: Server,
    connection: WebSocket,
    handshake: ClientHandshake) {
  }

  def onClose(
    server: Server,
    connection: WebSocket,
    code: Int,
    reason: String,
    remote: Boolean) {
  }

  def onMessage(
    server: Server,
    connection: WebSocket,
    message: String) {
  }

  def onMessage(
    server: Server,
    connection: WebSocket,
    message: ByteBuffer) {
  }

  def onError(
    server: Server,
    connection: WebSocket,
    error: Exception) {
  }

}