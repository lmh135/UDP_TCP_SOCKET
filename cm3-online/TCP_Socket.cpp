#include "TCP_Socket.h"






int TCP_Socket::TCPcreateServer(const char* IPAddress,int Port)
{
	/*建立socket连接*/  
   	if ((server_fd = socket(AF_INET,SOCK_STREAM,0))== -1)  
    	{  
       		perror("socket");  
        	exit(1);  
    	}
	/*设置sockaddr_in 结构体中相关参数*/  
    	server_sockaddr.sin_family = AF_INET;  
    	server_sockaddr.sin_port = htons(Port);  
    	server_sockaddr.sin_addr.s_addr = INADDR_ANY;  
    	bzero(&(server_sockaddr.sin_zero), 8);

	int i = 1;/* 使得重复使用本地地址与套接字进行绑定 */  
    	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));

	/*绑定函数bind*/  
    	if (bind(server_fd, (struct sockaddr *)&server_sockaddr, sizeof(struct sockaddr))== -1)  
    	{  
        	perror("bind");  
        	exit(1);  
    	} 

	/*调用listen函数*/  
    	if (listen(server_fd, MAX_QUE_CONN_NM) == -1)  
    	{  
        	perror("listen");  
        	exit(1);  
    	}  
    	printf("Listening....\n");

	/*调用accept函数，等待客户端的连接*/  
    	if ((client_fd = accept(server_fd, (struct sockaddr *)&client_sockaddr, &sin_size)) == -1)  
    	{  
        	perror("accept");  
        	exit(1);  
    	} 
	return 0;
}

int TCP_Socket::TCPcreateClient(const char* IPAddress,int Port)
{
	/*创建socket*/  
    	if ((client_fd = socket(AF_INET,SOCK_STREAM,0)) == -1)  
    	{  
        	perror("socket");  
        	exit(1);  
    	} 
	/*设置sockaddr_in 结构体中相关参数*/  
    	server_sockaddr.sin_family = AF_INET;  
    	server_sockaddr.sin_port = htons(Port);  
    	server_sockaddr.sin_addr.s_addr = inet_addr(IPAddress);  
    	bzero(&(server_sockaddr.sin_zero), 8);  

	/*调用connect函数主动发起对服务器端的连接*/  
    	if(connect(client_fd,(struct sockaddr *)&server_sockaddr, sizeof(struct sockaddr))== -1)  
    	{  
        	perror("connect");  
        	exit(1);  
    	}  
      	return 0;
}

int TCP_Socket::TCPReceivePackets(void* buf,int len_byte)
{
	int recvbytes = 0; 
	if ((recvbytes = recv(client_fd, (char*)buf, len_byte, 0)) == -1)  
    	{  
        	perror("recv");  
        	exit(1);  
    	} 
	return recvbytes;
}

int TCP_Socket::TCPSendPackets(void* buf, int len_byte)
{
	int sendbytes = 0;
	if ((sendbytes = send(client_fd, (char*)buf, len_byte, 0)) == -1)  
    	{  
        	perror("send");  
        	exit(1);  
    	} 
	return sendbytes;
}

int TCP_Socket::Get_Server_SocketFD()
{
	return this->server_fd;
}

int TCP_Socket::Get_Client_SocketFD()
{
	return this->client_fd;
}




