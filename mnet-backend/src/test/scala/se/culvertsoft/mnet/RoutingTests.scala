package se.culvertsoft.mnet

import java.util.concurrent.ConcurrentLinkedQueue

import org.junit.Test

import TestUtils._
import se.culvertsoft.mnet.backend.WebSockProvider

class RoutingTests {

  @Test
  def threeInARow() {

    val b1Msgs = new ConcurrentLinkedQueue[Message]
    val b2Msgs = new ConcurrentLinkedQueue[Message]
    val b3Msgs = new ConcurrentLinkedQueue[Message]

    val b1 = TestUtils.newNode(1100)(b1Msgs.add(_)).start()
    val b2 = TestUtils.newNode(1101)(b2Msgs.add(_)).start()
    val b3 = TestUtils.newNode(1102)(b3Msgs.add(_)).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]
    val ws3 = b3.getProvider[WebSockProvider]

    ws3.addOutboundConnection(ws2.listenPort)
    ws1.addOutboundConnection(ws2.listenPort)

    assertWithin1sec(b1.getRoutes.size == 2)
    assertWithin1sec(b2.getRoutes.size == 2)
    assertWithin1sec(b3.getRoutes.size == 2)

    b3.stop()
    b2.stop()
    b1.stop()

  }

}