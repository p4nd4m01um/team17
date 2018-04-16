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


TEST_CASE( "Base on the Humidity and Tem to calculate if it will snow  ", "[argument]" ) {
    
    SECTION( "Set the humidity and temperature to test" ) {
	s1.setSnowPro(0);
        s1.setTemp(10);
	s1.setHum(20.5);  
	s1.setIrDetect(true);
        s1.snowCal();
        REQUIRE( s1.getSnowPro() == 0 );
    }
    SECTION( "Reset the humidity and temperature to test " ) {
	s1.setSnowPro(0);
	s1.setTemp(4.5);
	s1.setHum(60.5);
	s1.setIrDetect(false);
        s1.snowCal();
        REQUIRE( s1.getSnowPro() == 0.684087 );
    }
    SECTION( "Reset the humidity and temperature to test" ) {
	s1.setSnowPro(0);
        s1.setTemp(1.0);
	s1.setHum(70); 
	s1.setIrDetect(false);
        s1.snowCal();
        REQUIRE( s1.getSnowPro() == 1.19952 );
    }
    SECTION( "Used a wrong number to test" ) {
	s1.setSnowPro(0);
        s1.setTemp(1.0);
	s1.setHum(70);  
	s1.setIrDetect(false);
        s1.snowCal();
        REQUIRE( s1.getSnowPro() == 0.8 );
    }

}

TEST_CASE("Test Humidity and Temperature sensor"){
	s1.readTempHumSensor();	
        REQUIRE( s1.getHum()<=100);
	REQUIRE( s1.getTemp()>=-20);
}


TEST_CASE("Test PIR sensor")
{
     SECTION("Test the PIR sensor pow=1"){
	s1.setIr(1);
	s1.setPow(1);
	s1.readIrSensor();	
        REQUIRE( s1.getIr() == 1 );
    }
     SECTION("Test the PIR sensor pow=1"){
	s1.setIr(0);
	s1.setPow(1);
	s1.readIrSensor();	
        REQUIRE( s1.getIr() == 0 );
     }
     SECTION("Test the PIR sensor pow=0"){
	s1.setPow(0);
	s1.setIr(1);
	s1.readIrSensor();	
        REQUIRE( s1.getIr() == 0 );
    }
     SECTION("Test the PIR sensor pow=0"){
	s1.setIr(0);
	s1.setPow(0);
	s1.readIrSensor();	
        REQUIRE( s1.getIr() == 0 );
     }
}


