package se.culvertsoft.mnet.api

import se.culvertsoft.mnet.Message

/**
 * Represents an abstract connections as provided by a BackEnd.
 * Connections are usually handled by the Node's ConnectionConsolidator.
 */
trait Connection {

  /**
   * Attempts to send a message to this connection. The back-end implementation
   * that provided this Connection may allow you to send on the current thread
   * or use an internal thread to handle the sending.
   *
   * So calling this function could result in virtually any exception, though
   * checking for MNetExceptions and IOExceptions should be sufficient.
   */
  def send(msg: Message)

  /**
   * Returns if this connection is currently connected.
   */
  def isConnected(): Boolean

  /**
   * Returns if there are currently messages queued to be sent out on this connection.
   */
  def hasBufferedData(): Boolean

}