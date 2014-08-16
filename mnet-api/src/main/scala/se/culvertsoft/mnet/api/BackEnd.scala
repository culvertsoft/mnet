package se.culvertsoft.mnet.api

trait BackEnd {
  def start(backEnd: ConnectionConsolidator): Unit
  def stop(): Unit
}