#include<mysql/mysql.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
   
int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char server[]="localhost";
	char user[]="root";
	char password[]="rygc";
	char database[]="mysql";

	conn=mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		cout<<"init error"<<endl;
		exit(1);
	}

	if(mysql_query(conn,"show tables"))
	{
		cout<<"query error"<<endl;
		exit(1);
	}

	res=mysql_use_result(conn);

	while((row=mysql_fetch_row(res))!=NULL)
	{
		cout<<row[0]<<endl;	
	}

	mysql_free_result(res);
	mysql_close(conn);



	return 0;
}
