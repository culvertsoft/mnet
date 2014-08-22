MNet
====

WARNING: This project is in its infant stage and is not yet intended to be used, not even for testing/evaluation! Release is scheduled to be some time after our sister project [mgen](https://github.com/culvertsoft/mgen).

MNet will be a data format-, transport layer- and programming language agnostic software network infrastructure provider. A default transport layer implemenation will be written using websockets. Websockets are selected for their simple message-based API as well as having a standard that may be leveraged from virtually any programming language and platform.

MNet will allow you to connect applications to a persistent network of nodes, where you may announce services as well as send custom messages (byte arrays and/or strings) to all of or a subset of known nodes. It can also be used a simple server-client skeleton for you to manage, for example for game servers and similar applications.

MNet can be seen as a follow-up and sister product of [mgen](https://github.com/culvertsoft/mgen), and will follow MGen's dual licensing model of GPLv2 + a future license that is more commercially compatible.

MNet will have NO requirements for you to use MGen as the data format, as they are two completely separate projects.

The steps for MNet is a mess right now (so don't do it! Wait at least until beta release):
1. Build MGen so sbt publishes the mgen jars to your local ivy reposityro
2. Use the MGen installer script (in mgen/mgen-installers/) and set the required environmental variables
3. call 'python build.py -b' in your checked out MNet repo

The c++ library is header-only, but to build the c++ tests, you currently have to do this manually, there's a CMakeLists.txt available.

Like MGen, MNet is available from oss sonatype professional.
