package se.culvertsoft.mnet

class PortMaker(startPort: Int) {
  private var next = startPort
  def nextPort(): Int = synchronized {
    val out = next
    next += 1
    out
  }
}