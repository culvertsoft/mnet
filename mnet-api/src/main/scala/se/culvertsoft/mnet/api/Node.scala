package se.culvertsoft.mnet.api

import java.util.ArrayList
import java.util.concurrent.ConcurrentHashMap

import scala.collection.JavaConversions.bufferAsJavaList
import scala.collection.JavaConversions.mapAsScalaConcurrentMap
import scala.collection.mutable.ArrayBuffer
import scala.reflect.ClassTag

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeSettings
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.api.util.NewNodeUUID

/**
 * Represents a local MNet node that can be connected to
 * an MNet network using one or more BackEnd objects.
 *
 * @param name
 * 		The name this node will use to announce its presence on the network. This is
 *   	not required to be unique. Node's also create internal UUIDs for a unique ID
 *    	on the network.
 *
 * @param tags
 * 		The set of tags this node will use to announce its presence on the network
 *
 * @param announceInterval
 * 		The time interval at which to send announcements on the network about this
 *   	Node's presence. Announcements are also send when initally connecting.
 */
class Node(
  val name: String,
  val tags: java.util.List[String],
  val announceInterval: Double) {
  def this(settings: NodeSettings = new NodeSettings) = this(settings.getName, settings.getTags, settings.getAnnounceInterval)

  /**
   * The unique NodeUUID of this node on the network.
   */
  val id = NewNodeUUID()

  /**
   * Currently detected neighbor nodes on the network.
   */
  private val neighbors = new ConcurrentHashMap[NodeUUID, Route]

  /**
   * Routing table from node IDs to endpoints.
   */
  private val routes = new ConcurrentHashMap[NodeUUID, Route]

  /**
   * Current added BackEnd instances. Empty by default. Use addBackEnd(..).
   */
  private val backEnds = new ArrayBuffer[BackEnd]

  /**
   * See ConnectionConsolidator. Briefly: Consolidates connection input from multiple
   * threads to a single event handling thread.
   */
  private val connectionConsolidator = new ConnectionConsolidator(this)

  /**
   * ****************************************
   *
   * 			API
   *
   * ***************************************
   */

  /**
   * Gets a snapshot of the currently known routes.
   */
  def getRoutes(): java.util.List[Route] = {
    new ArrayList(routes.values)
  }

  /**
   * Gets a snapshot of the currently attached back-ends.
   */
  def getBackEnds(): java.util.List[BackEnd] = {
    new ArrayList(backEnds)
  }

  /**
   * Starts this node, its ConnectionConsolidator and any attached BackEnd objects.
   */
  def start(): Node = {
    connectionConsolidator.start()
    backEnds.foreach(_.start(connectionConsolidator))
    this
  }

  /**
   * Stops this Node, its ConnectionConsolidator and any attached BackEnd objects.
   */
  def stop(): Node = {
    connectionConsolidator.stop()
    backEnds.foreach(_.stop())
    this
  }

  /**
   * Sends a message. If the message has a targetId, it will be sent along that Route only.
   * If the message does NOT have a targetId, it is considered a broadcast. See broadcast(..).
   */
  def send(msg: Message): Node = {
    if (msg.hasTargetId)
      sendImpl(msg)
    else
      broadcast(msg)
  }

  /**
   * Broadcasts a message to all neighbor nodes (and onwards) that meet the given filter.
   * The default filter sends to all neighbors.
   */
  def broadcast(msg: Message, filter: Route => Boolean = _ => true): Node = {
    broadcastImpl(msg, filter)
    this
  }

  /**
   * Adds a new BackEnd instance to this Node. E.g. myNode.addBackEnd(new WebsockBackEnd(...)...)
   */
  def addBackEnd(BackEnd: BackEnd): Node = {
    backEnds += BackEnd
    this
  }

  /**
   * Gets a currently attached BackEnd object by type.
   *
   * @throw MNetException
   * 		If no such BackEnd is currently attached
   */
  def getBackEnd[T <: BackEnd: ClassTag](): T = {
    val cls = scala.reflect.classTag[T].runtimeClass
    backEnds
      .find(_.getClass == cls)
      .getOrElse(throw new MNetException(s"Unable to get provider $cls", null))
      .asInstanceOf[T]
  }

  /**
   * Sends a NodeAnnouncement about this node on the network. Usually not necessary
   * to call from outside since it will be called on regular intervals by the
   * ConnectionConsolidator anyway.
   */
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

  /**
   * Called by the ConnectionConsolidator when a new route is discovered.
   */
  def handleConnect(route: Route) {

  }

  /**
   * Called by the ConnectionConsolidator when a route is lost.
   */
  def handleDisconnect(route: Route, reason: String) {

  }

  /**
   * Called by any thread when an exception is thrown
   */
  def handleError(error: Exception, endPoint: AnyRef) {
    error.printStackTrace()
  }

  /**
   * Called by the ConnectionConsolidator when a new message is received.
   */
  def handleMessage(message: Message, route: Option[Route]) {

  }

  /**
   * Default handling for creating a NodeAnnouncement. Can be overloaded. In such a case
   * the recommended way to use it is to subclass NodeAnnouncement to add further fields that
   * work better in your system.
   *
   * Note: May be called from any thread.
   */
  def createAnnouncement(): NodeAnnouncement = {
    new NodeAnnouncement()
      .setName(name)
      .setTags(new java.util.ArrayList(tags))
      .setSenderId(id)
  }

  /**
   * ****************************************
   *
   * 		For route providers to use
   *
   * ***************************************
   */

  /**
   * Default handling of a new NodeAnnouncement. Can be overloaded, but is usually not the case.
   * Only to be called by the ConnectionConsolidator.
   */
  def onAnnounce(msg: NodeAnnouncement, route: Route) {

    if (msg.getHops == 1) {
      neighbors.put(route.endpointId, route)
    }

    if (!routes.contains(route.endpointId)) {
      routes.put(route.endpointId, route)
      handleConnect(route)
    }

    broadcast(msg, _ != route)

  }

  /**
   * Default handling of a disconnected route. Can be overloaded, but is usually not the case.
   * Only to be called by the ConnectionConsolidator.
   */
  def onDisconnect(route: Route, reason: String) {
    neighbors.remove(route.endpointId)
    routes.get(route.endpointId) match {
      case r: Route if (r == route) =>
        routes.remove(route.endpointId)
        handleDisconnect(route, reason)
      case _ =>
    }
  }

  /**
   * Default handling of a errors. Can be overloaded, but is usually not the case.
   * Only to be called by internal threads.
   */
  def onError(error: Exception, endPoint: AnyRef) {
    handleError(error, endPoint)
  }

  /**
   * Default handling of a new message. Can be overloaded, but is usually not the case.
   * Only to be called by the ConnectionConsolidator.
   */
  def onMessage(message: Message, route: Option[Route]) {

    // Targeted
    if (message.hasTargetId) {
      if (message.getTargetId == id) {
        handleMessage(message, route)
      } else {
        routes.get(message.getTargetId) match {
          case route: Route => route.send(message)
          case _ =>
        }
      }
    } // Broadcast
    else {
      handleMessage(message, route)
      broadcast(message, _ != route.getOrElse(null))
    }

  }

  /**
   * Default send implementation.
   */
  protected def sendImpl(msg: Message): Node = {
    if (msg.getHops < msg.getMaxHops && msg.hasTargetId) {
      routes.get(msg.getTargetId) match {
        case route: Route => route.send(msg)
        case _ =>
      }
    }
    this
  }

  /**
   * b
   * Default broadcast implementation.
   */
  protected def broadcastImpl(
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