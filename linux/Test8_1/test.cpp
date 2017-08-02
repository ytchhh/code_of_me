/*
	分别使用C/C++/linux的方式操作文件
*/

//		Linux

#if 0

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd;
	if((fd = open("1.txt",O_WRONLY)) == -1)
		printf("open eror\n");
	write(fd,"Hello World",strlen("Hello World"));
	char buf[11];
	close(fd);
	fd = open("1.txt",O_RDONLY);
	read(fd,buf,11);
	printf("buf = %s\n",buf);
	close(fd);
	return 0;
}
#endif

#if 1

#include<stdio.h>


int main()
{
	FILE *fp;
	fp = fopen("1.txt","r");
	char *buffer = "Hello";
	fwrite(buffer,1,sizeof(buffer),fp);
	fclose(fp);


	return 0;
}

#endif
