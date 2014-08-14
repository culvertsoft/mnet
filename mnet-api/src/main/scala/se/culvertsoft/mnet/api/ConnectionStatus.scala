package se.culvertsoft.mnet.api

abstract class ConnectionStatus(val isConnected: Boolean)

case object Connected extends ConnectionStatus(true)
case object Connecting extends ConnectionStatus(false)
case object Disconnected extends ConnectionStatus(false)