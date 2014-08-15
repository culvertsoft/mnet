package se.culvertsoft.mnet.backend

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeUUID

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

  def onConnect(route: Route) {
    if (!routingTable.contains(route.id))
      routingTable.put(route.id, route)
  }

  def onDisconnect(route: Route, reason: String) {
    if (routingTable.get(route.id) == route)
      routingTable.remove(route.id)
  }

  def onError(route: Option[Route], error: Exception) {

  }

  def onMessage(route: Option[Route], message: Message) {

  }

}