package se.culvertsoft.mnet.backend

import java.util.UUID

import se.culvertsoft.mnet.NodeUUID

object MkId {
  def apply() = {
    val uuid = UUID.randomUUID()
    new NodeUUID(uuid.getLeastSignificantBits, uuid.getMostSignificantBits)
  }
}