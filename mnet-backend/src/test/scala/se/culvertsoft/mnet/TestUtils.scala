package se.culvertsoft.mnet

import se.culvertsoft.mnet.backend.BackendConfiguration
import se.culvertsoft.mnet.backend.Node
import se.culvertsoft.mnet.backend.Route
import se.culvertsoft.mnet.backend.WebSockProvider
import se.culvertsoft.mnet.backend.WebsockSerializer

object TestUtils {

  val serializer = new WebsockSerializer

  private var testPort = 80
  def getTestPort(): Int = synchronized {
    val out = testPort
    testPort += 1
    out
  }

  def getTestCfg(): BackendConfiguration = {
    new BackendConfiguration().setListenPort(getTestPort)
  }

  def newNode(msgHandler: Message => Unit = _ => Unit): Node = {
    val settings = getTestCfg
    new Node() {
      override def handleMessage(message: Message, route: Option[Route]) {
        msgHandler(message)
      }
    }.addRouteProvider(new WebSockProvider(settings))
  }

  def getTime(): Double = {
    System.nanoTime() / 1e9
  }

}