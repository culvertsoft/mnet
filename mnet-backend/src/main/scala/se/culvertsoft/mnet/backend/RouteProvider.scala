package se.culvertsoft.mnet.backend

trait RouteProvider {
  def start(backEnd: NodeConnectionHandler): Unit
  def stop(): Unit
}