#include<iostream>
#include"MyDB.h"

using namespace std;


int main()
{
	MyDB db;
	db.initDB("localhost","pi","","test");
	db.exeSQL("INSERT accounts values('team17','123');");
	db.exeSQL("INSERT accounts values('team18','456');");
	db.exeSQL("SELECT * from accounts;");

	return 0;
}
