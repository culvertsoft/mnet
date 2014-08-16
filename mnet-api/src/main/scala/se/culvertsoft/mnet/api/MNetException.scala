package se.culvertsoft.mnet.api

import java.lang.Exception

class MNetException(
  val msg: String,
  val reason: Exception,
  val connection: AnyRef) extends RuntimeException(msg, reason) {
  def this(msg: String, connection: AnyRef) = this(msg, null, connection)
  def this(reason: Exception, connection: AnyRef) = this("", reason, connection)
}