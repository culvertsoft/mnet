
name := "mnet-api"

organization := "se.culvertsoft"

version := scala.util.Properties.envOrElse("MNEN_BUILD_VERSION", "SNAPSHOT")

isSnapshot := version.value.contains("SNAPSHOT")

crossPaths := false

unmanagedSourceDirectories in Compile += baseDirectory.value / "src_generated/main/java"

libraryDependencies += "se.culvertsoft" % "mgen-javalib" % version.value

libraryDependencies += "org.java-websocket" % "Java-WebSocket" % "1.3.0"

libraryDependencies += "com.novocode" % "junit-interface" % "0.10" % Test

EclipseKeys.withSource := true

EclipseKeys.relativizeLibs := false
