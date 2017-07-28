#include <stdio.h>
#include <mysql.h>

int main()
{
	MYSQL mysql;

	if(NULL == mysql_init(&mysql))
	{
		printf("mysql_init();%s\n",mysql_error(&mysql));
		return -1;
	}

	//尝试与主机上的Mysql数据库引擎建立连接
	if(NULL == mysql_real_connect(&mysql,"localhost","root","shallnet","db_users",0,NULL,0))
	{
		printf("mysql_real_connect():%s\n",mysql_error(&mysql));
		return -1;
	}

	printf("Connect Mysql successful\n");
	mysql_close(&mysql);
	return 0;
}
