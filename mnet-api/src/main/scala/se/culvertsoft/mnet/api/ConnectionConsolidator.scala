package se.culvertsoft.mnet.api

import scala.util.Random

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeSettings
import se.culvertsoft.mnet.api.util.ThreadConsolidator

/**
 * This class manages the input from multiple connections and their potential helper threads
 * and consolidates the input on a single event handling thread.
 */
class ConnectionConsolidator(
  node_dont_use_here: Node,
  settings: NodeSettings,
  iterationTime: Int = 10) extends ThreadConsolidator[Node](node_dont_use_here, iterationTime) {

  /**
   * Helper time stamp to know when we last sent out a NodeAnnouncement
   */
  private var lastAnnounce = time

  /**
   * Method called up to every iterationTime milliseconds on the event handling thread that this
   * ConnectionConsolidator maintains. May be extended/overloaded.
   */
  override def step(node: Node) {
    if (time - lastAnnounce > settings.getAnnounceInterval) {
      val fuzz = Random.nextFloat * settings.getAnnounceInterval * 0.2
      lastAnnounce = time + fuzz
      node.announce()
    }
  }

  /**
   * Called when receiving a new message. From any of the managed connections.
   * Increases the hop count of the incoming message and places it in the
   * command que of this ConnectionConsolidator. Notifies the event handling thread
   * that a new command is available.
   */
  def onMessage(msg: Message, conn: Connection) {
    queCommand { _.onMessage(msg, conn) }
  }

  /**
   * Called when receiving a new connection. Notifies the event handling thread
   * that a new command is available.
   */
  def onConnect(conn: Connection) {
    queCommand { _.onConnect(conn) }
  }

  /**
   * Called when notified of an error by any of the managed connections.
   * Notifies the event handling thread that a new command is available.
   */
  def onError(error: Exception, source: Connection) {
    queCommand { _.onError(error, source) }
  }

  /**
   * Called when receiving a connection is lost. Notifies the event handling thread
   * that a new command is available.
   */
  def onDisconnect(reason: String, conn: Connection) {
    queCommand { _.onNeighborDisconnect(reason, conn) }
  }

  def time(): Double = {
    System.nanoTime() / 1e9
  }

}