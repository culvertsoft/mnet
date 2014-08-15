package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.nio.ByteBuffer
import org.java_websocket.WebSocket
import org.java_websocket.handshake.ClientHandshake
import org.java_websocket.server.WebSocketServer
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeUUID

class WebsockInHandler(
  backEnd: NodeIfc,
  addr: InetSocketAddress) extends WebSocketServer(addr) {

  private val serializer = new WebsockSerializer
  private val handler = new ConnectionHandler(backEnd)

  override def onOpen(conn: WebSocket, handshake: ClientHandshake) {
    handler.onConnect(conn)
  }

  override def onClose(conn: WebSocket, code: Int, reason: String, remote: Boolean) {
    handler.onDisconnect(conn, reason)
  }

  override def onMessage(conn: WebSocket, jsonMsg: String) {
    handler.onMessage(conn, serializer.deserializeJson(jsonMsg))
  }

  override def onMessage(conn: WebSocket, binaryMsg: ByteBuffer) {
    handler.onMessage(conn, serializer.deserializeBinary(binaryMsg.array))
  }

  override def onError(conn: WebSocket, ex: Exception) {
    handler.onError(conn, ex)
  }

  implicit class RichWebSock(socket: WebSocket) extends Connection {
    def sendJson(msg: Message) = synchronized { socket.send(serializer.serializeJson(msg)) }
    def sendBinary(msg: Message) = synchronized { socket.send(serializer.serializeBinary(msg)) }
  }

}