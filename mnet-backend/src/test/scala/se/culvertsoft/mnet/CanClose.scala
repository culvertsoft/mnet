package se.culvertsoft.mnet

import org.junit.Test

class CanClose {

  @Test
  def test() {
    TestUtils
      .newNode(1100)()
      .start()
      .stop()
  }

}