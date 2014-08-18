package se.culvertsoft.mnet.client

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeSettings
import se.culvertsoft.mnet.api.Connection
import se.culvertsoft.mnet.api.Node
import se.culvertsoft.mnet.api.Route

class MNetClientNode(
  client: MNetClient,
  nodeSettings: NodeSettings) extends Node(nodeSettings) {

  override def handleConnect(route: Route) {
    client.handleConnect(route)
  }

  override def handleDisconnect(route: Route, reason: String) {
    client.handleDisconnect(route, reason)
  }

  override def handleError(error: Exception, source: Object) {
    client.handleError(error, source)
  }

  override def handleMessage(message: Message, connection: Connection) {
    client.handleMessage(message, connection)
  }

  override def createAnnouncement(): NodeAnnouncement = {
    client.createAnnouncement()
  }

}
