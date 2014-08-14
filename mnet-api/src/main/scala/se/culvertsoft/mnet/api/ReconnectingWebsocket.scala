package se.culvertsoft.mnet.api

import java.net.URI
import java.nio.ByteBuffer

import org.java_websocket.client.WebSocketClient
import org.java_websocket.drafts.Draft_10
import org.java_websocket.handshake.ServerHandshake

class ReconnectingWebsocket(
  val serverUri: URI,
  val timeout: Int = 0) {

  /**
   * *********************************
   *
   *
   * 		PUBLIC API
   *
   * *******************************
   */

  final def status() = {
    m_status
  }

  final def isConnected() = {
    status == Connected
  }

  final def isConnecting() = {
    status == Connecting
  }

  final def isDisconnected() = {
    status == Disconnected
  }

  final def start() = {
    m_thread.start()
    this
  }

  final def close() = {
    m_toLive = false
    this
  }

  final def forceReconnect() {
    if (!isDisconnected)
      m_forceReconnect = true
  }

  final def sendTextMessage(msg: String) {
    if (isConnected)
      m_currentWebsocket.send(msg)
  }

  final def sendBinaryMessage(msg: Array[Byte]) {
    if (isConnected)
      m_currentWebsocket.send(msg)
  }

  /**
   * **************************
   * 	Overrideable callbacks
   * **************************
   */

  def onConnecting() {
    println(s"$this connecting to $serverUri")
  }

  def onConnect() {
    println(s"$this connected to $serverUri")
  }

  def onDisconnect(
    code: Int,
    reason: String,
    remote: Boolean) {
    println(s"$this disconnected from $serverUri")
  }

  def onTextMessage(message: String) {
    println(s"$this got text message '$message' from $serverUri")
  }

  def onBinaryMessage(
    message: ByteBuffer) {
    println(s"$this got binary message of size ${message.remaining}  from $serverUri")
  }

  def onError(error: Exception) {
    println(s"$this got had error $error while $m_status to/from $serverUri")
  }

  /**
   * *********************************
   *
   *
   * 		INTERNALS
   *
   * *******************************
   */

  @volatile private var m_currentWebsocket: WebSocketClient = null
  @volatile private var m_forceReconnect = false
  @volatile private var m_toLive = false
  @volatile private var m_status: ConnectionStatus = Disconnected

  private val m_thread = new Thread {
    override def run() {
      while (m_toLive) {
        m_status match {
          case Disconnected => reconnect()
          case _ if (m_forceReconnect) => reconnect()
          case _ =>
        }
        Thread.sleep(1000)
      }
      m_currentWebsocket.close()
    }
  }

  private def reconnect() {

    m_forceReconnect = false

    if (!isDisconnected)
      m_currentWebsocket.close()

    m_status = Connecting
    m_currentWebsocket = new WebSocketClient(serverUri, new Draft_10, null, timeout) {

      override def onOpen(handshakedata: ServerHandshake) {
        m_status = Connected
        ReconnectingWebsocket.this.onConnect()
      }
      override def onMessage(message: String) {
        ReconnectingWebsocket.this.onTextMessage(message)
      }
      override def onClose(code: Int, reason: String, remote: Boolean) {
        m_status = Disconnected
        ReconnectingWebsocket.this.onDisconnect(code, reason, remote)
      }
      override def onError(error: Exception) {
        ReconnectingWebsocket.this.onError(error)
      }
      override def onMessage(bytes: ByteBuffer) {
        ReconnectingWebsocket.this.onBinaryMessage(bytes)
      }

    }
    onConnecting()
    m_currentWebsocket.connect()

  }

}