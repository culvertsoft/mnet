package se.culvertsoft.mnet.api

import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeUUID

/**
 * Represents a known route for sending a message to a given endpoint.
 * Nodes keep lookup-tables/routing-tables of NodeUUID -> Route pairs, which
 * are used when called to send messages to a specific Node on the network.
 *
 * Messages are routed through Routes and not necessarily directly to the endpoint.
 *
 * @param endpointId
 * 		The final destination that this Route represents. Note that if the message
 *   	doesn't have a supplied targetId, it will be treated as a broadcast and
 *    	hop on until the maxHops has been reached.
 *
 * @param connection
 * 		The underlying abstract connection which is used to transmit messages through.
 *
 * @param announcement
 * 		The original announcement which was received to create this Route.
 *
 */
case class Route(
  val endpointId: NodeUUID,
  val connection: Connection,
  val announcement: NodeAnnouncement) {

  /**
   * See Connection.send(..)
   */
  def send(msg: Message) {
    connection.send(msg)
  }

  /**
   * See Connection.isConnected()
   */
  def isConnected(): Boolean = {
    connection.isConnected()
  }

  /**
   * see Connection.hasBufferedData()
   */
  def hasBufferedData(): Boolean = {
    connection.hasBufferedData
  }

  /**
   * Returns the name received in the NodeAnnouncement
   */
  def name(): String = {
    announcement.getName()
  }

  /**
   * Returns the tags received in the NodeAnnouncement
   */
  def tags(): java.util.List[String] = {
    announcement.getTags()
  }

}