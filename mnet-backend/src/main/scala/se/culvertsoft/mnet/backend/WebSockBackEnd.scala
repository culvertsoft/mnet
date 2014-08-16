package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.net.URI

import scala.collection.JavaConversions.asScalaBuffer
import scala.collection.mutable.ArrayBuffer

import se.culvertsoft.mnet.api.BackEnd
import se.culvertsoft.mnet.api.ConnectionConsolidator

class WebSockBackEnd(_settings: WebsockBackendSettings) extends BackEnd {
  val settings = _settings.deepCopy()

  private var connectionHandler: ConnectionConsolidator = null
  private val listeningIfcs = new ArrayBuffer[WebsockInHandler]
  private val connectingTo = new ArrayBuffer[WebsockOutHandler]

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  override def start(handler_in: ConnectionConsolidator) {
    if (connectionHandler != null)
      throw new RuntimeException("Tried to start BackEnd Twice!")
    connectionHandler = handler_in

    if (settings.hasListenPort())
      listeningIfcs += new WebsockInHandler(connectionHandler, new InetSocketAddress(settings.getListenPort), settings.getUseTcpNodelay)

    for (addr <- settings.getConnectTo)
      connectingTo += new WebsockOutHandler(connectionHandler, new URI(addr), settings.getUseTcpNodelay(), 0)

    listeningIfcs.foreach(_.start())
    connectingTo.foreach(_.start())

  }

  override def stop() {
    connectingTo.foreach(_.stop())
    listeningIfcs.foreach(_.stop())
  }

  def listenPort(): Int = {
    settings.getListenPort()
  }

  def addOutboundConnection(uri: String) {
    if (connectionHandler != null) {
      val handler = new WebsockOutHandler(connectionHandler, new URI(uri), settings.getUseTcpNodelay(), 0)
      connectingTo += handler
      handler.start()
    } else {
      settings.getConnectTo().add(uri)
    }
  }

  def addOutboundConnection(addr: String, port: Int) {
    addOutboundConnection(s"ws://$addr:$port")
  }

  def addOutboundConnection(port: Int) {
    addOutboundConnection("127.0.0.1", port)
  }

}