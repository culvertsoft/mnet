package se.culvertsoft.mnet

import scala.collection.mutable.ArrayBuffer

import org.junit.Test

import TestUtils.assertFor01sec
import TestUtils.assertWithin1sec
import se.culvertsoft.mnet.backend.WebSockProvider

class CanSendMessage {

  @Test
  def canSendEachOtherMessages() {

    val b1Msgs = new ArrayBuffer[Message]
    val b2Msgs = new ArrayBuffer[Message]

    val b1 = TestUtils.newNode(400)(b1Msgs += _).start()
    val b2 = TestUtils.newNode(401)(b2Msgs += _).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]

    assertFor01sec(b2.getRoutes.isEmpty && b2.getRoutes.isEmpty)

    ws1.addOutboundConnection(ws2.listenPort)

    assertWithin1sec(b1.getRoutes.nonEmpty && b2.getRoutes.nonEmpty)

    val errMsgSentByB1 = new ErrorMessage().setMsg("ErrorFromB1")
    val errMsgSentByB2 = new ErrorMessage().setMsg("ErrorFromB2")

    b1.broadcastJson(errMsgSentByB1)
    b2.broadcastJson(errMsgSentByB2)

    assertWithin1sec(b1Msgs.size == 1 && b2Msgs.size == 1)

    b2.stop()
    b1.stop()
  }

}