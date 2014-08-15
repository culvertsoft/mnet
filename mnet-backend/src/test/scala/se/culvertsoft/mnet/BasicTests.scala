package se.culvertsoft.mnet

import scala.collection.mutable.ArrayBuffer
import org.junit.Test
import TestUtils.getTime
import TestUtils.serializer
import se.culvertsoft.mnet.api.ReconnectingWebsocket
import se.culvertsoft.mnet.backend.WebSockProvider
import junit.framework.TestFailure
import java.util.concurrent.ConcurrentLinkedQueue

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
    
    b2.stop()
    b1.stop()

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

    b2.stop()
    b1.stop()
  }

  @Test
  def latencyCheck() {

    val b1Msgs = new ConcurrentLinkedQueue[Message]
    val b2Msgs = new ArrayBuffer[Message]

    val b1 = TestUtils.newNode(b1Msgs.add(_)).start()
    val b2 = TestUtils.newNode(b2Msgs += _).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]

    Thread.sleep(100)

    assert(b1.viewRoutes.isEmpty)
    assert(b2.viewRoutes.isEmpty)

    ws2.addOutboundConnection(ws1.listenPort)

    Thread.sleep(100)

    assert(b1.viewRoutes.nonEmpty)
    assert(b2.viewRoutes.nonEmpty)

    val errMsgSentByB1 = new ErrorMessage().setMsg("ErrorFromB1")
    val errMsgSentByB2 = new ErrorMessage().setMsg("ErrorFromB2")

    val t00 = getTime
    var i = 0
    val n = 100000
    var nRecvd = 0
    while (i < n) {
      val t0 = getTime
      b2.broadcastJson(errMsgSentByB2)
      while (b1Msgs.isEmpty) {
        if (getTime - t0 > 0.1)
          throw new RuntimeException("Latency test crashed or deadlocked")
      }
      nRecvd += 1
      b1Msgs.clear()
      i += 1
    }

    val nBytes = errMsgSentByB1.toString().size.toLong * n.toLong
    val dt = getTime - t00
    val bits = nBytes.toLong * 8L
    val mbits = bits / 1024 / 1024
    val mbits_per_sec = mbits.toDouble / dt
    val msgs_per_sec = n.toDouble / dt

    assert(msgs_per_sec > 5000)

    assert(n == nRecvd)

    Thread.sleep(100)

    b2.stop()
    b1.stop()
  }
  
}