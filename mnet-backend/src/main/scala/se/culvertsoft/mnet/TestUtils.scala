package se.culvertsoft.mnet

import se.culvertsoft.mnet.api.Connection
import se.culvertsoft.mnet.api.Node
import se.culvertsoft.mnet.api.Route
import se.culvertsoft.mnet.backend.WebSockBackEnd
import se.culvertsoft.mnet.backend.WebsockBackendSettings
import se.culvertsoft.mnet.backend.WebsockSerializer

object TestUtils {

  val serializer = new WebsockSerializer

  def getTestCfg(port: Int): WebsockBackendSettings = {
    new WebsockBackendSettings().setListenPort(port)
  }

  def newNode(port: Int)(msgHandler: Message => Unit = _ => Unit): Node = {
    val settings = getTestCfg(port)
    new Node() {
      override def handleMessage(message: Message, from: Connection, route: Route) {
        msgHandler(message)
      }
    }.addBackEnd(new WebSockBackEnd(settings))
  }

  def getTime(): Double = {
    System.nanoTime() / 1e9
  }

  def within(tMax: Double)(f: => Boolean): Boolean = {
    val t0 = getTime
    while (!f) {
      if (getTime - t0 > tMax)
        return false
    }
    true
  }

  def within1sec(f: => Boolean): Boolean = {
    within(1)(f)
  }

  def forT(t: Double)(f: => Boolean): Boolean = {
    val t0 = getTime
    while (getTime < t0 + t) {
      if (!f)
        return false
    }
    true
  }

  def for1sec(f: => Boolean): Boolean = {
    forT(1)(f)
  }

  def for01sec(f: => Boolean): Boolean = {
    forT(0.1)(f)
  }

  def assertWithin1sec(f: => Boolean) {
    assert(within(1)(f))
  }

  def assertWithin2sec(f: => Boolean) {
    assert(within(2)(f))
  }

  def assertFor1sec(f: => Boolean) {
    assert(forT(1)(f))
  }

  def assertFor01sec(f: => Boolean) {
    assert(forT(0.1)(f))
  }

}