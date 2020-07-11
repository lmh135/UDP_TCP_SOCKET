#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{    
	//1.创建套接字
	int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);    
	if(sockfd<0)
	{   
		perror("socket error");
		return -1; 
	}   
	//2.绑定：客户端程序不推荐绑定地址
	//3.向服务端发起连接请求
	struct sockaddr_in serv_addr;
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(9000);
	serv_addr.sin_addr.s_addr=inet_addr("192.168.122.1");
	//#include <sys/types.h>          /* See NOTES */
	//#include <sys/socket.h>
	//int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
	//      sockfd:套接字描述符
	//      addr:要连接的服务器地址
	//      addrlen：地址信息长度
	//      返回值：成功返回0，失败返回-1
	socklen_t len=sizeof(struct sockaddr_in);
	int ret=connect(sockfd,(struct sockaddr*)&serv_addr,len);
	if(ret<0)
	{
			perror("connect error");
			return -1;
	}
	char buff[1024]={0};
	while(1)
	{
		//4.发送数据
		printf("client say:");
		scanf("%s",buff);
		send(sockfd,buff,strlen(buff),0);
		//5.接收数据
		memset(buff,0,sizeof(buff));
		ssize_t rlen = recv(sockfd, buff, 1023, 0);
		if (rlen < 0)
		{
				perror("recv error");
				return -1;
		}
		else if (rlen == 0)
		{
				printf("peer shutdown!\n");
				return -1;
		}
		printf("server say:%s\n", buff);
	}
	close(sockfd);
	return 0;
}
