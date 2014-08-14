package se.culvertsoft.mnet

import org.junit.Test

import se.culvertsoft.mnet.api.ReconnectingWebsocket
import se.culvertsoft.mnet.backend.BackEnd
import se.culvertsoft.mnet.backend.BackendConfiguration

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
}

class TestBackend {
  import TestBackend._

  @Test
  def canCreateBackend() {
    val b = new BackEnd(getTestCfg)
  }

  @Test
  def canCloseBackend() {
    val b = new BackEnd(getTestCfg).start()
    Thread.sleep(100)
    b.close()
    Thread.sleep(100)
  }

  @Test
  def canConnectToBackend() {

    val b = new BackEnd(getTestCfg).start()
    val ws = new ReconnectingWebsocket("localhost", b.port).start()

    Thread.sleep(500)
    assert(ws.isConnected)
    ws.close()
    b.close()
    Thread.sleep(100)
    assert(ws.isDisconnected)

  }

}