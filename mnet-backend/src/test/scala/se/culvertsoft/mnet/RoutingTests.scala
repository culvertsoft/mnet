package se.culvertsoft.mnet

import java.util.concurrent.ConcurrentLinkedQueue

import scala.collection.JavaConversions.collectionAsScalaIterable
import scala.collection.mutable.ArrayBuffer

import org.junit.Test

import TestUtils.assertWithin2sec
import se.culvertsoft.mnet.api.Node
import se.culvertsoft.mnet.backend.WebSockBackEnd

class RoutingTests {

  @Test
  def manyToOne() {

    val n = 20
    val nodes = new ArrayBuffer[Node]
    val portMaker = new PortMaker(11100)

    val firstNode = TestUtils
      .newNode(portMaker.nextPort)()
      .start()

    val tgtPort = firstNode.getBackEnd[WebSockBackEnd].listenPort

    for (i <- 0 until n) {
      val node = TestUtils
        .newNode(portMaker.nextPort)()
        .start()
      nodes += node
    }

    for (node <- nodes) {
      if (node != firstNode) {
        val myProvider = node.getBackEnd[WebSockBackEnd]
        myProvider.addOutboundConnection(tgtPort)
      }
    }

    assertWithin2sec(nodes.forall(_.getRoutes.size == n))

  }

  @Test
  def oneToMany() {

    val n = 20
    val nodes = new ArrayBuffer[Node]
    val portMaker = new PortMaker(11200)

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
        val tgtPort = node.getBackEnd[WebSockBackEnd].listenPort
        val myProvider = firstNode.getBackEnd[WebSockBackEnd]
        myProvider.addOutboundConnection(tgtPort)
      }
    }

    assertWithin2sec(nodes.forall(_.getRoutes.size == n))

  }

  @Test
  def bridged() {

    val portMaker = new PortMaker(11300)

    val leftMost = TestUtils.newNode(portMaker.nextPort)().start()
    val leftCenter = TestUtils.newNode(portMaker.nextPort)().start()
    val rightCenter = TestUtils.newNode(portMaker.nextPort)().start()
    val rightMost = TestUtils.newNode(portMaker.nextPort)().start()

    bridge(leftMost, leftCenter)
    bridge(leftCenter, rightCenter)
    bridge(rightCenter, rightMost)

    assertWithin2sec(leftMost.getRoutes.size == 3)
    assertWithin2sec(leftCenter.getRoutes.size == 3)
    assertWithin2sec(rightCenter.getRoutes.size == 3)
    assertWithin2sec(rightMost.getRoutes.size == 3)

  }

  @Test
  def bridgedMessaging() {

    val portMaker = new PortMaker(11400)

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

    assertWithin2sec(leftMost.getRoutes.size == 3)
    assertWithin2sec(leftCenter.getRoutes.size == 3)
    assertWithin2sec(rightCenter.getRoutes.size == 3)
    assertWithin2sec(rightMost.getRoutes.size == 3)

    rightMost.send(new DataMessage().setTargetId(leftMost.id))
    leftMost.send(new DataMessage().setTargetId(rightMost.id))

    assertWithin2sec(leftMostCollect.nonEmpty)
    assertWithin2sec(rightMostCollect.nonEmpty)
    assertWithin2sec(leftCenterCollect.isEmpty)
    assertWithin2sec(rightCenterCollect.isEmpty)

  }

  @Test
  def aBridgeTooFar() {

    val portMaker = new PortMaker(11500)

    val leftMost = TestUtils.newNode(portMaker.nextPort)().start()
    val leftCenter = TestUtils.newNode(portMaker.nextPort)().start()
    val center = TestUtils.newNode(portMaker.nextPort)().start()
    val rightCenter = TestUtils.newNode(portMaker.nextPort)().start()
    val rightMost = TestUtils.newNode(portMaker.nextPort)().start()

    bridge(leftMost, leftCenter)
    bridge(leftCenter, center)
    bridge(center, rightCenter)
    bridge(rightCenter, rightMost)

    assertWithin2sec(leftMost.getRoutes.size == 3)
    assertWithin2sec(leftCenter.getRoutes.size == 4)
    assertWithin2sec(center.getRoutes.size == 4)
    assertWithin2sec(rightCenter.getRoutes.size == 4)
    assertWithin2sec(rightMost.getRoutes.size == 3)

  }

  private def bridge(from: Node, to: Node) {
    val wsFrom = from.getBackEnd[WebSockBackEnd]
    val wsTo = to.getBackEnd[WebSockBackEnd]
    wsFrom.addOutboundConnection(wsTo.listenPort)
  }

}