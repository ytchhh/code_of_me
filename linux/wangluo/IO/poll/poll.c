#include"../utili.h"
#include<poll.h>

#define MAX_CLIENT_SIZE 5
void do_poll(int sock);

int main()
{
    int sockSer = startup(SERVER_IP, SERVER_PORT);
    do_poll(sockSer);
    close(sockSer);
    return 0;
}

void do_poll(int sock)
{
    struct pollfd client_fd[MAX_CLIENT_SIZE];
    //Server
    client_fd[0].fd = sock;
    client_fd[0].events = POLLIN;

    int i;
    for(i=1; i<MAX_CLIENT_SIZE; ++i)
        client_fd[i].fd = 0;

    int num = 1;
    int nready = 0;
    char buffer[MAX_BUFFER_SIZE];
    struct timeval tv;
    for(;;)
    {
        //accept
        //recv send
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        nready = poll(client_fd, num, -1);
        if(nready == -1)
        {
            perror("poll");
            continue;
        }
        else if(nready == 0)
        {
            printf("server time out.\n");
            continue;
        }
        else
        {
            if(client_fd[0].revents & POLLIN)
            {
                struct sockaddr_in addrCli;
                socklen_t len = sizeof(struct sockaddr);
                int sockConn = accept(sock, (struct sockaddr*)&addrCli, &len);
                if(sockConn == -1)
                {
                    perror("accept");
                    continue;
                }
                for(i=1; i<MAX_CLIENT_SIZE; ++i)
                {
                    if(client_fd[i].fd == 0)
                    {
                        client_fd[i].fd = sockConn;
                        client_fd[i].events = POLLIN;
                        num++;
                        break;
                    }
                }
                if(i == MAX_CLIENT_SIZE)
                {
                    char *msg = "POLL:Sorry, Server OverLoad.";
                    send(sockConn, msg, strlen(msg)+1, 0);
                }
                continue;
            }

            for(i=1; i<MAX_CLIENT_SIZE; ++i)
            {
                if(client_fd[i].fd == 0)
                    continue;
                if(client_fd[i].revents & POLLIN)
                {
                    recv(client_fd[i].fd, buffer, MAX_BUFFER_SIZE, 0);
                    printf("From Client Msg:>%s\n",buffer);
                    send(client_fd[i].fd, buffer, strlen(buffer)+1, 0);
                }
            }
        }
    }
}









