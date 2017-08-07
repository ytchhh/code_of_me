#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int sig)
{
	printf("this is a signal:%d\n",sig);
	(void)signal(SIGINT,SIG_DFL);
}

int main()
{
	(void) signal(SIGINT,handler);
	while(1)
	{
		printf("Hello World\n");
		sleep(1);
	}
	return 0;
}
