
name := "mnet-javaclient"

organization := "se.culvertsoft"

version := scala.util.Properties.envOrElse("MNEN_BUILD_VERSION", "SNAPSHOT")

isSnapshot := version.value.contains("SNAPSHOT")

crossPaths := false

libraryDependencies += "se.culvertsoft" % "mnet-api" % version.value

libraryDependencies += "com.novocode" % "junit-interface" % "0.10" % Test

EclipseKeys.withSource := true

EclipseKeys.relativizeLibs := false
