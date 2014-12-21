MNet
====

WARNING: This project is in very early development and is not intended for public testing/evaluation!

MNet might turn into something like a data format-, transport layer- and programming language agnostic communication library. An experimental scala+Cpp-implementation exists today based on websockets. Websockets are selected for their simple message-based API as well as having a standard that may be leveraged from virtually any programming language and platform.

The vision is to easily be able to connect applications to your own persistent network of nodes, where you may announce services as well as send custom messages (byte arrays and/or strings) to all of or a subset of known nodes. It can also be used a simple server-client skeleton for you to manage, for example for game servers and similar applications.

MNet can be seen as a follow-up of [mgen](https://github.com/culvertsoft/mgen), but MNet will have NO requirements for you to use MGen as the data format.

Building MNet is a mess right now (so don't do it! Wait at least until beta release):
  * Install MGen (follow the instructions at [culvertsoft.github.io/mgen](http://culvertsoft.github.io/mgen/))
  * Execute 'python build.py -b' in your checked out MNet repo

For now MNet is available here under GPLv2, but eventually it will probably be released with an MIT license (like MGen).
