package se.culvertsoft.mnet.backend

import java.util.concurrent.ConcurrentHashMap

import scala.collection.JavaConverters.mapAsScalaConcurrentMapConverter

import se.culvertsoft.mnet.IdCreateReply
import se.culvertsoft.mnet.IdCreateRequest
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement

class ConnectionHandler(backEnd: NodeIfc) {
  private val pending = new ConcurrentHashMap[Connection, Connection].asScala
  private val connected = new ConcurrentHashMap[Connection, Route].asScala

  def onMessage(conn: Connection, msg: Message) {

    msg match {

      case msg: NodeAnnouncement =>

        if (!msg.hasSenderId)
          throw new BackendException(s"${msg._typeName} from $conn missing senderId", conn)

        if (pending.contains(conn)) {
          val newNeighbor = new Route(msg.getSenderId, conn)
          pending -= conn
          connected.put(conn, newNeighbor)
          backEnd.onConnect(newNeighbor)
        }

        backEnd.onMessage(connected.get(conn), msg)

      case msg: IdCreateRequest =>
        conn.sendJson(new IdCreateReply().setCreatedId(MkId()))

      case msg =>
        backEnd.onMessage(connected.get(conn), msg)

    }
  }

  def onConnect(conn: Connection) {
    pending.put(conn, conn)
  }

  def onDisconnect(conn: Connection, reason: String) {
    pending -= conn
    connected -= conn
  }

  def onError(conn: Connection, ex: Exception) {
    backEnd.onError(connected.get(conn), ex)
  }

}