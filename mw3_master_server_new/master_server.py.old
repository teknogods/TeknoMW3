#!/usr/bin/python
from __future__ import with_statement, print_function
import struct
import socket
import threading
import time

from twisted.internet import reactor, protocol
from twisted.internet.endpoints import TCP4ServerEndpoint

serversList = {}
serversLock = threading.Lock()

def read_struct(fmt, data):
   return struct.unpack_from(fmt, data), data[struct.calcsize(fmt):]


class ExpireThread(threading.Thread):
   
   def __init__(self):
      threading.Thread.__init__(self)
      
   def run(self):
      while(True):
         time.sleep(1)   #seconds
         with serversLock:
            for serverList in serversList.values():
               serverList.expire()

class ServerList:
   MW3_MS_CLEANUP_RATE = 30      #seconds

   def __init__(self):
      self.lock = threading.Lock()
      self.known = {}

   def heartbeat(self, ip, port):
      with self.lock:
         self.known[(ip, port)] = time.time()
         
   def expire(self):
      now = time.time()
      with self.lock:
         for (key, last) in self.known.items():
            diff = now - last
            if diff >= self.MW3_MS_CLEANUP_RATE:
               del self.known[key]
               (ip, port) = key
               print('%s:%s expired (active servers left: %d)' % (ip, port, len(self.known)))
   
   def getKnown(self):
      with self.lock:
         return self.known.copy()
                        
class MW3Master(protocol.Protocol):
   MW3_MS_SERVER_MAGIC4CC = 0x424f4f42
   MW3_MS_CLIENT_MAGIC4CC = 0x434f4b45

   def dataReceived(self, data):
      (magic,), data = read_struct("I", data)

      if magic == self.MW3_MS_SERVER_MAGIC4CC:
         (version, port), data = read_struct("IH", data)
         ip = self.transport.getPeer().host
         #print("SERVER_MAGIC Ip: %s, Port: %d, Version: %08X" % (ip, port, version))
         self.getServerList(version).heartbeat(ip, port)

      elif magic == self.MW3_MS_CLIENT_MAGIC4CC:
         (version,), data = read_struct("I", data)
         #print("CLIENT_MAGIC Version: %08X" % (version,))
         known = self.getServerList(version).getKnown()
         reply = struct.pack("I", len(known))
         for (ip, port) in known:
            reply += struct.pack("IH", struct.unpack('>I', socket.inet_aton(ip))[0], port)
         #print('sending %r' % (reply,))
         self.transport.write(reply)
      self.transport.loseConnection()

   def getServerList(self, version):
      with serversLock:
         try:
            return serversList[version]
         except:
            serverList = ServerList()
            serversList[version] = serverList
            return serverList


def main():
   expireThread = ExpireThread()
   expireThread.start()
   MW3_MS_LISTEN_PORT = 27017

   print("TeknoMW3 Master Server v1.0d")
   print("============================")
   print("")
   print("Listening to connections")
   print("")
   factory = protocol.ServerFactory()
   factory.protocol = MW3Master
   endpoint = TCP4ServerEndpoint(reactor, MW3_MS_LISTEN_PORT)
   endpoint.listen(factory)
   reactor.run()

if __name__ == '__main__':
   main()
