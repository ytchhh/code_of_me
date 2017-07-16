#define _GNU_SOURCE 1

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<pthread.h>
#include<poll.h>


#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE	10
#define SERVER_IP "192.168.0.188"
#define SERVER_PORT 9090
