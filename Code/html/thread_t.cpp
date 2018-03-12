#include<iostream>
#include"MyDB.h"
#include<string>
#include<ctime>
#include<thread>
#include<unistd.h>
#include<cmath>

extern"C"{
	#include "ths.h"
	#include "ir.h"
}

using namespace std;

void search(){
	// query data
	MyDB db_2;
	db_2.initDB("localhost", "pi", "", "sensor");
	while(1){
		sleep(5);
		db_2.exeSQL("SELECT * from THS;");
	}
}

float calculator(float temp, float humd){

	float eq1, eq1_1, eq2, c_humd, result;

	cout<<"input temp :"<<temp<<endl;
	cout<<"input humd :"<<humd<<endl;

	eq1 = (-17.27*temp)/(temp +238.3);
	eq1_1 = exp(eq1);
	eq2 = (10.5 - temp);


	c_humd = 9.5 * eq1_1 * eq2 *0.01;

	cout<< "c_humd is :"<< c_humd <<endl;

	result = c_humd/humd;

	if (result >= 1){
		cout<< "it will snow" <<endl;
	}
	else{
		cout<< "Probability for any precipitation to be snow is about "<< result*10 <<endl;
	}

	result = result*100;
	return result;
}


void data_store(){

	float variable, variable2, dht22[2];
        int dht_11_val[5];
        string value;
	MyDB db;// initiate data obj 
        db.initDB("localhost","pi","","sensor");


	while(1){//read data from sensor and store it to database
                dht11_read_val(dht_11_val,dht22);
                sleep(3);
                variable = dht22[0];
                variable2 = dht22[1];
                value = "UPDATE THS SET value='" + to_string(variable) + "',value2='" + to_string(variable2) + "' WHERE name='t&h';";
                db.exeSQL(value);
        }
}


int main(){

	thread t1(search);//thread for query
	t1.detach();

	if(wiringPiSetup()==-1){
		exit(1);
	}
	thread t2(data_store);
	t2.detach();
	int ir;

	while(1){
		ir = Read_PIRsensor();
		if (ir == 1){
			digitalWrite(motor, HIGH);
			cout<<"ir is hight now"<<endl;
			sleep(5);
			ir = 0;
		}
		else{
			digitalWrite(motor,LOW);
			cout<<"ir is low now"<<endl;
		}
	}

	return 0;
}
