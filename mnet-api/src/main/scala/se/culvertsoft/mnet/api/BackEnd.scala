package se.culvertsoft.mnet.api

/**
 * Interface for all back-end implementations.
 * Provides Connections and subsequently Routes to the Node class.
 */
trait BackEnd {

  /**
   * Starts this back-end and any internal threads it might use.
   */
  def start(backEnd: ConnectionConsolidator): Unit

  /**
   * Stops this back-end, closes all of its connections and stops
   * any internal threads it might use
   */
  def stop(): Unit

  /**
   * Returns if this back-end is currently running or not.
   */
  def isStarted(): Boolean

  /**
   * Returns if this back-end supports restarting after having been stopped.
   * Generally speaking, restarting back-ends is usually not supported. However
   * back-ends should implement reconnect functionality internally.
   */
  def isRestartSupported(): Boolean

}