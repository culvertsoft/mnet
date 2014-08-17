package se.culvertsoft.mnet.api

/**
 * Scala-esque "enum class" that represents connection states.
 * 
 * Used this way:
 * 		val state = foo.getConnectionStatus()
 *   	state match {
 *    		case Connected => ...
 *      	case Connecting => ...
 *       	case Disconnected => ...
 *    	}
 */
abstract class ConnectionStatus

case object Connected extends ConnectionStatus
case object Connecting extends ConnectionStatus
case object Disconnected extends ConnectionStatus