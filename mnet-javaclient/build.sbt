
name := "mnet-client"

organization := "se.culvertsoft"

version := scala.util.Properties.envOrElse("MNEN_BUILD_VERSION", "SNAPSHOT")

isSnapshot := version.value.contains("SNAPSHOT")

crossPaths := false

libraryDependencies += "se.culvertsoft" % "mnet-backend" % version.value

libraryDependencies += "com.novocode" % "junit-interface" % "0.10" % Test

EclipseKeys.withSource := true

EclipseKeys.relativizeLibs := false
