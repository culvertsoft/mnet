package se.culvertsoft.mnet.backend

trait RouteProvider {
  def start(backEnd: NodeIfc): Unit
  def stop(): Unit
}