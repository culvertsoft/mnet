package se.culvertsoft.mnet

import scala.collection.mutable.ArrayBuffer
import org.junit.Test
import TestUtils.assertWithin1sec
import se.culvertsoft.mnet.backend.Node
import se.culvertsoft.mnet.backend.WebSockProvider
import java.util.concurrent.ConcurrentLinkedQueue
import scala.collection.JavaConversions._

class RoutingTests {

  @Test
  def manyToOne() {

    val n = 20
    val nodes = new ArrayBuffer[Node]
    val portMaker = new PortMaker(1100)

    val firstNode = TestUtils
      .newNode(portMaker.nextPort)()
      .start()

    val tgtPort = firstNode.getProvider[WebSockProvider].listenPort

    for (i <- 0 until n) {
      val node = TestUtils
        .newNode(portMaker.nextPort)()
        .start()
      nodes += node
    }

    for (node <- nodes) {
      if (node != firstNode) {
        val myProvider = node.getProvider[WebSockProvider]
        myProvider.addOutboundConnection(tgtPort)
      }
    }

    assertWithin1sec(nodes.forall(_.getRoutes.size == n))

  }

  @Test
  def oneToMany() {

    val n = 20
    val nodes = new ArrayBuffer[Node]
    val portMaker = new PortMaker(1200)

    val firstNode = TestUtils
      .newNode(portMaker.nextPort)()
      .start()

    for (i <- 0 until n) {
      val node = TestUtils
        .newNode(portMaker.nextPort)()
        .start()
      nodes += node
    }

    for (node <- nodes) {
      if (node != firstNode) {
        val tgtPort = node.getProvider[WebSockProvider].listenPort
        val myProvider = firstNode.getProvider[WebSockProvider]
        myProvider.addOutboundConnection(tgtPort)
      }
    }

    assertWithin1sec(nodes.forall(_.getRoutes.size == n))

  }

  @Test
  def bridged() {

    val portMaker = new PortMaker(1300)

    val leftMost = TestUtils.newNode(portMaker.nextPort)().start()
    val leftCenter = TestUtils.newNode(portMaker.nextPort)().start()
    val rightCenter = TestUtils.newNode(portMaker.nextPort)().start()
    val rightMost = TestUtils.newNode(portMaker.nextPort)().start()

    bridge(leftMost, leftCenter)
    bridge(leftCenter, rightCenter)
    bridge(rightCenter, rightMost)

    assertWithin1sec(leftMost.getRoutes.size == 3)
    assertWithin1sec(leftCenter.getRoutes.size == 3)
    assertWithin1sec(rightCenter.getRoutes.size == 3)

  }
 @Test
  def bridgedMessaging() {

    val portMaker = new PortMaker(1400)
    
    val leftMostCollect = new ConcurrentLinkedQueue[Message]
    val leftCenterCollect = new ConcurrentLinkedQueue[Message]
    val rightCenterCollect = new ConcurrentLinkedQueue[Message]
    val rightMostCollect = new ConcurrentLinkedQueue[Message]

    val leftMost = TestUtils.newNode(portMaker.nextPort)(leftMostCollect.add(_)).start()
    val leftCenter = TestUtils.newNode(portMaker.nextPort)(leftCenterCollect.add(_)).start()
    val rightCenter = TestUtils.newNode(portMaker.nextPort)(rightCenterCollect.add(_)).start()
    val rightMost = TestUtils.newNode(portMaker.nextPort)(rightMostCollect.add(_)).start()

    bridge(leftMost, leftCenter)
    bridge(leftCenter, rightCenter)
    bridge(rightCenter, rightMost)

    assertWithin1sec(leftMost.getRoutes.size == 3)
    assertWithin1sec(leftCenter.getRoutes.size == 3)
    assertWithin1sec(rightCenter.getRoutes.size == 3)
    
    rightMost.sendPreferred(new DataMessage().setTargetId(leftMost.id))
    leftMost.sendPreferred(new DataMessage().setTargetId(rightMost.id))
    
    assertWithin1sec(leftMostCollect.nonEmpty)
    assertWithin1sec(rightMostCollect.nonEmpty)
    assertWithin1sec(leftCenterCollect.isEmpty)
    assertWithin1sec(rightCenterCollect.isEmpty)

  }
 
  def bridge(from: Node, to: Node) {
    val wsFrom = from.getProvider[WebSockProvider]
    val wsTo = to.getProvider[WebSockProvider]
    wsFrom.addOutboundConnection(wsTo.listenPort)
  }

}