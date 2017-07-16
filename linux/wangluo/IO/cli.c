#include"./utili.h"


int main()
{
	int sockCli = socket(AF_INET,SOCK_STREAM,0);
	if(sockCli == -1)
	{
		perror("socket");
		exit(1);
	}
	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(SERVER_PORT);
	addrSer.sin_addr.s_addr = inet_addr(SERVER_IP);

	socklen_t len = sizeof(struct sockaddr);
	int res = connect(sockCli,(struct sockaddr*)&addrSer,len);
	if(res == -1)
	{
		perror("Client Connect Server Fail\n");
		close(sockCli);
		exit(1);
	}

	char recv_buffer[MAX_BUFFER_SIZE];
	char send_buffer[MAX_BUFFER_SIZE];

	memset(send_buffer,0,sizeof(send_buffer));
	memset(recv_buffer,0,sizeof(recv_buffer));

	while(1)
	{
		printf("msg:>");
		scanf("%s",send_buffer);
		send(sockCli,send_buffer,strlen(send_buffer)+1,0);
		recv(sockCli,recv_buffer,MAX_BUFFER_SIZE,0);
		printf("From Server of myself msg:>%s\n",recv_buffer);
	}
	close(sockCli);
	return 0;
}
