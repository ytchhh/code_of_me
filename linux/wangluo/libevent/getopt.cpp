#include <stdio.h>
#include <unistd.h>

/*

	int getopt(int argc,char * const argv[ ],const char * optstring);
	extern char* optarg 保存选项的参数
	extern int optind 记录下一个检索位置
	extern int opterr 是否将错误信息输出到stderr
	extern int optopt 不在选项字符串optstring中的选项
*/
#if 1
int main(int argc,char *argv[])
{
	int ch;
	printf("\n\n");
	printf("optind:%d,opterr:%d\n",optind,opterr);
	printf("------------------------------------\n");
	while((ch = getopt(argc,argv,"ab:c:de::")) != -1)
	{
		printf("optind: %d\n",optind);
		switch(ch)
		{
			case 'a':
				printf("Have option:-a\n\n");
				break;
			case 'b':
				printf("Have option: -b\n");
				printf("The argument of -b is %s\n\n",optarg);
				break;
			case 'c':
				printf("Have option: -c\n");
				printf("The argument of -c is %s\n\n",optarg);
				break;
			case 'd':
				printf("Have option: -d\n");
				break;
			case 'e':
				printf("Have option: -e\n");
				printf("The argument of -e is %s\n\n",optarg);
				break;
			case '?':
				printf("Unknown option: %c\n",(char)optopt);
				break;
		}
	}
	return 0;
}
/*
	./a.out -b "qing er" -c1234
	optind:1,opterr:1
	------------------------------------
	optind: 3
	Have option: -b
	The argument of -b is qing er

	optind: 4
	Have option: -c
	The argument of -c is 1234
////////////////////////////////////////
	./a.out -zheng
	optind:1，opterr：1
	--------------------------
	./main: invalid option -- 'z'
	optind: 1
	Unknown option: z
	./main: invalid option -- 'h'
	optind: 1
	Unknown option: h
	optind: 2
	HAVE option: -e
	The argument of -e is ng
*/

#endif
#if 0
int main(int argc,char *argv[])
{
	int i;
	printf("--------------------\n");
	for(i = 0; i < argc; ++i)
		printf("%s\n",argv[i]);
	printf("--------------------\n");

	int ch;
	printf("\n\n");
	printf("optind:%d,opterr:%d\n",optind,opterr);
	printf("--------------------\n");
	while((ch=getopt(argc,argv,"ab:c:de::")) != -1)
	{
		printf("optind:%d\n",optind);
		switch(ch)
		{
			case 'a':
				printf("Have option:-a\n\n");
				break;
			case 'b':
				printf("Have option:-b\n");
				printf("The argument of -b is %s\n\n",optarg);
				break;
			case 'c':
				printf("The option:-c\n");
				printf("The argument of -c is %s\n\n",optarg);
				break;
			case 'd':
				printf("The optind:-d\n");
				break;
			case 'e':
				printf("Have option:-e\n");
				printf("The argument of -e is %s\n\n",optarg);
				break;
			case '?':
				printf("Unknown option:%c\n",(char)optopt);
				break;
		}
	}
	printf("-------------\n");
	printf("optind=%d,argv[%d]=%s\n",optind,optind,argv[optind]);

	printf("-------------\n");
	for(i = 0; i < argc; ++i)
		printf("%s\n",argv[i]);
	printf("-------------\n");
	return 0;
}

/*
	./a.out zheng -b "qing er" han -c123 qing
	--------------------
	./a.out
	zheng
	-b
	qing er
	han
	-c123
	qing
	--------------------


	optind:1,opterr:1
	--------------------
	optind:4
	Have option:-b
	The argument of -b is qing er

	optind:6
	The option:-c
	The argument of -c is 123

	-------------
	optind=4,argv[4]=zheng
	-------------
	./a.out
	-b
	qing er
	-c123
	zheng
	han
	qing
	-------------
*/

#endif
