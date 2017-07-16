#include"../utili.h"
#include<sys/select.h>

#define MAX_CLIENT_SIZE 5

/*
	基于Select模型的TCP服务器，----------一个服务iq如何与多个客户端进行通信
	1.将服务器监听的socket,添加到FD中
	2.Select这个FD中对应的readSet集，看是否有读就绪，若有，则是新的连接到来
	3.accept函数返回这个新连接的socket
	4.循环检测fd中各个socket中的状态，若监听socket有读就绪，说明有新连接到来，若是其他的socket有读就绪，说明是当前连接有数据到来，注意看基本网络编程都是在accept返回的这个新版socket上进行数据传输，服务器自身的socket只用来接收新的连接

*/

int main()
{
	int sockSer = startup(SERVER_IP,SERVER_PORT);

	int client_fd[MAX_CLIENT_SIZE] = {0};
	fd_set readset;
	int max_sock = sockSer;
	int conn_num = 0;	//client connect number
	int i = 0;
	int res;

	char buffer[MAX_BUFFER_SIZE];
	struct sockaddr_in addrCli;
	struct timeval tv;

	while(1)
	{
		//读集 清零初始化
		FD_ZERO(&readset);
		FD_SET(sockSer,&readset);
		
		//将socket放入读集合中 让内核去检测这些socket是否有读就绪
		for(i = 0; i < MAX_CLIENT_SIZE; ++i)
		{
			if(client_fd[i] != 0)
			{
				FD_SET(client_fd[i],&readset);
			}
		}

		tv.tv_sec = 5;
		tv.tv_usec = 0;

		//select函数去检查读集中是否有socket就绪，注意各个参数
		res = select(max_sock+1,&readset,NULL,NULL,&tv);
		if(res == -1)
		{
			perror("select");
			continue;
		}
		else if(res == 0)
		{
			printf("server time out\n");
			continue;
		}
		else
		{
			for(i = 0; i < conn_num; ++i)
			{
				if(FD_ISSET(client_fd[i],&readset))
				{
					//接收来自客户端的conect请求
					recv(client_fd[i],buffer,MAX_BUFFER_SIZE,0);
					printf("From Client Msg:%s\n",buffer);
					send(client_fd[i],buffer,strlen(buffer)+1,0);
				}
			}
			//如果通信的socket处于就绪状态
			if(FD_ISSET(sockSer,&readset))
			{
				socklen_t len = sizeof(struct sockaddr);
				int sockConn = accept(sockSer,(struct sockaddr*)&addrCli,&len);
				if(sockConn == -1)
				{
					perror("accept");
					continue;
				}
				//小于服务器最大负载
				if(conn_num < MAX_CLIENT_SIZE)
				{
					client_fd[conn_num++] = sockConn;
					if(sockConn > max_sock)
						max_sock = sockConn;
				}
				//超载
				else
				{
					char *msg = "Sorry,Server OverLoad";
					send(sockConn,msg,strlen(msg)+1,0);
				}
			}
		}
	}
	close(sockSer);
	return 0;
}
