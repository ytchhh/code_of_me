#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

#if 0
int main()
{
	pid_t pid;
	printf("Process Createion study\n");

	pid = fork();
	switch(pid)
	{
		case 0://child process 该返回值为0
			printf("Child process is runing ,Curpid is %d,ParentPid is %d\n",getpid,getppid());
			break;
		case -1:
			printf("Process creation failed\n");
			break;
		default://parent process 返回为子进程的id
			printf("Parent process is runing,Childpid is %d,Parentpid is %d\n",pid,getpid());
			break;
	}
	return 0;
}
#endif

#if 0

int main()
{
	pid_t pid;
	char *msg;
	int k;

	printf("Process Creation Study\n");
	pid = fork();
	switch(pid)
	{
		case 0:
			msg = "Child process is running";
			k = 3;
			break;
		case -1:
			msg = "Process creation failed";
			break;
		default:
			msg = "Parent process is running";
			k = 5;
			break;
	}

	while(k > 0)
	{
		puts(msg);
		sleep(1);
		k--;
	}
	return 0;
}
#endif

#if 0

int main()
{
	pid_t pid;
	pid = fork();

	switch(pid)
	{
		case 0:
			while(1)//父进程结束后 其变为孤儿进程
			{
				printf("A background process,PID:%d,ParentID:%d\n",getpid(),getppid());
				sleep(3);
			}
		case -1:
			perror("Process creation failed\n");
			exit(1);
		default:
			printf("I am parent process,my pid is %d\n",getpid());
			exit(1);
	}
	return 0;
}
#endif

#if 0

int globVar = 5;

int main()
{
	pid_t pid;
	int var = 1,i;

	printf("fork is different with vfork\n");

	//pid = fork();
	//fork是拷贝了一份之前的所有变量
	//父与子进程之间互相不影响
	pid = vfork();
	//vfork保障了子进程在前，父进程在后
	//并且共享了局部变量和全局变量
	switch(pid)
	{
		case 0:
			i = 3;
			while(i-- > 0)
			{
				printf("Child process is running\n");
				globVar++;
				var++;
				sleep(1);
			}
			printf("child's globVar is %d,var = %d\n",globVar,var);
			break;
		case -1:
			perror("Process creation failed\n");
			exit(0);
		default:
			i = 5;
			while(i-- > 0)
			{
				printf("Parent process is running\n");
				globVar++;
				var++;
				sleep(1);
			}
			printf("Parent's globVar = %d,var = %d\n",globVar,var);
			exit(1);
	}
	return 0;
}
#endif

#if 0

int main()
{
	pid_t pid;
	char *msg;
	int k;
	int exit_code;

	printf("Study how to get_exit code\n");
	pid = fork();

	switch(pid)
	{
		case 0:
			msg = "Child process is running";
			k =5;
			exit_code = 37;
			break;
		case -1:
			perror("Process craetion failed\n");
			exit(1);
		default:
			exit_code = 0;
			break;
	}

	if(pid != 0)
	{
		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);
		//父进程调用wait后被挂起，直到子进程结束
		printf("Child process has exited,pid = %d\n",child_pid);
		if(WIFEXITED(stat_val))
			printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
		else
			printf("Child exited abnormally\n");
	}
	else
	{
		while(k-- > 0)
		{
			puts(msg);
			sleep(1);
		}
	}
	exit(exit_code);
}
#endif


#if 0

int main()
{
	pid_t pid;

	if((pid = fork()) == -1)
	{
		printf("fork error\n");
		exit(1);
	}

	if(pid == 0)
		printf("getpid return %d\n",getpid());
	return 0;
}
#endif

#if 0

extern int errno;

int main()
{
	int fd;

	printf("uid stduy:\n");
	printf("Process's pid = %d,euid = %d\n",getuid(),geteuid());

	if(fd = open("test.cpp",O_RDWR) == -1)
	{
		printf("Open failure,errno is %d:%s\n",errno,strerror(errno));
		exit(1);
	}
	else
		printf("Open successfully!\n");
	close(fd);
	exit(0);
	return 0;
}
#endif

#if 1

#include<sys/resource.h>

int main()
{
	pid_t pid;
	int stat_val = 0;
	int oldpri,newpri;
	
	printf("nice study\n");
	pid = fork();
	switch(pid)
	{
		case 0:
			printf("Child is running,Curpid is %d,ParentPid is %d\n",pid,getpid());

			oldpri = getpriority(PRIO_PROCESS,0);
			printf("Old priority = %d\n",oldpri);

			newpri = nice(2);
			printf("New priority = %d\n",newpri);
			break;
		case -1:
			perror("Process creation failed\n");
			break;
		default:
			printf("Paret is running,ChildPid is %d,,ParentPid is %d",pid,getpid());
			break;
	}
	wait(&stat_val);
	return 0;
}
#endif

