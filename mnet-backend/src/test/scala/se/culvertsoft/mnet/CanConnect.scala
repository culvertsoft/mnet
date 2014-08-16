package se.culvertsoft.mnet

import org.junit.Test

import TestUtils.assertWithin1sec
import TestUtils.serializer
import se.culvertsoft.mnet.backend.WebSockBackEnd
import se.culvertsoft.mnet.backend.util.ReconnectingWebsocket

class CanConnect {

  @Test
  def test() {

    val b = TestUtils.newNode(200)().start()
    val port = b.getBackEnd[WebSockBackEnd].listenPort

    @volatile var gotMsg: Message = null
    val ws = new ReconnectingWebsocket("127.0.0.1", port, true) {
      override def onTextMessage(jsonMsg: String) {
        gotMsg = serializer.deserializeJson(jsonMsg)
      }
      start()
    }

    assertWithin1sec(ws.isConnected)
    assertWithin1sec(gotMsg.isInstanceOf[NodeAnnouncement])
    Thread.sleep(100)
    ws.stop()
    Thread.sleep(100)
    b.stop()
    assertWithin1sec(ws.isDisconnected)
    assertWithin1sec(b.getRoutes.isEmpty)

  }

}