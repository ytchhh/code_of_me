#include"../utili.h"

int main()
{
    int sockSer = socket(AF_INET, SOCK_STREAM, 0);
    if(sockSer == -1)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addrSer, addrCli;
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(PORT);
    addrSer.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    socklen_t len = sizeof(struct sockaddr);
    int res = bind(sockSer, (struct sockaddr*)&addrSer, len);
    if(res == -1)
    {
        perror("bind");
        close(sockSer);
        exit(1);
    }

    res = listen(sockSer, LISTEN_QUEUE_SIZE);
    if(res == -1)
    {
        perror("listen");
        close(sockSer);
        exit(1);
    }

    printf("Server wait Connect.......\n");
    /*
	int sockConn = accept(sockSer, (struct sockaddr*)&addrCli, &len);
    if(sockConn == -1)
    {
        printf("Server Accept Client Fail.\n");
        close(sockSer);
        exit(1);
    }
    else
    {
        printf("Server Accept Client OK.\n");
    }
	*/
    char sendbuf[256];
    char recvbuf[256];
    /*
	 *单线程重复式
	while(1)
    {
		int sockConn = accept(sockSer, (struct sockaddr*)&addrCli, &len);
    	if(sockConn == -1)
    	{
        	printf("Server Accept Client Fail.\n");
        	close(sockSer);
        	exit(1);
    	}
    	else
    	{
        	printf("Server Accept Client OK.\n");
    	}
        printf("Ser:>");
        scanf("%s",sendbuf);
        if(strcmp(sendbuf, "quit") == 0)
            break;
        send(sockConn, sendbuf, strlen(sendbuf)+1, 0);

        recv(sockConn, recvbuf, 256, 0);
        printf("Cli:>%s\n",recvbuf);
    }
    close(sockSer);
    */
	//多进程网络服务
	
	while(1)
	{
		
	}
	return 0;
}

