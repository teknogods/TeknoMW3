#ifndef __DW_STUN_SERVER_H__
#define __DW_STUN_SERVER_H__

extern short StunServerPort;
extern char  StunServerHost[32];

void StartStunServer();
void StartIpDiscovery();

#endif //__DW_STUN_SERVER_H__