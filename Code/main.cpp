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


	thread t1(&sensor::readIrSensor, &s1);
	t1.detach();

	thread t2(&sensor::readTempHumSensor, &s1);
	t2.detach();


	while(1){
		sleep(3);
		db.update(s1.getTemp(),s1.getHum());
		s1.snowCal();
		sleep();
	}

	return 0;


}
