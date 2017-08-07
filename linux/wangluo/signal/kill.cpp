#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static int alarm_fired = 0;

void handler(int sig)
{
	alarm_fired = 1;
}

int main()
{
	pid_t pid;
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork failed\n");
			exit(1);
		case 0:
		//child process
			sleep(5);
			kill(getppid(),SIGALRM);
			exit(0);
		default:
			break;
	}
	signal(SIGALRM,handler);
	while(!alarm_fired)
	{
		printf("Hello World\n");
		sleep(1);
	}
	if(alarm_fired)
		printf("I get a signal %d\n",SIGALRM);
	return 0;
}


/*在代码中我们使用fork调用复制了一个新进程，在子进程中，5秒后向父进程中发送一个SIGALRM信号，
父进程中捕获这个信号，并用ouch函数来处理，变改alarm_fired的值，然后退出循环。从结果中我们也可以看到输出了5个Hello World！
之后，程序就收到一个SIGARLM信号，然后结束了进程
*/
