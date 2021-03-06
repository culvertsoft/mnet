package se.culvertsoft.mnet

import java.util.concurrent.ConcurrentLinkedQueue

import scala.collection.JavaConversions.asScalaBuffer
import scala.collection.mutable.ArrayBuffer

import org.junit.Test

import TestUtils.assertFor01sec
import TestUtils.assertWithin1sec
import TestUtils.getTime
import se.culvertsoft.mnet.backend.WebSockBackEnd

class CheckLatency {

  @Test
  def latencyCheck() {

    val b1Msgs = new ConcurrentLinkedQueue[Message]
    val b2Msgs = new ConcurrentLinkedQueue[Message]

    val b1 = TestUtils.newNode(1500)(b1Msgs.add(_)).start()
    val b2 = TestUtils.newNode(1501)(b2Msgs.add(_)).start()

    val ws1 = b1.getBackEnd[WebSockBackEnd]
    val ws2 = b2.getBackEnd[WebSockBackEnd]

    assertFor01sec(b1.getRoutes.isEmpty && b2.getRoutes.isEmpty)

    ws2.addOutboundConnection(ws1.listenPort)

    assertWithin1sec(b1.getRoutes.nonEmpty && b2.getRoutes.nonEmpty)

    val errMsgSentByB1 = new ErrorMessage().setMsg("ErrorFromB1")
    val errMsgSentByB2 = new ErrorMessage().setMsg("ErrorFromB2")

    val t00 = getTime
    var i = 0
    val n = 10000
    var nRecvd = 0
    while (i < n) {
      b2.broadcast(errMsgSentByB2)
      while (b1Msgs.isEmpty) {}
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

    b2.stop()
    b1.stop()

  }

}