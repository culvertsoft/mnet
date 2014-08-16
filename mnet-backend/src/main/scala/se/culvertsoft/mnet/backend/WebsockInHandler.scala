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

class WebsockInHandler(
  handler: ConnectionConsolidator,
  addr: InetSocketAddress,
  useTcpNoDelay: Boolean) extends WebSocketServer(addr) {

  super.setWebSocketFactory(new DefaultWebSocketServerFactory() {

    override def createWebSocket(a: WebSocketAdapter, d: Draft, s: Socket): WebSocketImpl = {
      ConfigureSocket(s, useTcpNoDelay)
      super.createWebSocket(a, d, s)
    }

    override def createWebSocket(a: WebSocketAdapter, d: java.util.List[Draft], s: Socket): WebSocketImpl = {
      ConfigureSocket(s, useTcpNoDelay)
      super.createWebSocket(a, d, s)
    }

    override def wrapChannel(channel: SocketChannel, key: SelectionKey): SocketChannel = {
      if (channel != null)
        ConfigureSocket(channel.socket, useTcpNoDelay)
      super.wrapChannel(channel, key)
    }

  })

  private val serializer = new WebsockSerializer

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
    def send(msg: Message) {
      msg match {
        case msg: DataMessage if (msg.hasBinaryData()) => sendBinary(msg)
        case msg => sendJson(msg)
      }
    }
  }

}