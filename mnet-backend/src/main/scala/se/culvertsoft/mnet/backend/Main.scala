package se.culvertsoft.mnet.backend

import se.culvertsoft.mnet.NodeSettings
import se.culvertsoft.mnet.api.Node

object Main {

  def main(args: Array[String]): Unit = {
    //TODO: Parse args...maybe just a config file name?
    val nodeSettings = new NodeSettings
    val backEndSettings = new WebsockBackendSettings
    new Node(nodeSettings)
      .addBackEnd(new WebSockBackEnd(backEndSettings))
      .start()
  }

}