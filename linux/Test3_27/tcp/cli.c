#include"../utili.h"

int main()
{
    int sockCli = socket(AF_INET, SOCK_STREAM, 0);
    if(sockCli == -1)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addrSer;
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(PORT);
    addrSer.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    socklen_t len = sizeof(struct sockaddr);
    int res = connect(sockCli, (struct sockaddr*)&addrSer, len);
    if(res == -1)
    {
        printf("Client Connect Server Fail.\n");
        close(sockCli);
        exit(1);
    }
    else
    {
        printf("Client Connect Server OK.\n");
    }

    char sendbuf[256];
    char recvbuf[256];
    while(1)
    {
        recv(sockCli, recvbuf, 256, 0);
        printf("Ser:>%s\n",recvbuf);
        printf("Cli:>");
        scanf("%s",sendbuf);
        if(strcmp(sendbuf, "quit") == 0)
            break;
        send(sockCli, sendbuf, strlen(sendbuf)+1, 0);
    }
    close(sockCli);

    return 0;
}

