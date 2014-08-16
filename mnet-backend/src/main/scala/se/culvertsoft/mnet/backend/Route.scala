package se.culvertsoft.mnet.backend

import org.java_websocket.WebSocket

import se.culvertsoft.mnet.NodeUUID

case class Route(
  val endpointId: NodeUUID,
  val connection: Connection)