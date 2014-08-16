package se.culvertsoft.mnet.api

import java.util.concurrent.ConcurrentLinkedQueue
import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.LinkedList

class MTCommandQue[CommandTarget](target: CommandTarget) {
  type Command = CommandTarget => Unit

  private var toLive = false
  private val cmds = new java.util.LinkedList[Command]

  private val thread = new Thread {
    override def run() {
      cmds.synchronized {
        while (toLive) {
          while (process(cmds.poll())) {}
          cmds.wait(10)
        }
      }
    }
  }

  private def process(cmd: Command): Boolean = {
    if (cmd != null) {
      try {
        cmd(target)
      } catch {
        case e: Exception => handleError(e)
      }
      true
    } else {
      false
    }
  }

  /**
   * Overload this
   */
  def handleError(e: Exception) {
    e.printStackTrace()
  }

  def start(): MTCommandQue[CommandTarget] = {
    toLive = true
    thread.start()
    this
  }

  def stop(): MTCommandQue[CommandTarget] = {
    cmds.synchronized {
      toLive = false
      cmds.notify()
    }
    this
  }

  def queCommand(cmd: Command) {
    cmds.synchronized {
      cmds.add(cmd)
      cmds.notify()
    }
  }

}