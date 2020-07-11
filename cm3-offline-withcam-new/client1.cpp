#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>
#include<sys/time.h>
#include"MySocket.h"
#include"imu.h"
#include"uart.h"
#include"Data.h"
#include"mylib.h"
#include"gps.h"
#include"VLP16.h"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <asm/types.h>
#include <linux/videodev2.h>
#include <malloc.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <termios.h>
#include <iostream>
#include <fstream>
#include <signal.h>
Packet pkt_data;
pthread_mutex_t data_mutex;


struct timeval first_time;




pthread_mutex_t time_mutex;



#define USEGPS 0       //使用GPS
#define USEIMU 1	//使用IMU
#define USECAM 0	//使用摄像头
#define USEVLP 1	//使用VLP16扫描仪
#define DEBUG 0  //是否打印调试数据



//int ggacount,vtgcount,headingcount;
//double ned_xyz_check[3],ned_uvw_check[3],heading_check;
//int gps_sats_check,gps_mod_check;
pthread_mutex_t gps_mutex;
GPS_Data gps_data_copy;

bool gga_update_flag = false;
bool vtg_update_flag = false;
bool heading_update_flag = false;


void *gps_capt(void*fd)
{
	
}

void *cam_capt(void *arg)
{

}

int main()
{
	unsigned char laser_buf[4]={1,2,3,5};
	Socket laser_capt_socket; 
	struct timeval laser_capt_time;
	//Laser_Data laser_data;

	int udprecvbuflen,udprecvbuf;
	socklen_t optlen;
	optlen=sizeof(udprecvbuf);
	//laser_capt_socket.UDPCreateServer("IPV4","UDP","192.168.122.1",8082);//lidardata    //raspberry eth1-laser 192.168.0.101
	laser_capt_socket.UDPCreateClient("IPV4","UDP","192.168.122.1",8081);
 	if(getsockopt(laser_capt_socket.GetSocketFD(),SOL_SOCKET,SO_RCVBUF,(char*)&udprecvbuf,&optlen)!=0)
	perror("getsockopt1 error");
	printf("the original udprecvbuflen is %d\n",udprecvbuf);
	udprecvbuflen=0;
	if(setsockopt(laser_capt_socket.GetSocketFD(),SOL_SOCKET,SO_RCVBUF,(char*)&udprecvbuflen,sizeof(int))!=0)
	perror("setsockopt error");
	if(getsockopt(laser_capt_socket.GetSocketFD(),SOL_SOCKET,SO_RCVBUF,(char*)&udprecvbuf,&optlen)!=0)
	perror("getsockopt2 error");
	printf("the final udprecvbuflen is %d\n",udprecvbuf);
	laser_capt_socket.UDPSendPackets(&laser_buf,sizeof(laser_buf));
		

}





		
