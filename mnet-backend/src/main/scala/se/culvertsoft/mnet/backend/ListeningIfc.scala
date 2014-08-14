package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.nio.ByteBuffer

import org.java_websocket.WebSocket
import org.java_websocket.handshake.ClientHandshake
import org.java_websocket.server.WebSocketServer

class ListeningIfc(
  parent: BackEnd,
  addr: InetSocketAddress) extends WebSocketServer(addr) {

  override def onOpen(conn: WebSocket, handshake: ClientHandshake) {
    parent.onOpen(SourceNode, conn, handshake)
  }

  override def onClose(conn: WebSocket, code: Int, reason: String, remote: Boolean) {
    parent.onClose(SourceNode, conn, code, reason, remote)
  }

  override def onMessage(conn: WebSocket, message: String) {
    parent.onMessage(SourceNode, conn, message)
  }

  override def onMessage(conn: WebSocket, message: ByteBuffer) {
    parent.onMessage(SourceNode, conn, message)
  }

  override def onError(conn: WebSocket, ex: Exception) {
    parent.onError(SourceNode, conn, ex)
  }
}