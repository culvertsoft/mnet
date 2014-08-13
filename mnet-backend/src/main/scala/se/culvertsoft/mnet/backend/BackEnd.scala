package se.culvertsoft.mnet.backend

object BackEnd {

  val DEFAULT_PORT = 6537

  def main(args: Array[String]) {
    //TODO: Parse args...maybe just a config file name?
    val settings = new BackendConfiguration
    new BackEnd(settings).run()
  }

}

class BackEnd(settings: BackendConfiguration) {
  val port = if (settings.hasPort) settings.getPort else BackEnd.DEFAULT_PORT
  
  def run() {
  }
  
}