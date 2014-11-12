
name := "mnet-api"

organization := "se.culvertsoft"

version := scala.util.Properties.envOrElse("MNET_BUILD_VERSION", "SNAPSHOT")

scalaVersion := "2.11.4"

isSnapshot := version.value.contains("SNAPSHOT")

resolvers += "Sonatype OSS Snapshots" at "https://oss.sonatype.org/content/repositories/snapshots"

publishMavenStyle := true

publishTo := {
  val nexus = "https://oss.sonatype.org/"
  if (isSnapshot.value)
    Some("snapshots" at nexus + "content/repositories/snapshots")
  else
    Some("releases"  at nexus + "service/local/staging/deploy/maven2")
}

pomIncludeRepository := { _ => false }

publishArtifact in Test := false

pomExtra := (
  <url>http://github.com/culvertsoft/mnet</url>
  <licenses>
    <license>
      <name>GPL 2</name>
      <url>https://github.com/culvertsoft/mnet/blob/master/LICENSE</url>
      <distribution>repo</distribution>
    </license>
  </licenses>
  <scm>
    <url>git@github.com:culvertsoft/mnet.git</url>
    <connection>scm:git:git@github.com:culvertsoft/mnet.git</connection>
  </scm>
  <developers>
    <developer>
      <id>PhroZenOne</id>
      <name>Mikael Berglund</name>
    </developer>
    <developer>
      <id>GiGurra</id>
      <name>Johan Kjölhede</name>
    </developer>
  </developers>)

crossPaths := false

unmanagedSourceDirectories in Compile += baseDirectory.value / "src_generated/main/java"

libraryDependencies += "se.culvertsoft" % "mgen-javalib" % version.value

libraryDependencies += "org.java-websocket" % "Java-WebSocket" % "1.3.0"

libraryDependencies += "com.novocode" % "junit-interface" % "0.10" % Test

EclipseKeys.withSource := true

EclipseKeys.relativizeLibs := false
