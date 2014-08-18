package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.net.Socket
import java.nio.ByteBuffer
import java.nio.channels.SelectionKey
import java.nio.channels.SocketChannel
import org.java_websocket.WebSocket
import org.java_websocket.WebSocketAdapter
import org.java_websocket.WebSocketImpl
import org.java_websocket.drafts.Draft
import org.java_websocket.handshake.ClientHandshake
import org.java_websocket.server.DefaultWebSocketServerFactory
import org.java_websocket.server.WebSocketServer
import se.culvertsoft.mnet.DataMessage
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.api.Connection
import se.culvertsoft.mnet.api.ConnectionConsolidator
import se.culvertsoft.mnet.backend.util.ConfigureSocket
import se.culvertsoft.mnet.backend.util.JavaWebSockFactories

class WebsockInHandler(
  handler: ConnectionConsolidator,
  addr: InetSocketAddress,
  useTcpNoDelay: Boolean) extends WebSocketServer(addr) {

  setWebSocketFactory(JavaWebSockFactories.getServerFactory(useTcpNoDelay))

  private val serializer = new WebsockSerializer

  override def onOpen(conn: WebSocket, handshake: ClientHandshake) {
    handler.onConnect(RichWebSock(conn))
  }

  override def onClose(conn: WebSocket, code: Int, reason: String, remote: Boolean) {
    handler.onDisconnect(reason, RichWebSock(conn))
  }

  override def onMessage(conn: WebSocket, jsonMsg: String) {
    handler.onMessage(serializer.deserializeJson(jsonMsg), RichWebSock(conn))
  }

  override def onMessage(conn: WebSocket, binaryMsg: ByteBuffer) {
    handler.onMessage(serializer.deserializeBinary(binaryMsg.array), RichWebSock(conn))
  }

  override def onError(conn: WebSocket, ex: Exception) {
    handler.onError(ex, RichWebSock(conn))
  }

  case class RichWebSock(socket: WebSocket) extends Connection {

    override def isConnected(): Boolean = socket.isOpen()
    
    override def hasBufferedData(): Boolean = socket.hasBufferedData()

    override def send(msg: Message) {
      msg match {
        case msg: DataMessage if (msg.hasBinaryData()) => sendBinary(msg)
        case msg => sendJson(msg)
      }
    }

    def sendJson(msg: Message) = synchronized { socket.send(serializer.serializeJson(msg)) }

    def sendBinary(msg: Message) = synchronized { socket.send(serializer.serializeBinary(msg)) }

  }

}