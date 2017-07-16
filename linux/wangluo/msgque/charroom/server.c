#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>

#define BUF_SIZE 256
#define PROJ_ID  32
#define PATH_NAME "mymsg"
#define SERVER_MSG 1
#define CLIENT_MSG 2


int main()
{	
	//用户自定义消息缓冲区
	struct mymsgbuf
	{
		long msgtype;
		char ctrlstring[BUF_SIZE];
	}msgbuffer;

	int qid;
	int msglen;
	key_t msgkey;

	if((msgkey = ftok(PATH_NAME,PROJ_ID)) == -1)
	{
		perror("ftok error\n");
		exit(1);
	}

	if((qid = msgget(msgkey,IPC_CREAT | 0660)) == -1)
	{
		perror("msgget error\n");
		exit(1);
	}

	while(1)
	{
		printf("Server:");
		fgets(msgbuffer.ctrlstring,BUF_SIZE,stdin);
		if(strncmp("quit",msgbuffer.ctrlstring,4) == 0)
		{
			msgctl(qid,IPC_RMID,NULL);
			break;
		}

		msgbuffer.ctrlstring[strlen(msgbuffer.ctrlstring)-1] = '\0';
		msgbuffer.msgtype = SERVER_MSG;

		if(msgsnd(qid,&msgbuffer,strlen(msgbuffer.ctrlstring) + 1,0) == -1)\
		{
			perror("Server msgsnd error\n");
			exit(1);
		}

		if(msgrcv(qid,&msgbuffer,BUF_SIZE,CLIENT_MSG,0) == -1)
		{
			perror("Server msgrcv error\n");
			exit(1);
		}
		printf("Client:%s\n",msgbuffer.ctrlstring);
	}
	return 0;
}
