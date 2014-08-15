package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.net.URI

import scala.collection.JavaConversions.asScalaBuffer
import scala.collection.mutable.ArrayBuffer

class WebSockProvider(settings: BackendConfiguration) extends RouteProvider {

  // Kept so we can close them (they have slave threads)
  private val listeningIfcs = new ArrayBuffer[WebsockInHandler]
  private val connectingTo = new ArrayBuffer[WebsockOutHandler]

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  override def start(backEnd: NodeIfc) {
    if (listeningIfcs.nonEmpty)
      throw new RuntimeException("Tried to start BackEnd Twice!")

    if (settings.hasListeningInterfaces()) {
      ???
    } else {
      listeningIfcs += new WebsockInHandler(backEnd, new InetSocketAddress(settings.getPort))
      for (addr <- settings.getRemoteNodes)
        connectingTo += new WebsockOutHandler(backEnd, new URI(addr), 0)
    }

    listeningIfcs.foreach(_.start())
    connectingTo.foreach(_.start())

  }

  override def stop() {
    listeningIfcs.foreach(_.stop())
    connectingTo.foreach(_.stop())
  }

}