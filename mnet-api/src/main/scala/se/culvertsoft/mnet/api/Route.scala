package se.culvertsoft.mnet.api

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID

case class Route(
  val endpointId: NodeUUID,
  val connection: Connection,
  val announcement: NodeAnnouncement) {

  def send(msg: Message) {
    connection.send(msg)
  }

}