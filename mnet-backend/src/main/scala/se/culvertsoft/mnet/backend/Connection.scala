package se.culvertsoft.mnet.backend

import se.culvertsoft.mnet.Message

trait Connection {
  def sendJson(msg: Message)
  def sendBinary(msg: Message)
  def sendPreferred(msg: Message)
}