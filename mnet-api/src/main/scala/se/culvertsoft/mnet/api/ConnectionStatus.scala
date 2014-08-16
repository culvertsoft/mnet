package se.culvertsoft.mnet.api

abstract class ConnectionStatus

case object Connected extends ConnectionStatus
case object Connecting extends ConnectionStatus
case object Disconnected extends ConnectionStatus