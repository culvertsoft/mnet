package se.culvertsoft.mnet.backend

abstract class SourceType
case object SourceUndetermined extends SourceType
case object SourceNode extends SourceType
case object SourceClient extends SourceType