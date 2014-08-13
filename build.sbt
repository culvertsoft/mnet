
// Remember, sbt needs empty lines between active settings

name := "mnet"

organization := "se.culvertsoft"

version := scala.util.Properties.envOrElse("MNET_BUILD_VERSION", "SNAPSHOT")

isSnapshot := version.value.contains("SNAPSHOT")

crossPaths := false

lazy val mnet_api = project in file("mnet-api")

lazy val mnet_backend = (project in file("mnet-backend")).dependsOn(mnet_api)

lazy val mnet_javaclient = (project in file("mnet-javaclient")).dependsOn(mnet_api)

// cppclient handled elsewhere
