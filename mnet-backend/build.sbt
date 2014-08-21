
name := "mnet-backend"

organization := "se.culvertsoft"

version := scala.util.Properties.envOrElse("MNET_BUILD_VERSION", "SNAPSHOT")

isSnapshot := version.value.contains("SNAPSHOT")

resolvers += "Sonatype OSS Snapshots" at "https://oss.sonatype.org/content/repositories/snapshots"

crossPaths := false

unmanagedSourceDirectories in Compile += baseDirectory.value / "src_generated/main/java"

libraryDependencies += "se.culvertsoft" % "mnet-api" % version.value

libraryDependencies += "com.novocode" % "junit-interface" % "0.10" % Test

EclipseKeys.withSource := true

EclipseKeys.relativizeLibs := false
