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

	float r_humd, result;

	cout<<"input temp is :"<<temp<<endl;
	cout<<"input humd is :"<<humd<<endl;

	r_humd = 9.5 * exp((-17.27*temp)/(temp + 238.3))*(10.5 - temp);

	cout<< "r_humd is :"<< r_humd <<endl;

	result = r_humd/humd;


	return result;
}


void data_store(){

	float variable, variable2, dht22[2];
        int dht_11_val[5];
	float pop;
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

		//call caculator to measure the probability;
		pop = calculator(variable, variable2);

		if (pop >= 0.99){
                	cout<< "it will snow: it is " <<endl;
			digitalWrite(motor, HIGH);
			cout<<"motor on"<<endl;
        	}
        	else if (pop <= 0){
                	cout<< "it will snow in hell before it does here"<<endl;
        	}
        	else{
                	cout<< "Probability for any precipitation to be snow is about "<< pop*100<<"%"<<endl;
        	}

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
