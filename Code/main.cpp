#include<iostream>
#include "sensor.h"
#include<wiringPi.h>

int main(){
	
	sensor s1;

	if(wiringPiSetup()==-1){
		exit(1);
	}


//	s1.readIrSensor();
	s1.readTempHumSensor();



	return 1;


}
