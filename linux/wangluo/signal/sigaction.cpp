#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signal(int sig)
{
	printf("this is a signal\n");
}

int main()
{
	struct sigaction act;
	act.sa_handler = signal;
	//创建新的信号屏蔽字，既不屏蔽任何信号
	sigemptyset(&act.sa_mask);
	//使sigaction函数重置为默认行为
	act.sa_flags = SA_RESETHAND;

	sigaction(SIGINT,&act,0);
	while(1)
	{
		printf("Hello World\n");
		sleep(1);
	}
	return 0;
}
