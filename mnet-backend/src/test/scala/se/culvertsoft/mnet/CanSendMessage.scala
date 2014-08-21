package se.culvertsoft.mnet

import java.util.concurrent.ConcurrentLinkedQueue

import scala.collection.JavaConversions.asScalaBuffer

import org.junit.Test

import TestUtils.assertFor01sec
import TestUtils.assertWithin1sec
import se.culvertsoft.mnet.backend.WebSockBackEnd

class CanSendMessage {

  @Test
  def canSendEachOtherMessages() {

    val b1Msgs = new ConcurrentLinkedQueue[Message]
    val b2Msgs = new ConcurrentLinkedQueue[Message]

    val b1 = TestUtils.newNode(1400)(b1Msgs.add).start()
    val b2 = TestUtils.newNode(1401)(b2Msgs.add).start()

    val ws1 = b1.getBackEnd[WebSockBackEnd]
    val ws2 = b2.getBackEnd[WebSockBackEnd]

    assertFor01sec(b2.getRoutes.isEmpty && b2.getRoutes.isEmpty)

    ws1.addOutboundConnection(ws2.listenPort)

    assertWithin1sec(b1.getRoutes.nonEmpty && b2.getRoutes.nonEmpty)

    val errMsgSentByB1 = new ErrorMessage().setMsg("ErrorFromB1")
    val errMsgSentByB2 = new ErrorMessage().setMsg("ErrorFromB2")

    b1.broadcast(errMsgSentByB1)
    b2.broadcast(errMsgSentByB2)

    assertWithin1sec(b1Msgs.size == 1 && b2Msgs.size == 1)

    b2.stop()
    b1.stop()
  }

}