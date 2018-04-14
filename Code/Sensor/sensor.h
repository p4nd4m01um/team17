#include<iostream>
#include<wiringPi.h>
#include<unistd.h>
#include<cmath>
#include<chrono>

#define PIR   0
#define motor 3
#define MAX_TIME 100
#define DHT11PIN 7
#define ATTEMPTS 5
#define POWER 4
using namespace std;
using namespace chrono;


#ifndef SENSOR_H
#define SENSOR_H

class sensor {
	private:
		int ir, data_tempHumSensor[5], pow;
		float data_temp, data_hum, data_reHum, data_snowPro;

	public:

		void readIrSensor();
		void readTempHumSensor();
		void snowCal();

		float getTemp();
		float getHum();
		float getSnowPro();
		float getReHum();
		int getIr();
		void setTemp(float input);
                void setHum(float input);
                void setSnowPro(float input);
                void setReHum(float input);
                void setIr(int input);





};
#endif

