package se.culvertsoft.mnet.backend

import java.net.InetSocketAddress
import java.net.URI

import scala.collection.JavaConversions.asScalaBuffer
import scala.collection.mutable.ArrayBuffer

import se.culvertsoft.mnet.api.BackEnd
import se.culvertsoft.mnet.api.ConnectionConsolidator
import se.culvertsoft.mnet.api.MNetException

/**
 * Back-end implementation using websockets.
 * The default back-end implementation in MNet.
 */
class WebSockBackEnd(settings: WebsockBackendSettings) extends BackEnd {

  /**
   * Used to consolidate all the inputs from multiple back-ends and their
   * slave threads to a single event handling thread. This is provided
   * by the parent Node when start(..) is called.
   */
  private var connectionHandler: ConnectionConsolidator = null

  /**
   * All the interfaces that we are currently listening on. At this point
   * the mnet websocket back-end only supports listening on all network interfaces,
   * but in the future you will be able to select a subset of available
   * network interfaces if you want to.
   */
  private val listeningIfcs = new ArrayBuffer[WebsockInHandler]

  /**
   * Represents outbound connection attempts as configured by this class'
   * settings parameter. For each item in the WebsockBackendSettins connectTo
   * list, one WebsockOutHandler will be started and placed here.
   */
  private val connectingTo = new ArrayBuffer[WebsockOutHandler]

  /**
   * Starts this back-end. See BackEnd.start(..).
   *
   * Opens up a listener interface on the port specified in the settings parameter when
   * this back-end was created.
   *
   * Opens up one outbound connection for each specified connection target in the
   * settings parameter given when this back-end was started.
   *
   * Starts any internal helper threads.
   *
   * @throw MNetException
   * 	If this back-end is already started
   */
  override def start(handler_in: ConnectionConsolidator) {
    if (isStarted)
      throw new MNetException("Tried to start BackEnd Twice!")
    connectionHandler = handler_in

    if (settings.hasListenPort())
      listeningIfcs += new WebsockInHandler(connectionHandler, new InetSocketAddress(settings.getListenPort), settings.getUseTcpNodelay)

    for (addr <- settings.getConnectTo)
      connectingTo += new WebsockOutHandler(connectionHandler, new URI(addr), settings.getUseTcpNodelay(), 0)

    listeningIfcs.foreach(_.start())
    connectingTo.foreach(_.start())

  }

  /**
   * See BackEnd.isStarted()
   */
  override def isStarted(): Boolean = {
    connectionHandler != null
  }

  /**
   * See BackEnd.stop()
   */
  override def stop() {
    connectingTo.foreach(_.stop())
    listeningIfcs.foreach(_.stop())
  }

  /**
   * Always returns false. This back-end does not support restart. However all internal
   * outbound connections will automatically try to reconnect if a connection is lost, unless
   * configured to do otherwise (in the settings parameter provided when this back-end was started)
   */
  override def isRestartSupported(): Boolean = {
    false
  }

  /**
   * Returns the port that this back-end is listening on for incoming connections.
   */
  def listenPort(): Int = {
    settings.getListenPort()
  }

  /**
   * Can be used both before and after calling start(..). Adds an additional outbound connection
   * address. It will be treated like any other outbound connection.
   */
  def addOutboundConnection(uri: String) {
    if (connectionHandler != null) {
      val handler = new WebsockOutHandler(connectionHandler, new URI(uri), settings.getUseTcpNodelay(), 0)
      connectingTo += handler
      handler.start()
    } else {
      settings.getConnectTo().add(uri)
    }
  }

  /**
   * See addOutboundConnection(String)
   */
  def addOutboundConnection(addr: String, port: Int) {
    addOutboundConnection(s"ws://$addr:$port")
  }

  /**
   * See addOutboundConnection(String)
   */
  def addOutboundConnection(port: Int) {
    addOutboundConnection("127.0.0.1", port)
  }

}