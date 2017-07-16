#include"../utili.h"

#if 0
//dup函数
#include"../utili.h"

int main()
{
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET,SERVER_IP,&address.sin_addr);
	address.sin_port = htons(SERVER_PORT);

	int sock = socket(PF_INET,SOCK_STREAM,0);
	assert(sock >= 0);

	int ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
	assert(ret != -1);

	ret = listen(sock,5);
	assert(ret != -1);

	struct sockaddr_in client;
	socklen_t client_addrlength = sizeof(client);

	int connfd = accept(sock,(struct sockaddr*)&client,&client_addrlength);
	if(connfd < 0)
	{
		printf("errno is :%d\n",errno);
	}
	else
	{
		close(STDOUT_FILENO);
		dup(connfd);
		printf("abcd\n");
		close(connfd);
	}
	close(sock);
	return 0;
}
#endif

#if 0
#include"../utili.h"

int main()
{
	FILE* res = fopen("1.txt","rw");
	close(STDOUT_FILENO);
	dup(*((int*)res));
	printf("abcd\n");
	fclose(res);
	return 0;
}
#endif

#if 0
//readv函数和writev函数
#include<sys/uio.h>
#include<string.h>

#define BUFFER_SIZE 1024

static const char* status_line[2] = {"200 OK","500 Internet server error"};

int main(int argc,char* argv[])
{
	char *file_name = argv[1];
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET,SERVER_IP,&address.sin_addr);
	address.sin_port = htons(SERVER_PORT);

	int sock = socket(PF_INET,SOCK_STREAM,0);
	assert(sock >= 0);

	int ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
	assert(ret != -1);

	ret = listen(sock,5);
	assert(ret != -1);

	struct sockaddr_in client;
	socklen_t client_addrlength = sizeof(client);
	int connfd = accept(sock,(struct sockaddr*)&client,&client_addrlength);
	if(connfd < 0)
	{
		printf("errno is :%d\n",errno);
	}
	else
	{
		//用于保存HTTP应答的状态行，头部字段和一个空行的缓存区
		char header_buf[BUFFER_SIZE];
		memset(header_buf,'\0',BUFFER_SIZE);
		//英语存放目标文件内容的应用程序缓存
		char* file_buf;
		//用于获取目标文件的属性，比如是否为目录，文件大小等
		struct stat file_stat;
		//记录目标文件是否时有效文件
		bool vaild = true;
		//缓存区header_buf目前已经使用了多少字节的空间
		int len = 0;
		if(stat(file_name,&file_stat) < 0)
		{
			vaild = false;
		}
		else
		{
			if(S_ISDIR(file_stat.st_mode))	//目标文件是一个目录
			{
				vaild = false;
			}
			else if(file_stat.st_mode & S_IROTH)
			{
				//动态分配缓存区file_buf,并指定其大小为目标文件的大小file_stat.st_size加1，然后将目标文件读入缓存区file_buf中
				int fd = open(file_name,O_RDONLY);
				file_buf = new char[file_stat.st_size + 1];
				memset(file_buf,'\0',file_stat.st_size + 1);
				if(read(fd,file_buf,file_stat.st_size) < 0)
				{
					vaild = false;
				}
			}
			else
			{
				vaild = false;
			}
		}
		//如果目标文件有效，则发送正常的HTTP应答
		if(vaild)
		{
			//下面这部分内容将HTTP应答的状态行，"content-length"头部字段和一个空行一次加入head_buf中
			ret = snprintf(header_buf,BUFFER_SIZE-1,"%s %s\r\n",
							"HTTP/1.1",status_line[0]);
			len += ret;
			ret = snprintf(header_buf + len,BUFFER_SIZE-1-len,"Content-length:%d\r\n",file_stat.st_size);
			len += ret;
			ret = snprintf(header_buf,BUFFER_SIZE-1-len,"%s","\r\n");
			//利用writev将header_buf和file_buf的内容一并写出
			struct iovec iv[2];
			iv[0].iov_base = header_buf;
			iv[0].iov_len = strlen(header_buf);
			iv[1].iov_base = file_buf;
			iv[1].iov_len = file_stat.st_size;
			ret = write(connfd,iv,2);

		}
		else
		{
			ret = snprintf(header_buf,BUFFER_SIZE-1,"%s %s\r\n","HTTP/1.1",status_line[0]);
			len += ret;
			ret = snprintf(header_buf + len,BUFFER_SIZE-1-len,"%s","\r\n");
			send(connfd,header_buf,strlen(header_buf),0);
		}
		close(connfd);
		delete [] file_buf;
	}
	close(connfd);
	return 0;
}

#endif

#if 1


//sendfile函数
int main()
{
	
	return 0;
}

#endif
