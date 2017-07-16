#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define LISTEN_QUEUE_SIZE 5
#define MAX_BUFFER_SIZE	256




int startup(const char *server_ip,unsigned short server_port)
{
	//创建服务i端socket
	int sock_fd = socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd == -1)
	{
		perror("socket");
		exit(1);
	}

	//服务器地址信息
	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(SERVER_PORT);
	addrSer.sin_addr.s_addr = inet_addr(SERVER_IP);

	int yes = 1;
	setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

	socklen_t len = sizeof(struct sockaddr);
	//绑定
	int res = bind(sock_fd,(struct sockaddr*)&addrSer,len);
	if(res == -1)
	{
		perror("bind");
		close(sock_fd);
		exit(1);
	}
	//监听
	res = listen(sock_fd,LISTEN_QUEUE_SIZE);
	if(res == -1)
	{
		perror("listen");
		close(sock_fd);
		exit(1);
	}
	return sock_fd;
} 
