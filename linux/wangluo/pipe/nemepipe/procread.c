#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

#define FIFO_NAME "myfifo"
#define BUF_SIZE 1024

int main()
{
	int fd;
	char buf[BUF_SIZE];

	umask(0);
	fd = open(FIFO_NAME,O_RDONLY);//以只读方式打开管道
	printf("Read content:%s\n",buf);
	close(fd);
	exit(0);
}
