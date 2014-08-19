package se.culvertsoft.mnet.client

import scala.collection.JavaConversions.seqAsJavaList

import se.culvertsoft.mnet.DataMessage
import se.culvertsoft.mnet.Message
import se.culvertsoft.mnet.NodeAnnouncement
import se.culvertsoft.mnet.NodeSettings
import se.culvertsoft.mnet.NodeUUID
import se.culvertsoft.mnet.api.Connection
import se.culvertsoft.mnet.api.Route
import se.culvertsoft.mnet.backend.WebSockBackEnd
import se.culvertsoft.mnet.backend.WebsockBackendSettings

/**
 * The default constructor will simply set up a local host node.
 * It will not try to create any outgoing connections.
 *
 * If you want to set up anything more advanced, you should
 * provide settings of your own. There are also a few
 * auxilliary constructors for convenience.
 */
class MNetClient(
  wsSettings: WebsockBackendSettings = new WebsockBackendSettings,
  nodeSettings: NodeSettings = new NodeSettings) {

  /**
   * Creates an outgoing (only) connection to specified network target
   */
  def this(
    addr: String,
    port: Int) = this(MNetClient.makeWsSettings(addr, port))

  /**
   * Creates a named outgoing (only) connection to specified network target
   */
  def this(
    name: String,
    addr: String,
    port: Int) = this(MNetClient.makeWsSettings(addr, port), MNetClient.makeNodeSettings(name, Nil))

  /**
   * Creates a named and tagged outgoing (only) connection to specified network target
   */
  def this(
    name: String,
    tags: java.util.Collection[String],
    addr: String,
    port: Int) = this(MNetClient.makeWsSettings(addr, port), MNetClient.makeNodeSettings(name, tags))

  /**
   * ********************************************
   *
   *
   * 		FIELDS
   *
   * *******************************************
   */

  private val node = new MNetClientNode(this, nodeSettings)
  node.addBackEnd(new WebSockBackEnd(wsSettings))

  /**
   * ********************************************
   *
   *
   * 		PUBLIC API
   *
   * *******************************************
   */

  def id(): NodeUUID = {
    node.id
  }

  def start(): MNetClient = {
    node.start()
    this
  }

  def stop(): MNetClient = {
    node.stop()
    this
  }

  def send(message: Message): MNetClient = {
    if (!message.hasSenderId)
      message.setSenderId(id)
    node.send(message)
    this
  }

  def send(msgContents: String, targetId: NodeUUID): MNetClient = {
    send(new DataMessage()
      .setSenderId(node.id)
      .setTargetId(targetId)
      .setStringData(msgContents))
  }

  def send(msgContents: Array[Byte], targetId: NodeUUID): MNetClient = {
    send(new DataMessage()
      .setSenderId(node.id)
      .setTargetId(targetId)
      .setBinaryData(msgContents))
  }

  def broadcast(message: Message): MNetClient = {
    send(message.setTargetId(null))
  }

  def broadcast(msgContents: String): MNetClient = {
    send(msgContents, null)
  }

  def broadcast(msgContents: Array[Byte]): MNetClient = {
    send(msgContents, null)
  }

  def getRoutes(): java.util.List[Route] = {
    node.getRoutes
  }

  /**
   * ********************************************
   *
   *
   * 		OVERRIDEABLES
   *
   * *******************************************
   */

  protected[client] def handleConnect(route: Route) {
    println(s"$this got route to $route")
  }

  protected[client] def handleDisconnect(route: Route, reason: String) {
    println(s"$this lost route to $route")
  }

  protected[client] def handleError(error: Exception, source: Object) {
    error.printStackTrace()
  }

  protected[client] def handleMessage(message: Message, connection: Connection, route: Route) {
    println(s"$this got ${message._typeName} from $connection")
  }

  protected[client] def createAnnouncement(): NodeAnnouncement = {
    new NodeAnnouncement()
      .setName(nodeSettings.getName)
      .setTags(nodeSettings.getTags)
      .setSenderId(node.id)
  }

}

object MNetClient {

  def makeWsSettings(connectToUrl: String): WebsockBackendSettings = {
    val out = new WebsockBackendSettings
    out.getConnectTo().add(connectToUrl)
    out.unsetListenPort()
    out
  }

  def makeWsSettings(connectToAddr: String, connectToPort: Int): WebsockBackendSettings = {
    makeWsSettings(s"ws://$connectToAddr:$connectToPort")
  }

  def makeNodeSettings(name: String, tags: java.util.Collection[String]): NodeSettings = {
    val out = new NodeSettings
    out.setName(name)
    out.setTags(new java.util.ArrayList(tags))
    out
  }

  /**
   * ********************************************
   *
   *
   * 		IF USED AS APPLICATION
   *
   * *******************************************
   */

  def main(args: Array[String]) {
    val port =
      if (args.nonEmpty) {
        args(0).toInt
      } else {
        80
      }
    new MNetClient(new WebsockBackendSettings().setListenPort(port)).start()
  }

}

