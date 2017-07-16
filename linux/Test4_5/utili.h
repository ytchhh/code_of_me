#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 5050
#define IP_ADDRESS "127.0.0.1"	//ip地址
#define LISTEN_QUEUE_SIZE 5		//监听等待队伍大小
