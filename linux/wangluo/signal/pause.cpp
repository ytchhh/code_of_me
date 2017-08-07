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
	signal(SIGALRM,handler);
	alarm(5);
	pause();
	if(alarm_fired == 1)
		printf("Receive a signal %d\n",SIGALRM);
	return 0;
}
