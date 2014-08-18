package se.culvertsoft.mnet.client

import scala.collection.JavaConversions.asScalaBuffer

import org.junit.Test

import se.culvertsoft.mnet.TestUtils

class BasicTest {

  @Test
  def canConnect() {
    val b1 = new MNetClient
    val b2 = new MNetClient("localhost", 80)

    b1.start()
    b2.start()

    TestUtils.assertWithin1sec(b1.getRoutes.nonEmpty)
    TestUtils.assertWithin1sec(b2.getRoutes.nonEmpty)

  }
}