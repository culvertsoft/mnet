package se.culvertsoft.mnet

import java.util.concurrent.ConcurrentLinkedQueue

import org.junit.Test

import TestUtils.within
import se.culvertsoft.mnet.backend.WebSockProvider

class RoutingTests {

  @Test
  def threeInARow() {

    val b1Msgs = new ConcurrentLinkedQueue[Message]
    val b2Msgs = new ConcurrentLinkedQueue[Message]
    val b3Msgs = new ConcurrentLinkedQueue[Message]

    val b1 = TestUtils.newNode(b1Msgs.add(_)).start()
    val b2 = TestUtils.newNode(b2Msgs.add(_)).start()
    val b3 = TestUtils.newNode(b3Msgs.add(_)).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]
    val ws3 = b3.getProvider[WebSockProvider]

    ws1.addOutboundConnection(ws2.listenPort)
    ws3.addOutboundConnection(ws2.listenPort)

    assert(within(b1.viewRoutes.size == 2, 0.5))
    assert(within(b2.viewRoutes.size == 2, 1.5))
    assert(within(b3.viewRoutes.size == 2, 0.5))

    b3.stop()
    b2.stop()
    b1.stop()

  }

}