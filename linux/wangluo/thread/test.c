#if 0
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int* thread()
{
	pthread_t newthid;

	newthid = pthread_self();//获得本线程的id
	printf("this is new thread,thread ID = %d\n",newthid);
	return NULL;
}

int main()
{
	pthread_t thid;
	printf("main thread,ID is %d\n",pthread_self());//打印主线程的ID
	if(pthread_create(&thid,NULL,(void*)thread,NULL) != 0)
	{
		printf("thread creation failed\n");
		exit(1);
	}
	sleep(1);
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void run(void)
{
	printf("Function running in thread %u\n",pthread_self());
}
void* thread1(void *arg)
{
	pthread_t thid = pthread_self();
	printf("Current thread's ID is %u\n",thid);
	pthread_once(&once,run);//限制run函数只被调用一次
	printf("thread1 ends\n");
}
void* thread2(void *arg)
{
	pthread_t thid = pthread_self();
	printf("Current thread's ID is %u\n",thid);
	pthread_once(&once,run);
	printf("thread2 ends\n");
}
int main()
{
	pthread_t thid1,thid2;

	pthread_create(&thid1,NULL,thread1,NULL);
	pthread_create(&thid2,NULL,thread2,NULL);
	sleep(3);
	printf("main thread exit\n");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<pthread.h>

void* assisthread(void *arg)
{
	printf("I am helping to do some jobs\n");
	sleep(3);
	pthread_exit(0);
}
int main()
{
	pthread_t assistthid;
	int status;

	pthread_create(&assistthid,NULL,(void*)assisthread,NULL);
	pthread_join(assistthid,(void*) &status);
	printf("assistthread's exit is caused %d\n",status);
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_key_t key;

void* thread2(void *arg)
{
	int tsd = 5;
	printf("thread %d is running\n",pthread_self());
	pthread_setspecific(key,(void*)tsd);
	printf("thread %d returns %d\n",pthread_self(),pthread_getspecific(key));
}

void* thread1(void *arg)
{
	int tsd = 0;
	pthread_t thid2;

	printf("thread %d is running\n",pthread_self());
	pthread_setspecific(key,(void*)tsd);
	pthread_create(&thid2,NULL,thread2,NULL);
	sleep(10);
	printf("thread %d return %d\n",pthread_self(),pthread_getspecific(key));
}

int main()
{
	pthread_t thid1;
	printf("main thread begins running \n");
	pthread_key_create(&key,NULL);
	pthread_create(&thid1,NULL,thread1,NULL);
	sleep(3);
	pthread_key_delete(key);
	printf("main thread exit\n");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t number_mutex;
int 			globalnumber;
void write_globalnumber()
{
	pthread_mutex_lock(&number_mutex);
	globalnumber++;
	pthread_mutex_unlock(&number_mutex);
}
int read_mutex()
{
	int temp;
	pthread_mutex_lock(&number_mutex);
	temp = globalnumber;
	pthread_mutex_unlock(&number_mutex);
	return temp;
}
int main()
{
	
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void* thread1(void *arg)
{
	pthread_cleanup_push(pthread_mutex_unlock,&mutex);

	while(1)
	{
		printf("thread1 is running\n");
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond,&mutex);
		printf("thread1 applied the condition\n");
		pthread_mutex_unlock(&mutex);
		sleep(4);
	}
	pthread_cleanup_pop(0);
}

void* thread2(void *arg)
{
	while(1)
	{
		printf("thread2 is running\n");
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond,&mutex);
		printf("thread2 applied the condition\n");
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

int main()
{
	pthread_t tid1,tid2;

	printf("condition variable study!\n");
	pthread_mutex_init(&cond,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&tid1,NULL,(void*)thread1,NULL);
	pthread_create(&tid2,NULL,(void*)thread2,NULL);

	do
	{
		pthread_cond_signal(&cond);
	}while(1);

	sleep(50);
	pthread_exit(0);

	return 0;
}
#endif

#if 0

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>//打印出错误的信息 根据相应的错误码 查找原因

int main()
{
	FILE *stream;
	char *filename = "test.txt";

	errno = 0;

	stream = fopen(filename,"r");

	if(stream == NULL)
		printf("open file %s failed,errno is %d\n",filename,errno);
	else
		printf("open file %s successfully\n",filename);
	return 0;
}
#endif


#if 0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

FILE* open_file(char * filename)
{
	FILE *stream;
	errno = 0;

	stream = fopen(filename,"r");
	if(stream == NULL)
	{
		printf("can not open the file %s.reason: %s\n",filename,strerror(errno));
		exit(-1);
	}
	else
		return stream;
}

int main()
{
	char *filename = "test.txt";

	open_file(filename);
	return 0;
}
#endif
