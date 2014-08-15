package se.culvertsoft.mnet

import scala.collection.mutable.ArrayBuffer

import org.junit.Test

import TestUtils.getTime
import TestUtils.serializer
import se.culvertsoft.mnet.api.ReconnectingWebsocket
import se.culvertsoft.mnet.backend.WebSockProvider

class BasicTests {

  @Test
  def canCreateNode() {
    val b = TestUtils.newNode()
  }

  @Test
  def canCloseBackend() {
    val b = TestUtils.newNode().start()
    Thread.sleep(100)
    b.stop()
    Thread.sleep(100)
  }

  @Test
  def canConnectToBackend() {

    val b = TestUtils.newNode().start()
    val port = b.getProvider[WebSockProvider].listenPort

    @volatile var gotMsg: Message = null

    val ws = new ReconnectingWebsocket("localhost", port) {
      override def onTextMessage(jsonMsg: String) {
        gotMsg = serializer.deserializeJson(jsonMsg)
      }
    }.start()

    Thread.sleep(500)
    assert(ws.isConnected)
    ws.stop()
    b.stop()
    Thread.sleep(100)
    assert(ws.isDisconnected)
    assert(gotMsg.isInstanceOf[NodeAnnouncement])

  }

  @Test
  def canAnnounceOnBackend() {

    val b1 = TestUtils.newNode().start()
    val b2 = TestUtils.newNode().start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]

    Thread.sleep(100)

    assert(b1.viewRoutes.isEmpty)
    assert(b2.viewRoutes.isEmpty)

    ws1.addOutboundConnection(ws2.listenPort)

    Thread.sleep(100)

    assert(b1.viewRoutes.nonEmpty)
    assert(b2.viewRoutes.nonEmpty)

  }

  @Test
  def canSendEachOtherMessages() {

    val b1Msgs = new ArrayBuffer[Message]
    val b2Msgs = new ArrayBuffer[Message]

    val b1 = TestUtils.newNode(b1Msgs += _).start()
    val b2 = TestUtils.newNode(b2Msgs += _).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]

    Thread.sleep(100)

    assert(b1.viewRoutes.isEmpty)
    assert(b2.viewRoutes.isEmpty)

    ws1.addOutboundConnection(ws2.listenPort)

    Thread.sleep(100)

    assert(b1.viewRoutes.nonEmpty)
    assert(b2.viewRoutes.nonEmpty)

    val errMsgSentByB1 = new ErrorMessage().setMsg("ErrorFromB1")
    val errMsgSentByB2 = new ErrorMessage().setMsg("ErrorFromB2")

    b1.broadcastJson(errMsgSentByB1)
    b2.broadcastJson(errMsgSentByB2)

    Thread.sleep(100)

    assert(b1Msgs.size == 1)
    assert(b2Msgs.size == 1)

  }

  @Test
  def latencyCheck() {

    val b1Msgs = new ArrayBuffer[Message]
    val b2Msgs = new ArrayBuffer[Message]

    val b1 = TestUtils.newNode(b1Msgs += _).start()
    val b2 = TestUtils.newNode(b2Msgs += _).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]

    Thread.sleep(100)

    assert(b1.viewRoutes.isEmpty)
    assert(b2.viewRoutes.isEmpty)

    ws1.addOutboundConnection(ws2.listenPort)

    Thread.sleep(100)

    assert(b1.viewRoutes.nonEmpty)
    assert(b2.viewRoutes.nonEmpty)

    val errMsgSentByB1 = new ErrorMessage().setMsg("ErrorFromB1")
    val errMsgSentByB2 = new ErrorMessage().setMsg("ErrorFromB2")

    val t0 = getTime
    def dt() = getTime - t0
    b1.broadcastJson(errMsgSentByB1)
    b2.broadcastJson(errMsgSentByB2)

    while (b1Msgs.isEmpty && dt < 1.0) {}

    println(getTime - t0)

    Thread.sleep(100)

    assert(b1Msgs.size == 1)
    assert(b2Msgs.size == 1)

  }
}