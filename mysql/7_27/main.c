#include <stdio.h>
#include <string.h>
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
	if(NULL == mysql_real_connect(&mysql,"localhost","root","19961102","information",0,NULL,0))
	{
		printf("mysql_real_connect():%s\n",mysql_error(&mysql));
		return -1;
	}

	printf("Connect Mysql successful\n");

	char *query = "insert into nature(name,passwd,idnumber) values('yang','1234',1)";
	int flag = mysql_real_query(&mysql,query,(unsigned int)strlen(query));
	if(!flag)
		printf("insert data OK\n");
	else
	{
		printf("insert data failure");
		return -1;
	}
	mysql_close(&mysql);
	return 0;
}
