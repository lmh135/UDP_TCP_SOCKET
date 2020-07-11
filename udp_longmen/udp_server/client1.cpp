#include "MySocket.h"
#include <stdio.h>
#include <sys/socket.h>

char buff[1024]={0};

int main()
{
	Socket laser_capt_socket; 
	laser_capt_socket.UDPCreateServer("IPV4","UDP","192.168.122.1",9000);			
	laser_capt_socket.UDPReceivePackets(buff,strlen(buff)-1);
	printf("client say:%s\n",buff);

	return 0;
}
