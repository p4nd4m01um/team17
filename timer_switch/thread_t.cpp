#include<iostream>
#include"MyDB.h"
#include<string>
#include<ctime>
#include<thread>
#include<unistd.h>
using namespace std;

void search(){
	MyDB db_2;
	db_2.initDB("localhost", "pi", "", "test");
	while(1){
		sleep(5);
	//	delay(500);
		db_2.exeSQL("SELECT * from accounts;");
	}
}

int main(){
	MyDB db;
	db.initDB("localhost","pi","","test");
//	search(db);
	thread t1(search);
//	thread t1(search, std::ref(db));
//	thread1.join();
	t1.detach();
	int variable;
	string value;
	while(1){
	//	delay(300);
		clock_t start = clock();
		sleep(3);
		variable = time(0);
		value = "UPDATE accounts SET passwd='" + to_string(variable) + "' WHERE name='team18';";
//	db.exeSQL("UPDATE accounts SET passwd='" + value + "' WHERE name='team18';");
		db.exeSQL(value);
		db.exeSQL("SELECT * from accounts;");
		clock_t end = clock();
		cout<<"spend"<<(double)(end - start)/CLOCKS_PER_SEC<<"SECOND"<<endl;
	}
	return 0;
}
