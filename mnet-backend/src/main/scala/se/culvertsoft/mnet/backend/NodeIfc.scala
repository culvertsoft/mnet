package se.culvertsoft.mnet.backend

import se.culvertsoft.mnet.Message

trait NodeIfc {

  def onConnect(neighbor: Route)

  def onDisconnect(neighbor: Route, reason: String)

  def onError(neighbor: Option[Route], error: Exception)

  def onMessage(neighbor: Option[Route], message: Message)

}
