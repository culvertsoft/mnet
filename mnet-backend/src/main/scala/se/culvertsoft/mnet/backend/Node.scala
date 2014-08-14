package se.culvertsoft.mnet.backend

import scala.collection.mutable.ArrayBuffer

import org.java_websocket.WebSocket

import se.culvertsoft.mnet.NetworkId

class Node(val id: NetworkId) {
  private val connections = new ArrayBuffer[NodeConnection]

  def init(connectTo: String, backEnd: BackEnd): Node = {
    this
  }

  def init(backEnd: BackEnd): Node = {
    this
  }

  def removeConnection(connection: WebSocket) {
	  // TODO: Impl
  }
  
  def close() {
    connections.foreach(_.close())
  }

}