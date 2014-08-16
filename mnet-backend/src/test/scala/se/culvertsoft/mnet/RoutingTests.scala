package se.culvertsoft.mnet

import java.util.concurrent.ConcurrentLinkedQueue
import org.junit.Test
import TestUtils._
import se.culvertsoft.mnet.backend.WebSockProvider
import scala.collection.mutable.ArrayBuffer
import se.culvertsoft.mnet.backend.Node

class RoutingTests {

  @Test
  def manyToOne() {

    val n = 3
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

      Thread.sleep(1000)

      println(firstNode.getRoutes.size)

      for (node <- nodes) {
        println(node.getRoutes.size)
      }
      assertWithin1sec(nodes.forall(_.getRoutes.size == n))

    } finally {
      nodes.foreach(_.stop())
    }

  }

}