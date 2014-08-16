package se.culvertsoft.mnet.api.util

import java.util.UUID

import se.culvertsoft.mnet.NodeUUID

object NewNodeUUID {
  def apply(): NodeUUID = {
    val uuid = UUID.randomUUID()
    new NodeUUID(uuid.getLeastSignificantBits(), uuid.getMostSignificantBits())
  }
}