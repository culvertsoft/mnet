package se.culvertsoft.mnet.backend

import java.util.concurrent.ConcurrentHashMap

import scala.collection.JavaConverters.mapAsScalaConcurrentMapConverter
import scala.collection.mutable.ArrayBuffer

import se.culvertsoft.mnet.IdCreateReply
import se.culvertsoft.mnet.IdCreateRequest
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID

class ConnectionHandler(backEnd: NodeIfc) {

  private val conn2Id = new ConcurrentHashMap[Connection, ArrayBuffer[NodeUUID]].asScala
  private val endpoints = new ConcurrentHashMap[NodeUUID, Route].asScala

  def onMessage(conn: Connection, msg: Message) {

    msg match {

      case msg: NodeAnnouncement =>

        if (!msg.hasSenderId)
          throw new BackendException(s"${msg._typeName} from $conn missing senderId", conn)

        if (!endpoints.contains(msg.getSenderId))
          addEndpoint(msg, conn, new Route(msg.getSenderId, conn))

        backEnd.onMessage(msg, endpoints.get(msg.getSenderId))

      case msg: IdCreateRequest =>
        conn.sendJson(new IdCreateReply().setCreatedId(MkId()))

      case msg =>
        if (msg.hasSenderId)
          backEnd.onMessage(msg, endpoints.get(msg.getSenderId))
        else
          backEnd.onMessage(msg, None)

    }
  }

  def onConnect(conn: Connection) {
  }

  def onError(error: Exception, item: Connection) {
    backEnd.onError(error, item)
  }

  def onDisconnect(reason: String, conn: Connection) {
    for (endPoints <- conn2Id.remove(conn)) {
      for (endPoint <- endPoints) {
        backEnd.onDisconnect(endpoints(endPoint), reason)
      }
    }
  }

  private def addEndpoint(msg: NodeAnnouncement, conn: Connection, route: Route) = synchronized {
    endpoints.put(msg.getSenderId, route)
    conn2Id.getOrElse(conn, new ArrayBuffer) += msg.getSenderId
    backEnd.onConnect(msg, route)
  }

}