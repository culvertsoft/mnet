package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.net.URI

import scala.collection.JavaConversions.asScalaBuffer
import scala.collection.mutable.ArrayBuffer

class WebSockProvider(_settings: BackendConfiguration) extends RouteProvider {
  val settings = _settings.deepCopy()

  // Kept so we can close them (they have slave threads)
  private var backEnd: NodeIfc = null
  private val listeningIfcs = new ArrayBuffer[WebsockInHandler]
  private val connectingTo = new ArrayBuffer[WebsockOutHandler]

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  override def start(_backEnd: NodeIfc) {
    if (backEnd != null)
      throw new RuntimeException("Tried to start BackEnd Twice!")
    backEnd = _backEnd

    if (settings.hasListenPort())
      listeningIfcs += new WebsockInHandler(backEnd, new InetSocketAddress(settings.getListenPort()))

    for (addr <- settings.getConnectTo)
      connectingTo += new WebsockOutHandler(backEnd, new URI(addr), 0)

    listeningIfcs.foreach(_.start())
    connectingTo.foreach(_.start())

  }

  override def stop() {
    listeningIfcs.foreach(_.stop())
    connectingTo.foreach(_.stop())
  }

  def listenPort(): Int = {
    settings.getListenPort()
  }

  def addOutboundConnection(uri: String) {
    if (backEnd != null) {
      val handler = new WebsockOutHandler(backEnd, new URI(uri), 0)
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