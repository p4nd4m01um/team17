#include "catch.hpp"
#include<iostream>
#include<wiringPi.h>
#include<unistd.h>
#include"Sensor/sensor.h"
#include<cmath>

#define CATCH_CONFIG_MAIN

#define PIR   0
#define motor 3

#define MAX_TIME 100
#define DHT11PIN 7
#define ATTEMPTS 5

sensor s1;

using namespace std;

void sensor::readIrSensor(){


	pinMode(PIR , INPUT);
	while(1){
		sleep(1);
		this->ir = digitalRead(PIR);

		if (this->ir==1){
			cout<<"motion detected \n"<<endl;
			digitalWrite(motor, HIGH);
		}
		else{
			digitalWrite(motor,LOW);
			cout<<"nothing detected \n"<<endl;
		}
	}

}


void sensor::snowCal(){

	this->data_reHum = 9.5 * exp((-17.27*this->data_temp)/(this->data_temp + 238.3))*(10.5 - this->data_temp);
	this->data_snowPro = this->data_reHum/this->data_hum;
        if (this->data_snowPro <= -0.6){
		cout<<"it will snow"<<endl;
		digitalWrite(motor, HIGH);
	}
	cout<<this->data_snowPro<<endl;
}


TEST_CASE( "formula to calculate if it will snow", "[formula]" ) {
    REQUIRE( s1.getSnowPro() == 1 );
    REQUIRE( s1.getSnowPro() == 2 );
    REQUIRE( s1.getSnowPro() == 6 );
    REQUIRE( s1.getSnowPro() == 3628800 );
}

