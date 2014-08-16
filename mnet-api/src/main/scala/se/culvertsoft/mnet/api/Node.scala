package se.culvertsoft.mnet.api

import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import scala.reflect.ClassTag

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeSettings
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.api.util.NewNodeUUID

class Node(
  val name: String,
  val tags: java.util.ArrayList[String],
  val announceInterval: Double) {
  def this(settings: NodeSettings = new NodeSettings) = this(settings.getName, settings.getTags, settings.getAnnounceInterval)

  val id = NewNodeUUID()

  private val neighbors = new HashMap[NodeUUID, Route]
  private val routes = new HashMap[NodeUUID, Route]
  private val backEnds = new ArrayBuffer[BackEnd]
  private val connectionHandler = new ConnectionConsolidator(this)

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

  def getBackEnds(): Seq[BackEnd] = {
    new ArrayBuffer[BackEnd] ++ backEnds
  }

  def start(): Node = {
    connectionHandler.start()
    backEnds.foreach(_.start(connectionHandler))
    this
  }

  def stop(): Node = {
    connectionHandler.stop()
    backEnds.foreach(_.stop())
    this
  }

  def send(msg: Message): Node = {
    sendImpl(msg)
  }

  def broadcast(msg: Message, filter: Route => Boolean = _ => true): Node = {
    broadcastImpl(msg, filter)
    this
  }

  def addBackEnd(BackEnd: BackEnd): Node = {
    backEnds += BackEnd
    this
  }

  def getBackEnd[T <: BackEnd: ClassTag](): T = {
    val cls = scala.reflect.classTag[T].runtimeClass
    backEnds
      .find(_.getClass == cls)
      .getOrElse(throw new MNetException(s"Unable to get provider $cls", null))
      .asInstanceOf[T]
  }

  def announce() {
    broadcast(createAnnouncement())
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

    broadcast(msg, _ != route)

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
          case Some(route) => route.send(message)
          case _ =>
        }
      }
    } // Broadcast
    else {
      handleMessage(message, route)
      broadcast(message, _ != route.getOrElse(null))
    }

  }

  def createAnnouncement(): NodeAnnouncement = {
    new NodeAnnouncement()
      .setName(name)
      .setTags(tags)
      .setSenderId(id)
  }

  protected final def sendImpl(msg: Message): Node = {
    if (msg.getHops < msg.getMaxHops && msg.hasTargetId) {
      routes.get(msg.getTargetId) match {
        case Some(route) => route.send(msg)
        case _ =>
      }
    }
    this
  }

  protected final def broadcastImpl(
    msg: Message,
    filter: Route => Boolean = _ => true): Node = {
    if (msg.getHops < msg.getMaxHops) {
      for ((_, route) <- neighbors) {
        if (filter(route) && route.endpointId != msg.getSenderId) {
          route.send(msg)
        }
      }
    }
    this
  }

}