package se.culvertsoft.mnet.backend

trait RouteProvider {
  def start(backEnd: NodeCallbackIfc): Unit
  def stop(): Unit
}