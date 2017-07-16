#if 0
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

#define BUF_SIZE 256
#define PROJ_ID  32
#define PATH_NAME "."

int main()
{
	struct mymsgbuf//用户自定义消息缓冲
	{
		long msgtype;
		char ctrlstring[BUF_SIZE];
	}msgbuffer;
	int qid;//消息队列标示符
	int msglen;
	key_t msgkey;
	//获取键值
	if((msgkey = ftok(PATH_NAME,PROJ_ID)) == -1)
	{
		perror("ftok error\n");
		exit(1);
	}

	//创建消息队列
	if((qid = msgget(msgkey,IPC_CREAT | 0660)) == -1)
	{
		perror("msgget error\n");
		exit(1);
	}
	
	//填充消息队列，发送到消息队列
	msgbuffer.msgtype = 3;
	strcpy(msgbuffer.ctrlstring,"Hello,message queue");
	msglen = sizeof(struct mymsgbuf) -4;
	if(msgsnd(qid,&msgbuffer,msglen,0) == -1)
	{
		perror("msgget error\n");
		exit(1);
	}
	return 0;
}
#endif

#if 0

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<sys/msg.h>

#define BUF_SIZE 256
#define PROJ_ID  32
#define PATH_NAME "mymsg"

int main()
{
	//用户自定义消息缓冲区
	struct mymsgbuf
	{
		long msgtype;
		char ctrlstring[BUF_SIZE];
	}msgbuffer;

	int qid;//消息队列标示符
	int msglen;
	key_t msgkey;
	
	//获取键值
	if((msgkey = ftok(PATH_NAME,PROJ_ID)) == -1)
	{
		perror("ftok error\n");
		exit(1);
	}

	//获取消息队列标示符
	if((qid = msgget(msgkey,IPC_CREAT | 0660) == -1))
	{
		perror("msgget error\n");
		exit(1);
	}

	msglen = sizeof(struct mymsgbuf) - 4;
	if(msgrcv(qid,&msgbuffer,msglen,3,0) == -1)//读取数据
	{
		perror("msgrcv error\n");
		exit(1);
	}
	printf("Get message %s\n",msgbuffer.ctrlstring);

	return 0;
}
#endif

#if 0

#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

#define BUF_SIZE 256
#define PROJ_ID  32
#define PATH_NAME "mymsg"

void getmsgattr(int msgid,struct msqid_ds msg_info);

int main()
{
	//用户自定义消息缓冲区
	struct mymsgbuf
	{
		long msgtype;
		char ctrlstring[BUF_SIZE];
	}msgbuffer;
	int qid;//消息队列标示符
	int msglen;
	key_t msgkey;
	struct msqid_ds msq_attr;
	
	//获取键值
	if((msgkey = ftok(PATH_NAME,PROJ_ID)) == -1)
	{
		perror("ftok error\n");
		exit(1);
	}

	//获取消息队列标示符
	if((qid = msgget(msgkey,IPC_CREAT | 0660)) == -1)
	{
		perror("msgget error\n");
		exit(1);
	}
	getmsgattr(qid,msq_attr);//输出消息队列的属性

	//发送一条消息到消息队列
	msgbuffer.msgtype = 2;
	strcpy(msgbuffer.ctrlstring,"Another message");
	msglen = sizeof(struct mymsgbuf) - 4;
	if(msgsnd(qid,&msgbuffer,msglen,0) == -1)
	{
		perror("msgget error\n");
		exit(1);
	}
	getmsgattr(qid,msq_attr);//输出消息队列的属性

	//设置消息队列的属性
	msq_attr.msg_perm.uid = 3;
	msq_attr.msg_perm.gid = 2;

	if(msgctl(qid,IPC_SET,&msq_attr) == -1)
	{
		perror("msg set error\n");
		exit(1);
	}
	getmsgattr(qid,msq_attr);//修改后再观察其属性

	if(msgctl(qid,IPC_RMID,NULL) == -1)
	{
		perror("delete msg error\n");
		exit(1);
	}
	getmsgattr(qid,msq_attr);//删除后再观察其属性
	return 0;
}

void getmsgattr(int msgid,struct msqid_ds msg_info)
{
	if(msgctl(msgid,IPC_STAT,&msg_info) == -1)
	{
		perror("msgctl error \n");
		return ;
	}
	printf("****information of message queue%d****\n",msgid);
	printf("last msgsnd to msq time is %s\n",ctime(&(msg_info.msg_stime)));
	printf("last msgrcv time from msg is %s\n",ctime(&(msg_info.msg_rtime)));
	printf("last change msq time is %s\n",ctime(&(msg_info.msg_ctime)));
	printf("current number of bytes on queue is %d\n",msg_info.msg_cbytes);
	printf("number of messages in queue is %d\n",msg_info.msg_qnum);
	printf("max number of bytes on queue is %d\n",msg_info.msg_qbytes);
	printf("pid of last msgsnd is %d\n",msg_info.msg_lspid);
	printf("pid of last msgsnd is %d\n",msg_info.msg_lrpid);
	
	printf("msg uid is %d\n",msg_info.msg_perm.uid);
	printf("msg gid is %d\n",msg_info.msg_perm.gid);
	printf("******information end!******\n");
}
#endif


