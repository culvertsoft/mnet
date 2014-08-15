package se.culvertsoft.mnet.backend

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID

trait NodeCallbackIfc {

  def createAnnouncement(): NodeAnnouncement
  
  def onConnect(msg: NodeAnnouncement, route: Route)

  def onDisconnect(route: Route, reason: String)

  def onError(error: Exception, endPoint: AnyRef)

  def onMessage(message: Message, route: Option[Route])

}
