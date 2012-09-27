#!/usr/bin/python
from __future__ import with_statement, print_function
import sys
import os
import struct
import socket
import time

from twisted.internet.protocol import Protocol, ServerFactory
from twisted.internet.task import LoopingCall
from twisted.python import log
from twisted.application import service, internet
from twisted.python.log import ILogObserver, FileLogObserver
from twisted.python.logfile import DailyLogFile

def read_struct(fmt, data):
   return struct.unpack_from(fmt, data), data[struct.calcsize(fmt):]

class MW3Master(Protocol):
   MW3_MS_SERVER_MAGIC4CC = 0x424f4f42
   MW3_MS_CLIENT_MAGIC4CC = 0x434f4b45

   def dataReceived(self, data):
      (magic, version), data = read_struct("II", data)
      vList = self.factory.serverLists.setdefault(version, {})

      # ignore old clients
      if version == 17039742:
         self.transport.loseConnection()
         return

      # TODO Use Deferreds if anything in here takes a substantial amount of processing time,
      # else we will push up the server's response time.

      if magic == self.MW3_MS_SERVER_MAGIC4CC:
         (port, ), data = read_struct("H", data)
         ip = self.transport.getPeer().host
         #print("SERVER_MAGIC Ip: %s, Port: %d, Version: %08X" % (ip, port, version))
         vList[(ip, port)] = time.time()

      elif magic == self.MW3_MS_CLIENT_MAGIC4CC:
         #print("CLIENT_MAGIC Version: %08X" % (version,))
         reply = struct.pack("I", len(vList))
         for (ip, port) in vList.iterkeys():
            reply += struct.pack("IH", struct.unpack('>I', socket.inet_aton(ip))[0], port)
         #print('sending %r' % (reply,))
         self.transport.write(reply)
      self.transport.loseConnection()

MW3_MS_LISTEN_PORT = 27017

class MW3MasterFactory(ServerFactory):
   protocol = MW3Master
   lastPrune = 0

   def pruneList(self):
      now = time.time()
      for serverList in self.serverLists.values():
         for ((ip, port), last) in serverList.items():
            if last < self.lastPrune:
               del serverList[(ip, port)]
               log.msg('%s:%s expired (active servers left: %d)' % (ip, port, len(serverList)))
      self.lastPrune = now

   def startFactory(self):
      self.serverLists = {}
      LoopingCall(self.pruneList).start(30)

print("TeknoMW3 Master Server v1.0f")

application = service.Application('MW3 Master')
#application.setComponent(ILogObserver, FileLogObserver(DailyLogFile(os.path.join(os.path.dirname(__file__), 'mw3master.log'))).emit)

service = internet.TCPServer(MW3_MS_LISTEN_PORT, MW3MasterFactory())
service.setServiceParent(application)
