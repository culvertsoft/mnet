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

import se.culvertsoft.mnet.Message

class WebsockInHandler(
  backEnd: NodeCallbackIfc,
  addr: InetSocketAddress,
  useTcpNoDelay: Boolean) extends WebSocketServer(addr) {

  if (useTcpNoDelay) {
    super.setWebSocketFactory(new DefaultWebSocketServerFactory() {

      override def createWebSocket(a: WebSocketAdapter, d: Draft, s: Socket): WebSocketImpl = {
        if (s != null)
          s.setTcpNoDelay(true)
        super.createWebSocket(a, d, s)
      }

      override def createWebSocket(a: WebSocketAdapter, d: java.util.List[Draft], s: Socket): WebSocketImpl = {
        if (s != null)
          s.setTcpNoDelay(true)
        super.createWebSocket(a, d, s)
      }

      override def wrapChannel(channel: SocketChannel, key: SelectionKey): SocketChannel = {
        if (channel != null && channel.socket() != null)
          channel.socket.setTcpNoDelay(true)
        super.wrapChannel(channel, key)
      }

    })
  }

  private val serializer = new WebsockSerializer
  private val handler = new ConnectionHandler(backEnd)

  override def onOpen(conn: WebSocket, handshake: ClientHandshake) {
    handler.onConnect(RichWebSock(conn))
  }

  override def onClose(conn: WebSocket, code: Int, reason: String, remote: Boolean) {
    handler.onDisconnect(reason, RichWebSock(conn))
  }

  override def onMessage(conn: WebSocket, jsonMsg: String) {
    handler.onMessage(RichWebSock(conn), serializer.deserializeJson(jsonMsg))
  }

  override def onMessage(conn: WebSocket, binaryMsg: ByteBuffer) {
    handler.onMessage(RichWebSock(conn), serializer.deserializeBinary(binaryMsg.array))
  }

  override def onError(conn: WebSocket, ex: Exception) {
    handler.onError(ex, RichWebSock(conn))
  }

  case class RichWebSock(socket: WebSocket) extends Connection {
    def sendJson(msg: Message) = synchronized { socket.send(serializer.serializeJson(msg)) }
    def sendBinary(msg: Message) = synchronized { socket.send(serializer.serializeBinary(msg)) }
  }

}