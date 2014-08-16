package se.culvertsoft.mnet.api

import se.culvertsoft.mnet.Message

trait Connection {
  def send(msg: Message)
}