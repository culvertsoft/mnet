package se.culvertsoft.mnet.api

import java.lang.Exception

/**
 * Represents an exception thrown somewhere by the MNet layer.
 * May contain information about what connection the exception
 * originated from.
 */
class MNetException(
  val msg: String,
  val reason: Exception,
  val connection: AnyRef) extends RuntimeException(msg, reason) {
  def this(msg: String) = this(msg, null, null)
  def this(msg: String, connection: AnyRef) = this(msg, null, connection)
  def this(reason: Exception, connection: AnyRef) = this("", reason, connection)
}