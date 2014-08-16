package se.culvertsoft.mnet.backend

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import scala.util.Random

import se.culvertsoft.mnet.IdCreateReply
import se.culvertsoft.mnet.IdCreateRequest
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.api.MTCommandQue

class NodeConnectionHandler(
  node_dont_use_here: Node,
  announceDt: Double,
  fuzzyDt: Boolean = true) extends MTCommandQue[Node](node_dont_use_here) {

  private val conn2Id = new HashMap[Connection, ArrayBuffer[NodeUUID]]
  private val routes = new HashMap[NodeUUID, Route]
  private var lastAnnounce = time

  override def step(node: Node) {
    if (time - lastAnnounce > announceDt) {
      val fuzz = if (fuzzyDt) Random.nextFloat * announceDt * 0.2 else 0.0
      lastAnnounce = time + fuzz
      node.announce()
    }
  }

  def onMessage(conn: Connection, msg: Message) {

    incMsgHops(msg)

    queCommand { node =>

      msg match {

        case msg: NodeAnnouncement =>

          if (!msg.hasSenderId)
            throw new BackendException(s"${msg._typeName} from $conn missing senderId", conn)

          routes.get(msg.getSenderId) match {
            case x @ Some(route) =>
              node.onAnnounce(msg, route)
            case None =>
              val route = new Route(msg.getSenderId, conn)
              addEndpoint(msg, conn, route)
              node.onAnnounce(msg, route)
          }

        case msg: IdCreateRequest =>
          conn.sendJson(new IdCreateReply().setCreatedId(MkId()))

        case msg =>

          node.onMessage(msg,
            if (msg.hasSenderId) routes.get(msg.getSenderId)
            else None)

      }
    }
  }

  def onConnect(conn: Connection) {
    queCommand { node =>
      conn.sendJson(node.createAnnouncement())
    }
  }

  def onError(error: Exception, item: Connection) {
    queCommand { node =>
      node.onError(error, item)
    }
  }

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