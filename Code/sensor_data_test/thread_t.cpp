#include<iostream>
#include"MyDB.h"
#include<string>
#include<ctime>
#include<thread>
#include<unistd.h>

extern"C"{
	#include "ths.h"
}

using namespace std;

void search(){
	MyDB db_2;
	db_2.initDB("localhost", "pi", "", "sensor");
	while(1){
		sleep(5);
		db_2.exeSQL("SELECT * from THS;");
	}
}

int main(){
	MyDB db;
	db.initDB("localhost","pi","","sensor");

	thread t1(search);

	t1.detach();

	float variable, variable2, dht22[2];
	int dht_11_val[5];
	string value;
	if(wiringPiSetup()==-1){
		exit(1);
	}
	while(1){
		dht11_read_val(dht_11_val,dht22);

		sleep(3);
		variable = dht22[0];
		variable2 = dht22[1];

		value = "UPDATE THS SET value='" + to_string(variable) + "',value2='" + to_string(variable2) + "' WHERE name='t&h';";

		db.exeSQL(value);
	}
	return 0;
}
