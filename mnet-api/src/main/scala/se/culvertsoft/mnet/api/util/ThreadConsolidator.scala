package se.culvertsoft.mnet.api.util

class ThreadConsolidator[CommandInput](
  input: CommandInput,
  waitTime: Int = 10) {
  type Command = CommandInput => Unit

  private var toLive = false
  private val cmds = new java.util.LinkedList[Command]

  private val thread = new Thread {
    override def run() {
      cmds.synchronized {
        while (toLive) {
          while (process(cmds.poll())) {}
          step(input)
          cmds.wait(waitTime)
        }
      }
    }
  }

  private def process(cmd: Command): Boolean = {
    if (cmd != null) {
      try {
        cmd(input)
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

  def start(): ThreadConsolidator[CommandInput] = {
    toLive = true
    thread.start()
    this
  }

  def stop(): ThreadConsolidator[CommandInput] = {
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

  def step(target: CommandInput) {
  }

}