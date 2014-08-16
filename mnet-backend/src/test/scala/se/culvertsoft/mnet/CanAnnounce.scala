package se.culvertsoft.mnet

import org.junit.Test

import TestUtils.for01sec
import TestUtils.within1sec
import se.culvertsoft.mnet.backend.WebSockBackEnd

class CanAnnounce {

  @Test
  def canAnnounceOnBackend() {

    val b1 = TestUtils.newNode(300)().start()
    val b2 = TestUtils.newNode(301)().start()

    val ws1 = b1.getBackEnd[WebSockBackEnd]
    val ws2 = b2.getBackEnd[WebSockBackEnd]

    assert(for01sec(b1.getRoutes.isEmpty && b2.getRoutes.isEmpty))

    ws1.addOutboundConnection(ws2.listenPort)

    assert(within1sec(b1.getRoutes.nonEmpty && b2.getRoutes.nonEmpty))

    b2.stop()
    b1.stop()

  }

}