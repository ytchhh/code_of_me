#if 0

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void read_from_pipe(int fd)
{
	char message[100];
	read(fd,message,100);
	printf("read from pipe:%s",message);
}

void write_to_pipe(int fd)
{
	char *message = "Hello,pipe\n";
	write(fd,message,strlen(message)+1);
}

int main()
{
	int fd[2];
	pid_t pid;
	int stat_val;

	if(pipe(fd))
	{
		printf("create pipe failed\n");
		exit(1);
	}

	pid = fork();
	switch(pid)
	{
		case -1:
			printf("fork error\n");
			exit(1);
		case 0://子进程关闭fd1
			close(fd[1]);
			read_from_pipe(fd[0]);
			exit(0);
		default://父进程关闭fd0
			close(fd[0]);
			write_to_pipe(fd[1]);
			wait(&stat_val);
			exit(0);
	}
	return 0;
}
#endif

#if 0

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

/*子进程读写管道的函数*/
void child_rw_pipe(int readfd,int writefd)
{
	char* message1 = "from child process!\n";
	write(writefd,message1,strlen(message1)+1);

	char message2[100];
	read(readfd,message2,100);
	printf("child process read from pipe:%s",message2);
}

void parent_rw_pipe(int readfd,int writefd)
{
	char* message1 = "from parent process\n";
	write(writefd,message1,strlen(message1)+1);
	char message2[100];
	read(readfd,message2,100);
	printf("parent process read from pipe:%s",message2);
}

int main()
{
	int pipe1[2],pipe2[2];
	pid_t pid;
	int stat_val;

	printf("realize full_duplex communication:\n");
	if(pipe(pipe1))
	{
		printf("pipe1 failed!\n");
		exit(1);
	}
	if(pipe(pipe2))
	{
		printf("pipe2 failed\n");
		exit(1);
	}

	pid = fork();
	switch(pid)
	{
		case -1:
			printf("fork error!\n");
			exit(1);
		case 0:
			close(pipe1[1]);//写
			close(pipe2[0]);//读
			child_rw_pipe(pipe1[0],pipe2[1]);
			exit(1);
		default:
			close(pipe1[0]);//读
			close(pipe2[1]);//写
			parent_rw_pipe(pipe2[0],pipe1[1]);
			wait(&stat_val);
			exit(0);
	}
	return 0;
}
#endif

#if 0

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int arg,char *argv[],char **environ)
{
	int fd[2];
	pid_t pid;
	int stat_val;

	if(arg < 2)
	{
		printf("wrong parameters\n");
		exit(0);
	}
	if(pipe(fd))
	{
		perror("pipe failed");
		exit(1);
	}

	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork failed!\n");
			exit(1);
		case 0:
			close(0);
			dup(fd[0]);
			execve("ctrlprocess",(void*)argv,environ);
			exit(0);
		default:
			close(fd[0]);
			write(fd[1],argv[1],strlen(argv[1]));
			break;
	}
	wait(&stat_val);
	exit(0);
}


#endif
