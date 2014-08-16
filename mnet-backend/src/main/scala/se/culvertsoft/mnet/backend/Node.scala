package se.culvertsoft.mnet.backend

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import scala.reflect.ClassTag

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID

class Node(announceDt: Double = 0.5) {

  val id = MkId()

  private val neighbors = new HashMap[NodeUUID, Route]
  private val routes = new HashMap[NodeUUID, Route]
  private val routeProviders = new ArrayBuffer[RouteProvider]
  private val connectionHandler = new NodeConnectionHandler(this, announceDt)

  @volatile var routesView: Array[Route] = Array[Route]()

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  def getRoutes(): Seq[Route] = routes.synchronized {
    routesView
  }

  def getProviders(): Seq[RouteProvider] = {
    new ArrayBuffer[RouteProvider] ++ routeProviders
  }

  def start(): Node = {
    connectionHandler.start()
    routeProviders.foreach(_.start(connectionHandler))
    this
  }

  def stop(): Node = {
    connectionHandler.stop()
    routeProviders.foreach(_.stop())
    this
  }

  def sendJson(msg: Message): Node = {
    sendImpl(msg, route => route.connection.sendJson(msg))
  }

  def sendBinary(msg: Message): Node = {
    sendImpl(msg, route => route.connection.sendBinary(msg))
  }

  def sendPreferred(msg: Message): Node = {
    sendImpl(msg, route => route.connection.sendPreferred(msg))
  }

  def addRouteProvider(routeProvider: RouteProvider): Node = {
    routeProviders += routeProvider
    this
  }

  def broadcastJson(msg: Message, filter: Route => Boolean = _ => true): Node = {
    broadcastImpl(msg, route => route.connection.sendJson(msg), filter)
    this
  }

  def broadcastBinary(msg: Message, filter: Route => Boolean = _ => true): Node = {
    broadcastImpl(msg, route => route.connection.sendBinary(msg), filter)
    this
  }

  def broadcastPreferred(msg: Message, filter: Route => Boolean = _ => true): Node = {
    broadcastImpl(msg, route => route.connection.sendPreferred(msg), filter)
    this
  }

  def getProvider[T <: RouteProvider: ClassTag](): T = {
    val cls = scala.reflect.classTag[T].runtimeClass
    routeProviders
      .find(_.getClass == cls)
      .getOrElse(throw new BackendException(s"Unable to get provider $cls", null))
      .asInstanceOf[T]
  }

  def announce() {
    broadcastJson(createAnnouncement())
  }

  /**
   * ****************************************
   *
   * 			OVERRIDEABLES
   *
   * ***************************************
   */

  def handleConnect(route: Route) {

  }

  def handleDisconnect(route: Route, reason: String) {

  }

  def handleError(error: Exception, endPoint: AnyRef) {
    error.printStackTrace()
  }

  def handleMessage(message: Message, route: Option[Route]) {

  }

  /**
   * ****************************************
   *
   * 		For route providers to use
   *
   * ***************************************
   */

  def onAnnounce(msg: NodeAnnouncement, route: Route) {

    if (msg.getHops == 1) {
      neighbors.put(route.endpointId, route)
    }

    if (!routes.contains(route.endpointId)) {
      routes.put(route.endpointId, route)
      routesView = routes.values.toArray
      handleConnect(route)
    }

    broadcastJson(msg, _ != route)

  }

  def onDisconnect(route: Route, reason: String) {
    neighbors.remove(route.endpointId)
    routes.get(route.endpointId) match {
      case Some(r: Route) if (r == route) =>
        routes.remove(route.endpointId)
        handleDisconnect(route, reason)
      case _ =>
    }
  }

  def onError(error: Exception, endPoint: AnyRef) {
    handleError(error, endPoint)
  }

  def onMessage(message: Message, route: Option[Route]) {

    // Targeted
    if (message.hasTargetId) {
      if (message.getTargetId == id) {
        handleMessage(message, route)
      } else {
        routes.get(message.getTargetId) match {
          case Some(route) => route.connection.sendPreferred(message)
          case _ =>
        }
      }
    } // Broadcast
    else {
      handleMessage(message, route)
      broadcastPreferred(message, _ != route.getOrElse(null))
    }

  }

  def createAnnouncement(): NodeAnnouncement = {
    new NodeAnnouncement().setSenderId(id)
  }

  protected final def sendImpl(
    msg: Message,
    sendFunc: Route => Unit): Node = {

    if (!msg.hasSenderId)
      msg.setSenderId(id)

    if (msg.getHops < msg.getMaxHops && msg.hasTargetId) {
      routes.get(msg.getTargetId) match {
        case Some(route) => sendFunc(route)
        case _ =>
      }
    }
    this
  }

  protected final def broadcastImpl(
    msg: Message,
    sendFunc: Route => Unit,
    filter: Route => Boolean = _ => true): Node = {

    if (!msg.hasSenderId)
      msg.setSenderId(id)

    if (msg.getHops < msg.getMaxHops) {
      for ((_, route) <- neighbors) {
        if (filter(route) && route.endpointId != msg.getSenderId) {
          msg.setTargetId(route.endpointId)
          sendFunc(route)
        }
      }
    }
    this
  }

}