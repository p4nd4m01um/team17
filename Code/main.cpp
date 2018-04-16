#include<iostream>
#include"MySql/MyDB.h"
#include"Sensor/sensor.h"
#include<wiringPi.h>
#include<thread>
#include<cmath>
#include<string>
#include<unistd.h>

using namespace std;

int main(){

	sensor s1;
	MyDB db;
	db.initDB("localhost", "pi", "", "sensor");



	if(wiringPiSetup()==-1){
		exit(1);
	}


	thread t1(&sensor::readIrSensor, &s1); // thread 1 -- read IR sensor
	t1.detach();

	thread t2(&sensor::readTempHumSensor, &s1); // thread 2 -- read temperature and humidity sensor
	t2.detach();


	while(1){

		sleep(3);
		db.update(s1.getTemp(),s1.getHum()); // update the the data into database
		s1.snowCal();	//run calculator and trigger

	}

	return 0;


}
