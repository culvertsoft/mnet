package se.culvertsoft.mnet.backend.util

import java.net.Socket

object ConfigureSocket {
  def apply(
    socket: Socket,
    useTcpNoDelay: Boolean) {
    socket.setTcpNoDelay(useTcpNoDelay)
    socket.setReuseAddress(true)
    socket.setSoLinger(true, 0)
    //socket.setSoLinger(false, 0)
  }
}