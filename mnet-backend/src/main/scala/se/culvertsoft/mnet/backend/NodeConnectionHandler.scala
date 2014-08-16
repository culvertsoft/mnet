package se.culvertsoft.mnet.backend

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap

import se.culvertsoft.mnet.IdCreateReply
import se.culvertsoft.mnet.IdCreateRequest
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.api.MTCommandQue

class NodeConnectionHandler(node_dont_use_here: NodeCallbackIfc) extends MTCommandQue[NodeCallbackIfc](node_dont_use_here) {

  private val conn2Id = new HashMap[Connection, ArrayBuffer[NodeUUID]]
  private val routes = new HashMap[NodeUUID, Route]

  def onMessage(conn: Connection, msg: Message) {

    queCommand { backEnd =>

      msg match {

        case msg: NodeAnnouncement =>

          println(s"${backEnd.createAnnouncement.getSenderId.getLsb} got ${msg.getSenderId.getLsb} from $conn")

          if (!msg.hasSenderId)
            throw new BackendException(s"${msg._typeName} from $conn missing senderId", conn)

          routes.get(msg.getSenderId) match {
            case x @ Some(route) =>
              backEnd.onMessage(msg, x)
            case None =>
              addEndpoint(msg, conn, new Route(msg.getSenderId, conn))
          }

        case msg: IdCreateRequest =>
          conn.sendJson(new IdCreateReply().setCreatedId(MkId()))

        case msg =>

          backEnd.onMessage(msg,
            if (msg.hasSenderId) routes.get(msg.getSenderId)
            else None)

      }
    }
  }

  def onConnect(conn: Connection) {
    queCommand { backEnd =>
      conn.sendJson(backEnd.createAnnouncement())
    }
  }

  def onError(error: Exception, item: Connection) {
    queCommand { backEnd =>
      backEnd.onError(error, item)
    }
  }

  def onDisconnect(reason: String, conn: Connection) {

    queCommand { backEnd =>
      val removedRoutes: Seq[Route] = {
        conn2Id.remove(conn) match {
          case Some(items) => items.map(routes.remove(_).get)
          case None => Nil
        }
      }

      removedRoutes.foreach(backEnd.onDisconnect(_, reason))
    }

  }

  private def addEndpoint(msg: NodeAnnouncement, conn: Connection, route: Route) {

    queCommand { backEnd =>
      conn2Id.getOrElse(conn, new ArrayBuffer) += (msg.getSenderId)
      routes.put(msg.getSenderId, route)
      backEnd.onConnect(msg, route)
    }
  }

}