package se.culvertsoft.mnet.api

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import scala.util.Random

import se.culvertsoft.mnet.IdCreateReply
import se.culvertsoft.mnet.IdCreateRequest
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.api.util.NewNodeUUID
import se.culvertsoft.mnet.api.util.ThreadConsolidator

/**
 * This class manages the input from multiple connections and their potential helper threads
 * and consolidates the input on a single event handling thread.
 */
class ConnectionConsolidator(
  node_dont_use_here: Node,
  fuzzyDt: Boolean = true,
  iterationTime: Int = 10) extends ThreadConsolidator[Node](node_dont_use_here, iterationTime) {

  /**
   * Look-up table from connections -> endpoint NodeUUIDs
   */
  private val conn2Id = new HashMap[Connection, ArrayBuffer[NodeUUID]]

  /**
   * Lookup-table of NodeUUIDs -> Routes currently active. Mirrors Node.routes.
   */
  private val routes = new HashMap[NodeUUID, Route]

  /**
   * Helper time stamp to know when we last sent out a NodeAnnouncement
   */
  private var lastAnnounce = time

  /**
   * Method called up to every iterationTime milliseconds on the event handling thread that this
   * ConnectionConsolidator maintains. May be extended/overloaded.
   */
  override def step(node: Node) {
    if (time - lastAnnounce > node.announceInterval) {
      val fuzz = if (fuzzyDt) Random.nextFloat * node.announceInterval * 0.2 else 0.0
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
  def onMessage(conn: Connection, msg: Message) {

    incMsgHops(msg)

    queCommand { node =>

      msg match {

        case msg: NodeAnnouncement =>

          if (!msg.hasSenderId)
            throw new MNetException(s"${msg._typeName} from $conn missing senderId", conn)

          routes.get(msg.getSenderId) match {
            case x @ Some(route) =>
              node.onAnnounce(msg, route)
            case None =>
              val route = new Route(msg.getSenderId, conn, msg)
              addEndpoint(msg, conn, route)
              node.onAnnounce(msg, route)
          }

        case msg: IdCreateRequest =>
          conn.send(new IdCreateReply().setCreatedId(NewNodeUUID()))

        case msg =>

          node.onMessage(msg,
            if (msg.hasSenderId) routes.get(msg.getSenderId)
            else None)

      }
    }
  }

  /**
   * Called when receiving a new connection. Notifies the event handling thread
   * that a new command is available.
   */
  def onConnect(conn: Connection) {
    queCommand { node =>
      conn.send(node.createAnnouncement())
    }
  }

  /**
   * Called when notified of an error by any of the managed connections.
   * Notifies the event handling thread that a new command is available.
   */
  def onError(error: Exception, item: Connection) {
    queCommand { node =>
      node.onError(error, item)
    }
  }

  /**
   * Called when receiving a connection is lost. Notifies the event handling thread
   * that a new command is available.
   */
  def onDisconnect(reason: String, conn: Connection) {

    queCommand { node =>
      val removedRoutes: Seq[Route] = {
        conn2Id.remove(conn) match {
          case Some(items) => items.map(routes.remove(_).get)
          case None => Nil
        }
      }

      removedRoutes.foreach(node.onDisconnect(_, reason))
    }

  }

  private def addEndpoint(msg: NodeAnnouncement, conn: Connection, route: Route) {
    conn2Id.getOrElse(conn, new ArrayBuffer) += (msg.getSenderId)
    routes.put(msg.getSenderId, route)
  }

  private final def incMsgHops(msg: Message) {
    if (!msg.hasHops())
      msg.setHops(0)
    if (!msg.hasMaxHops())
      msg.setMaxHops(3)
    msg.setHops((msg.getHops + 1).toByte)
  }

  def time(): Double = {
    System.nanoTime() / 1e9
  }

}