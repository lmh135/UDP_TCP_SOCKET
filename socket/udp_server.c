//这是一个非常简单的udp服务端程序
//功能是：客户端与服务端的聊天程序
 
#include<stdio.h>
#include<unistd.h>
#include <sys/socket.h>
#include<errno.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
  
int main()
{
          //1.创建套接字
          //int socket(int domain, int type, int protocol);
          int sockfd =socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
          if(sockfd <0)
          {
                  perror("socket error\n");
                  return -1;
          }
          //2.为套接字绑定地址信息
          //  int bind(int sockfd, const struct sockaddr *addr,
          //                  socklen_t addrlen)
          struct sockaddr_in addr;
          addr.sin_family=AF_INET;
          addr.sin_port=htons(9000);
          addr.sin_addr.s_addr=inet_addr("192.168.122.1");
          socklen_t addrlen =sizeof(struct sockaddr_in);

	  int reuse = 1;//端口复用
	  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));


          int ret=bind(sockfd,(struct sockaddr*)&addr,addrlen);
          if(ret<0)
          {
                  perror("bind error\n");
                  close(sockfd);
                  return -1;
          }
          //3.接收数据
          // ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
          //                         struct sockaddr *src_addr, socklen_t *addrlen);
          //      sockfd: socket描述符
          //      buf：   用于将存储接收的数据
          //      len：   想要接收的数据长度
          //      flags： 0-默认是说如果缓冲区没有数据，那么我就阻塞等待
          //      src_addr：  用于确定数据的发送端地址信息
          //      addrlen：   地址信息的长度
          //      返回值：实际接收的数据长度 ,-1：失败
	  char buff[1024]={0};  
          struct sockaddr_in cli_addr;      
	  while(1)
          {
                 //接收数据               
                 ssize_t rlen=recvfrom(sockfd,buff,1023,0,(struct sockaddr*)&cli_addr,&addrlen);
                 if(rlen<0)
                 {
                         perror("recvfrom error\n");
                         close(sockfd);
                         return -1;
                 }
                 //inet_ntoa：将网络地址转换成“.”点隔的字符串格式
                 //ntohs：将网络字节序转成端口字节序。
                 printf("client[%s:%d] say:%s\n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port),buff);
                 //发送数据
                 //ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                 //                      const struct sockaddr *dest_addr, socklen_t addrlen);
                 //sockfd：socket描述符，发送数据的时候就是通过这个socket所绑定的地址来发送。
                 //buf：要发送的数据
                 //len：要发送数据的长度
                 //flag：0-默认阻塞式发送
                 //dest_addr：数据要发送到的对端地址，目的地址
                 //addrlen：地址信息长度
                 //返回值：返回时记得发送长度，失败返回-1/ 
                 memset(buff,0,sizeof(buff));//将数组初始化为0
                 printf("server say:");
                 scanf("%s",buff);
                 sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,addrlen);
          }
          close(sockfd);
          return 0;
 }

