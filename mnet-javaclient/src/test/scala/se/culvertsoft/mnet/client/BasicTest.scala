package se.culvertsoft.mnet.client

import scala.collection.JavaConversions.asScalaBuffer
import org.junit.Test
import se.culvertsoft.mnet.TestUtils
import se.culvertsoft.mnet.backend.WebsockBackendSettings

class BasicTest {

  @Test
  def canConnect() {
    val port = 22180
    val b1 = new MNetClient(new WebsockBackendSettings().setListenPort(port))
    val b2 = new MNetClient("localhost", port)

    b1.start()
    b2.start()

    TestUtils.assertWithin1sec(b1.getRoutes.nonEmpty)
    TestUtils.assertWithin1sec(b2.getRoutes.nonEmpty)

  }
}