package se.culvertsoft.mnet.backend.util

import java.net.Socket
import java.nio.channels.ByteChannel
import java.nio.channels.SelectionKey
import java.nio.channels.SocketChannel
import org.java_websocket.WebSocket
import org.java_websocket.WebSocketAdapter
import org.java_websocket.client.DefaultWebSocketClientFactory
import org.java_websocket.client.WebSocketClient
import org.java_websocket.drafts.Draft
import org.java_websocket.server.DefaultWebSocketServerFactory
import org.java_websocket.WebSocketImpl

object JavaWebSockFactories {

  def getClientFactory(client: WebSocketClient, useTcpNoDelay: Boolean): DefaultWebSocketClientFactory = {
    new DefaultWebSocketClientFactory(client) {

      override def createWebSocket(a: WebSocketAdapter, d: Draft, s: Socket): WebSocket = {
        ConfigureSocket(s, useTcpNoDelay)
        super.createWebSocket(a, d, s)
      }

      override def createWebSocket(a: WebSocketAdapter, d: java.util.List[Draft], s: Socket): WebSocket = {
        ConfigureSocket(s, useTcpNoDelay)
        super.createWebSocket(a, d, s)
      }

      override def wrapChannel(channel: SocketChannel, c: SelectionKey, host: String, port: Int): ByteChannel = {
        if (channel != null)
          ConfigureSocket(channel.socket, useTcpNoDelay)
        super.wrapChannel(channel, c, host, port)
      }
    }
  }

  def getServerFactory(useTcpNoDelay: Boolean): DefaultWebSocketServerFactory = {
    new DefaultWebSocketServerFactory() {

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

    }
  }

}

