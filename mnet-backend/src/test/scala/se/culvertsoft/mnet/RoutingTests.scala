package se.culvertsoft.mnet

import scala.collection.mutable.ArrayBuffer

import org.junit.Test

import TestUtils.assertWithin1sec
import se.culvertsoft.mnet.backend.Node
import se.culvertsoft.mnet.backend.WebSockProvider

class RoutingTests {

  @Test
  def manyToOne() {

    val n = 20
    val nodes = new ArrayBuffer[Node]

    try {

      val firstNode = TestUtils
        .newNode(1100)()
        .start()

      val tgtPort = firstNode.getProvider[WebSockProvider].listenPort

      for (i <- 0 until n) {
        val port = 1101 + i
        val node = TestUtils
          .newNode(port)()
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

    } finally {
      nodes.foreach(_.stop())
    }

  }

}