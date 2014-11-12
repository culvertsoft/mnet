
// Remember, sbt needs empty lines between active settings

name := "mnet"

organization := "se.culvertsoft"

resolvers += "Sonatype OSS Snapshots" at "https://oss.sonatype.org/content/repositories/snapshots"

version := scala.util.Properties.envOrElse("MNET_BUILD_VERSION", "SNAPSHOT")

scalaVersion := "2.11.4"

isSnapshot := version.value.contains("SNAPSHOT")

crossPaths := false

parallelExecution in Test := false

lazy val mnet_api = project in file("mnet-api")

lazy val mnet_backend = (project in file("mnet-backend")).dependsOn(mnet_api)

lazy val mnet_javaclient = (project in file("mnet-javaclient")).dependsOn(mnet_backend)

// cppclient handled elsewhere
