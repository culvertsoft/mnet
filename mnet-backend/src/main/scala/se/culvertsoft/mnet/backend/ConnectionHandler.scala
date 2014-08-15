package se.culvertsoft.mnet.backend

import java.util.concurrent.ConcurrentHashMap

import scala.collection.JavaConverters.mapAsScalaConcurrentMapConverter
import scala.collection.mutable.ArrayBuffer

import se.culvertsoft.mnet.IdCreateReply
import se.culvertsoft.mnet.IdCreateRequest
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID

class ConnectionHandler(backEnd: NodeCallbackIfc) {

  private val conn2Id = new ConcurrentHashMap[Connection, ArrayBuffer[NodeUUID]].asScala
  private val routes = new ConcurrentHashMap[NodeUUID, Route].asScala

  def onMessage(conn: Connection, msg: Message) {

    msg match {

      case msg: NodeAnnouncement =>

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

  def onConnect(conn: Connection) {
    conn.sendJson(backEnd.createAnnouncement())
  }

  def onError(error: Exception, item: Connection) {
    backEnd.onError(error, item)
  }

  def onDisconnect(reason: String, conn: Connection) {

    val removedRoutes: Seq[Route] = conn2Id.synchronized {
      conn2Id.remove(conn) match {
        case Some(items) => items.map(routes.remove(_).get)
        case None => Nil
      }
    }

    removedRoutes.foreach(backEnd.onDisconnect(_, reason))

  }

  private def addEndpoint(msg: NodeAnnouncement, conn: Connection, route: Route) {
    conn2Id.synchronized {
      conn2Id.getOrElse(conn, new ArrayBuffer) += (msg.getSenderId)
      routes.put(msg.getSenderId, route)
    }
    backEnd.onConnect(msg, route)
  }

}