package se.culvertsoft.mnet.backend

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.NodeAnnouncement

class Node(settings: BackendConfiguration)
  extends NodeIfc {

  val id = MkId()
  val port = settings.getPort()

  private val routingTable = new HashMap[NodeUUID, Route]
  private val routeProviders = new ArrayBuffer[RouteProvider]

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  def start(): Node = {
    routeProviders.foreach(_.start(this))
    this
  }

  def stop(): Node = {
    routeProviders.foreach(_.stop())
    this
  }

  def addRouteProvider(routeProvider: RouteProvider): Node = {
    routeProviders += routeProvider
    this
  }

  /**
   * ****************************************
   *
   * 			OVERRIDEABLES
   *
   * ***************************************
   */

  override def onConnect(msg: NodeAnnouncement, route: Route) {
    msg.setHops((msg.getHops + 1).toByte)
    if (!routingTable.contains(route.endpointId))
      routingTable.put(route.endpointId, route)
   // broadCast(msg, route.endpointId)
  }

  override def onDisconnect(route: Route, reason: String) {
    if (routingTable.get(route.endpointId) == route)
      routingTable.remove(route.endpointId)
  }

  override def onError(error: Exception, endPoint: AnyRef) {

  }

  override def onMessage(message: Message, route: Option[Route]) {

  }

}