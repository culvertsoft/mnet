package se.culvertsoft.mnet.api

import java.util.ArrayList
import java.util.concurrent.ConcurrentHashMap

import scala.collection.JavaConversions.bufferAsJavaList
import scala.collection.JavaConversions.collectionAsScalaIterable
import scala.collection.JavaConversions.mapAsScalaConcurrentMap
import scala.collection.mutable.ArrayBuffer
import scala.reflect.ClassTag

import se.culvertsoft.mnet.IdCreateReply
import se.culvertsoft.mnet.IdCreateRequest
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeDisconnect
import se.culvertsoft.mnet.NodeSettings
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.api.util.NewNodeUUID

/**
 * Represents a local MNet node that can be connected to
 * an MNet network using one or more BackEnd objects.
 */
class Node(settings: NodeSettings = new NodeSettings) {

  /**
   * The unique NodeUUID of this node on the network.
   */
  val id = NewNodeUUID()

  /**
   * Currently detected neighbor nodes on the network.
   */
  private val neighbors = new ConcurrentHashMap[Connection, Route]

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
  private val connectionConsolidator = new ConnectionConsolidator(this, settings)

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
  def broadcast(msg: Message, filter: Connection => Boolean = _ => true): Node = {
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
   * @throws MNetException
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
   * Gets a route to the specified endpoint ID, or null if no route is known.
   */
  def getRoute(id: NodeUUID): Route = {
    routes.getOrElse(id, null)
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
  def handleError(error: Exception, source: Object) {
    error.printStackTrace()
  }

  /**
   * Called by the ConnectionConsolidator when a new message is received.
   */
  def handleMessage(message: Message, connection: Connection, route: Route) {

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
      .setName(settings.getName)
      .setTags(settings.getTags)
      .setSenderId(id)
  }

  /**
   * ****************************************
   *
   * 		For route providers to use
   *
   * ***************************************
   */

  def onConnect(connection: Connection) {
    connection.send(createAnnouncement())
  }

  /**
   * Default handling of a new NodeAnnouncement. Can be overloaded, but is usually not the case.
   * Only to be called by the ConnectionConsolidator.
   */
  def onAnnounce(msg: NodeAnnouncement, connection: Connection) {

    if (!msg.hasSenderId)
      throw new MNetException(s"${msg._typeName} from $connection missing senderId", connection)

    if (!routes.containsKey(msg.getSenderId)) {
      val route = new Route(msg.getSenderId, connection, msg)
      routes.put(msg.getSenderId, route)
      if (msg.getHops == 1 && !neighbors.containsKey(connection))
        neighbors.put(connection, route)
      handleConnect(route)
    }

    broadcast(msg, _ != connection)

  }

  /**
   * Default handling of a NodeDisconnect. Can be overloaded, but is usually not the case.
   * Only to be called by the ConnectionConsolidator.
   */
  def onRouteDisconnect(route: Route, reason: String, connection: Connection) {
    if (route != null && route.connection == connection) {
      routes.remove(route.endpointId)
      neighbors.remove(route.endpointId)
      broadcast(new NodeDisconnect().setReason(reason).setDisconnectedNodeId(route.endpointId), _ != connection)
      handleDisconnect(route, reason)
    }
  }

  /**
   * Default handling of a disconnected neighbor. Can be overloaded, but is usually not the case.
   * Only to be called by the ConnectionConsolidator.
   */
  def onNeighborDisconnect(reason: String, connection: Connection) {
    neighbors.remove(connection) match {
      case neighborRoute: Route =>
        // We remove the neighbor first so that the children's 
        // broadcasts are not sent back
        onRouteDisconnect(neighborRoute, reason, connection)
        for (route <- routes.values.filter(_.connection == connection))
          onRouteDisconnect(route, reason, connection)
      case _ =>
    }
  }

  /**
   * Default handling of a errors. Can be overloaded, but is usually not the case.
   * Only to be called by internal threads.
   */
  def onError(error: Exception, source: Object) {
    handleError(error, source)
  }

  /**
   * Default handling of a new message. Can be overloaded, but is usually not the case.
   * Only to be called by the ConnectionConsolidator.
   */
  def onMessage(msg: Message, connection: Connection) {

    incHops(msg)

    // check expected route to get this msg
    if (msg.hasSenderId) {
      val expectedRoute = getRoute(msg.getSenderId)
      if (expectedRoute != null && expectedRoute.connection != connection)
        return
    }

    msg match {
      case msg: NodeAnnouncement =>
        onAnnounce(msg, connection)
      case msg: IdCreateRequest =>
        connection.send(new IdCreateReply().setCreatedId(NewNodeUUID()))
      case msg: NodeDisconnect =>
        onRouteDisconnect(getRoute(msg.getDisconnectedNodeId), msg.getReason, connection)
      case msg =>
        // Targeted
        if (msg.hasTargetId) {
          if (msg.getTargetId == id) {
            handleMessage(msg, connection, getRoute(msg.getSenderId))
          } else {
            getRoute(msg.getTargetId) match {
              case route: Route => route.send(msg)
              case _ =>
            }
          }
        } // Broadcast
        else {
          handleMessage(msg, connection, getRoute(msg.getSenderId))
          broadcast(msg, _ != connection)
        }
    }

  }

  /**
   * Default send implementation.
   */
  protected def sendImpl(msg: Message): Node = {
    if (msg.getHops < msg.getMaxHops && msg.hasTargetId) {
      getRoute(msg.getTargetId) match {
        case route: Route => route.send(msg)
        case _ =>
      }
    }
    this
  }

  /**
   * Default broadcast implementation.
   */
  protected def broadcastImpl(
    msg: Message,
    filter: Connection => Boolean = _ => true): Node = {
    if (msg.getHops < msg.getMaxHops) {
      for ((connection, route) <- neighbors) {
        if (filter(connection) && route.endpointId != msg.getSenderId) {
          connection.send(msg)
        }
      }
    }
    this
  }

  private final def incHops(msg: Message) {
    if (!msg.hasHops())
      msg.setHops(0)
    if (!msg.hasMaxHops())
      msg.setMaxHops(settings.getMaxHopsDefault.toByte)
    if (msg.getMaxHops > settings.getMaxHopsLimit)
      msg.setMaxHops(settings.getMaxHopsLimit.toByte)
    msg.setHops((msg.getHops + 1).toByte)
  }

}