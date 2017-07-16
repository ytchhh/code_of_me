#include"../utili.h"
#include<sys/epoll.h>

#define MAX_EVENT_SIZE 1024
#define MAX_CLIENT_SIZE		5

void do_epoll(int sock);

int main()
{
	int sockSer = startup(SERVER_IP,SERVER_PORT);
	do_epoll(sockSer);
	close(sockSer);
	return 0;
}

void add_event(int epoll_fd,int fd,int state)
{
	struct epoll_event ev;
	ev.events = state;
	ev.data.fd = fd;
	epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd,&ev);
}

void do_epoll(int sock)
{
	struct epoll_event event[MAX_EVENT_SIZE];
	int epoll_fd = epoll_create(MAX_CLIENT_SIZE);
	add_event(epoll_fd,sock,EPOLLIN);

	int ret;
	int i;
	while(1)
	{
		ret = epoll_wait(epoll_fd,event,MAX_EVENT_SIZE,-1);
		if(ret == -1)
		{
			perror("epoll_wait");
			continue;
		}
		else
		{
			for(i = 0; i < ret; ++i)
			{
				if(event[i].data.fd = sock && event[i].events && EPOLLIN)
				{
					struct sockaddr_in addrCli;
					socklen_t len = sizeof(struct sockaddr);
					int sockConn = accept(sock,(struct sockaddr*)&addrCli,&len);

					if(sockConn == -1)
					{
						perror("accept");
						break;
					}
					add_event(epoll_fd,sockConn,EPOLLIN);
				}
				else if(event[i].events & EPOLLIN)
				{
					char buffer[MAX_BUFFER_SIZE];
					recv(event[i].data.fd,buffer,MAX_BUFFER_SIZE,0);
					printf("msg:>%s\n",buffer);
					send(event[i].data.fd,buffer,strlen(buffer)+1,0);
				}
			}
		}
	}
}
