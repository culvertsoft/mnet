package se.culvertsoft.mnet.backend

object Main {

  def main(args: Array[String]): Unit = {
    //TODO: Parse args...maybe just a config file name?
    val settings = new BackendConfiguration
    new BackEnd(settings).start()
  }

}