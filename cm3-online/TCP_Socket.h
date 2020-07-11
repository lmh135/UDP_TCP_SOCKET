#ifndef _TCP_SOCKET_H_
#define _TCP_SOCKET_H_

#include <sys/types.h>  
#include <sys/socket.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/time.h>  
#include <sys/ioctl.h>  
#include <unistd.h>  
#include <netinet/in.h>
#include<arpa/inet.h>

#define MAX_QUE_CONN_NM	5

class TCP_Socket
{
	private:
	struct sockaddr_in server_sockaddr, client_sockaddr; 
	int server_fd, client_fd;
	socklen_t sin_size;
	
	 
	public:
	TCP_Socket()
	{ memset(&server_sockaddr,0,sizeof(server_sockaddr));
	  memset(&client_sockaddr,0,sizeof(client_sockaddr));}
	int TCPcreateClient(const char* IPAddress,int Port); //参数为服务器端的ip和端口号
	int TCPcreateServer(const char* IPAddress,int Port);//参数为客户的ip和端口号，一般客户ip为全网段
	
	int TCPReceivePackets(void* buf,int len_byte);
	int TCPSendPackets(void * buf, int len_byte);

	int Get_Server_SocketFD();
	int Get_Client_SocketFD();
};
















#endif
