package se.culvertsoft.mnet.backend

import se.culvertsoft.mnet.api.Connected
import se.culvertsoft.mnet.api.Connecting
import se.culvertsoft.mnet.api.ConnectionStatus
import se.culvertsoft.mnet.api.Disconnected

class NodeConnection {

  def status(): ConnectionStatus = {
    Disconnected
  }

  def isConnecting(): Boolean = {
    status == Connecting
  }

  def isConnected(): Boolean = {
    status == Connected
  }

  def isDisconnected(): Boolean = {
    status == Disconnected
  }
  
  def close() {
    
  }

}