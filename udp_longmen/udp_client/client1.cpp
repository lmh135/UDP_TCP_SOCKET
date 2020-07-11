#include "MySocket.h"
#include <stdio.h>
#include <sys/socket.h>

char buff[1024]={0};

int main()
{
	Socket laser_capt_socket; 
	laser_capt_socket.UDPCreateClient("IPV4","UDP","192.168.122.1",9000);
	printf("client say:");
        scanf("%s",buff);	
	laser_capt_socket.UDPSendPackets(buff,strlen(buff));

	return 0;
}
