package se.culvertsoft.mnet.backend

import java.util.concurrent.ConcurrentHashMap

import scala.collection.JavaConversions.mapAsScalaConcurrentMap
import scala.collection.concurrent
import scala.collection.mutable.ArrayBuffer
import scala.reflect.ClassTag

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID

class Node {

  val id = MkId()

  private val routes: concurrent.Map[NodeUUID, Route] = new ConcurrentHashMap[NodeUUID, Route]
  private val routeProviders = new ArrayBuffer[RouteProvider]

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  def getRoutes(): Seq[Route] = {
    routes.values.toSeq
  }

  def getProviders(): Seq[RouteProvider] = {
    new ArrayBuffer[RouteProvider] ++ routeProviders.toSeq
  }

  def start(): Node = {
    routeProviders.foreach(_.start(callbackIfc))
    this
  }

  def stop(): Node = {
    routeProviders.foreach(_.stop())
    this
  }

  def sendJson(msg: Message): Node = {
    sendImpl(msg, route => route.connection.sendJson(msg))
  }

  def sendBinary(msg: Message): Node = {
    sendImpl(msg, route => route.connection.sendBinary(msg))
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

  def getProvider[T <: RouteProvider: ClassTag](): T = {
    val cls = scala.reflect.classTag[T].runtimeClass
    routeProviders
      .find(_.getClass == cls)
      .getOrElse(throw new BackendException(s"Unable to get provider $cls", null))
      .asInstanceOf[T]
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
   * 			PRIVATE
   *
   * ***************************************
   */

  private val callbackIfc = new NodeCallbackIfc() {

    override def onConnect(msg: NodeAnnouncement, route: Route) {
      incMsgHops(msg)
      routes.putIfAbsent(route.endpointId, route)
      broadcastJson(msg, _ != route)
      handleConnect(route)
    }

    override def onDisconnect(route: Route, reason: String) {
      if (routes.get(route.endpointId) == route) {
        routes.remove(route.endpointId)
        handleDisconnect(route, reason)
      }
    }

    override def onError(error: Exception, endPoint: AnyRef) {
      handleError(error, endPoint)
    }

    override def onMessage(message: Message, route: Option[Route]) {
      incMsgHops(message)
      handleMessage(message, route)
    }

    override def createAnnouncement(): NodeAnnouncement = {
      new NodeAnnouncement().setSenderId(id)
    }
  }

  protected final def sendImpl(
    msg: Message,
    sendFunc: Route => Unit): Node = {
    if (msg.getHops < msg.getMaxHops && msg.hasTargetId) {
      routes.get(msg.getTargetId).foreach { route =>
        sendFunc(route)
      }
    }
    this
  }

  protected final def broadcastImpl(
    msg: Message,
    sendFunc: Route => Unit,
    filter: Route => Boolean = _ => true): Node = {
    if (msg.getHops < msg.getMaxHops) {
      for ((_, route) <- routes) {
        if (filter(route) && route.endpointId != msg.getSenderId) {
          msg.setTargetId(route.endpointId)
          sendFunc(route)
        }
      }
    }
    this
  }

  protected final def incMsgHops(msg: Message) {
    if (!msg.hasHops())
      msg.setHops(0)
    if (!msg.hasMaxHops())
      msg.setMaxHops(3)
    msg.setHops((msg.getHops + 1).toByte)
  }

}