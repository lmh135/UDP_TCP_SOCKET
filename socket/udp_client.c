#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
 
int main()
{
        int sockfd=socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd<0)
        {
                 perror("socket error\n");
                 return -1;
        }
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port=htons(9000);
        server.sin_addr.s_addr=inet_addr("192.168.122.1");
 
        char buff[1024]={0};
        struct sockaddr_in peer;
	socklen_t len=sizeof(peer);
        while(1)
        {
                 printf("client say:");
		 scanf("%s",buff);
                 sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&server,sizeof(server));
                 memset(buff,0,sizeof(buff));//将数组初始化为0
                 ssize_t _s=recvfrom(sockfd,buff,sizeof(buff)-1,0,(struct sockaddr*)&peer,&len);  
		 printf("Server[%s:%d] echo:%s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buff);               
        }
	close(sockfd);
        return 0;
}

