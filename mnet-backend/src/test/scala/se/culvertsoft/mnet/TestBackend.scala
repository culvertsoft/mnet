package se.culvertsoft.mnet

import org.junit.Test
import se.culvertsoft.mnet.api.ReconnectingWebsocket
import se.culvertsoft.mnet.backend.BackendConfiguration
import se.culvertsoft.mnet.backend.Node
import se.culvertsoft.mnet.backend.WebSockProvider

object TestBackend {

  private var testPort = 80
  def getTestPort(): Int = synchronized {
    val out = testPort
    testPort += 1
    out
  }

  def getTestCfg(): BackendConfiguration = {
    new BackendConfiguration().setPort(getTestPort)
  }
  
  def newNode(): Node = {
    val settings = getTestCfg
    new Node(settings).addRouteProvider(new WebSockProvider(settings))
  }
  
}

class TestBackend {
  import TestBackend._

  @Test
  def canCreateNode() {
    val b = TestBackend.newNode()
  }

  @Test
  def canCloseBackend() {
    val b = TestBackend.newNode().start()
    Thread.sleep(100)
    b.stop()
    Thread.sleep(100)
  }

  @Test
  def canConnectToBackend() {

    val b = TestBackend.newNode().start()
    val ws = new ReconnectingWebsocket("localhost", b.port).start()

    Thread.sleep(500)
    assert(ws.isConnected)
    ws.stop()
    b.stop()
    Thread.sleep(100)
    assert(ws.isDisconnected)

  }

}