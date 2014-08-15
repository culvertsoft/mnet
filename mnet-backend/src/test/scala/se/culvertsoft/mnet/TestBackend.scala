package se.culvertsoft.mnet

import org.junit.Test
import se.culvertsoft.mnet.api.ReconnectingWebsocket
import se.culvertsoft.mnet.backend.BackendConfiguration
import se.culvertsoft.mnet.backend.Node
import se.culvertsoft.mnet.backend.WebSockProvider
import se.culvertsoft.mnet.backend.WebsockSerializer
import se.culvertsoft.mnet.backend.Route
import scala.collection.mutable.ArrayBuffer

object TestBackend {

  val serializer = new WebsockSerializer

  private var testPort = 80
  def getTestPort(): Int = synchronized {
    val out = testPort
    testPort += 1
    out
  }

  def getTestCfg(): BackendConfiguration = {
    new BackendConfiguration().setListenPort(getTestPort)
  }

  def newNode(msgHandler: Message => Unit = _ => Unit): Node = {
    val settings = getTestCfg
    new Node() {
      override def handleMessage(message: Message, route: Option[Route]) {
        msgHandler(message)
      }
    }.addRouteProvider(new WebSockProvider(settings))
  }

}

class TestBackend {
  import TestBackend._

  @Test
  def canCreateNode() {
    val b = TestBackend.newNode()
  }

  @Test
  def canCloseBackend() {
    val b = TestBackend.newNode().start()
    Thread.sleep(100)
    b.stop()
    Thread.sleep(100)
  }

  @Test
  def canConnectToBackend() {

    val b = TestBackend.newNode().start()
    val port = b.getProvider[WebSockProvider].listenPort

    @volatile var gotMsg: Message = null

    val ws = new ReconnectingWebsocket("localhost", port) {
      override def onTextMessage(jsonMsg: String) {
        gotMsg = serializer.deserializeJson(jsonMsg)
      }
    }.start()

    Thread.sleep(500)
    assert(ws.isConnected)
    ws.stop()
    b.stop()
    Thread.sleep(100)
    assert(ws.isDisconnected)
    assert(gotMsg.isInstanceOf[NodeAnnouncement])

  }

  @Test
  def canAnnounceOnBackend() {

    var b1GotMsg = false
    var b2GotMsg = false

    val b1 = TestBackend.newNode(msg => b1GotMsg = true).start()
    val b2 = TestBackend.newNode(msg => b2GotMsg = true).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]

    Thread.sleep(100)

    assert(b1.viewRoutes.isEmpty)
    assert(b2.viewRoutes.isEmpty)

    ws1.addOutboundConnection(ws2.listenPort)

    Thread.sleep(100)

    assert(b1.viewRoutes.nonEmpty)
    assert(b2.viewRoutes.nonEmpty)

  }

  @Test
  def canSendEachOtherMessages() {

    val b1Msgs = new ArrayBuffer[Message]
    val b2Msgs = new ArrayBuffer[Message]

    val b1 = TestBackend.newNode(b1Msgs += _).start()
    val b2 = TestBackend.newNode(b2Msgs += _).start()

    val ws1 = b1.getProvider[WebSockProvider]
    val ws2 = b2.getProvider[WebSockProvider]

    Thread.sleep(100)

    assert(b1.viewRoutes.isEmpty)
    assert(b2.viewRoutes.isEmpty)

    ws1.addOutboundConnection(ws2.listenPort)

    Thread.sleep(100)

    assert(b1.viewRoutes.nonEmpty)
    assert(b2.viewRoutes.nonEmpty)

    val errMsgSentByB1 = new ErrorMessage().setMsg("ErrorFromB1")
    val errMsgSentByB2 = new ErrorMessage().setMsg("ErrorFromB2")
    
    b1.broadcastJson(errMsgSentByB1)
    b2.broadcastJson(errMsgSentByB2)
    
    Thread.sleep(100)
    
    assert(b1Msgs.size ==1)
    assert(b2Msgs.size ==1)
    
    
  }
  
}