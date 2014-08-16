package se.culvertsoft.mnet

import org.junit.Test

class CanClose {

  @Test
  def test() {
    TestUtils
      .newNode(100)()
      .start()
      .stop()
  }

}