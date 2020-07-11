#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
        //1.创建套接字socket
        int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        if(sockfd<0)
        {   
                perror("socket error");
                return -1; 
        }   
		
        //2.为socket绑定地址信息
        struct sockaddr_in addr;
        addr.sin_family=AF_INET;
        addr.sin_port=htons(9000);
        addr.sin_addr.s_addr=inet_addr("192.168.122.1");
        socklen_t len=sizeof(struct sockaddr_in);

	int reuse = 1;//端口复用
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
        int ret=bind(sockfd,(struct sockaddr *)&addr,len);
        if(ret<0)
        {    
                perror("bind error");
				close(sockfd);
                return -1; 
        }   
		
	//3. 监听
        //  int listen(int sockfd, int backlog);
        //  sockfd:     socket描述符
        //  backlog：   最大的同时并发连接数
        if(listen(sockfd,5)<0)
        {
                perror("listen error");
                return -1;
        }
		
        //4.获取连接成功的socket
        while(1)
        {
		struct sockaddr_in cli_addr;
		int new_sockfd;
		//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
		//  sockfd: socket描述符
		//  addr：  新建立连接的客户端地址信息
		//  addrlen：地址信息长度
		//  返回值：返回新的socket连接描述符，失败：-1
		new_sockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&len);
		if(new_sockfd<0)
		{
			perror("accept error");
			continue;
		}
		printf("new conn %s:%d\n", inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));
		
		char buff[1024]={0};
		while(1)
		{
			//5.接收数据
			ssize_t rlen=recv(new_sockfd,buff,1023,0);
			if(rlen<0)
			{
				perror("recv error");
				close(new_sockfd);
				return -1;
			}else if(rlen ==0)
			{
				perror("peer shutdown\n");
				close(new_sockfd);
				continue;
			}
			printf("client[%s:%d] say:%s\n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port), buff);
			//6.发送数据
			memset(buff,0,sizeof(buff));
			printf("server say:");
			scanf("%s", buff);
			send(new_sockfd, buff, strlen(buff), 0);
		}
        }
        close(sockfd);
        return 0;
}

