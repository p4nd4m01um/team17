#include<iostream>
#include<wiringPi.h>
#include<unistd.h>
#include<cmath>
#include<chrono>

#define PIR_PIN   0
#define MOTOR_PIN 3
#define DHT22_PIN 7
#define POWER_PIN 4
#define MAX_TIME 100
#define ATTEMPTS 5

using namespace std;
using namespace chrono;


#ifndef SENSOR_H
#define SENSOR_H

class sensor {
	private:
		int ir, data_tempHumSensor[5], pow;
		float data_temp, data_hum, data_reHum, data_snowPro;
		bool irDetect, startMotor;
		double rest, startMT;


	public:
		sensor();

		void readIrSensor();
		void readTempHumSensor();
		void snowCal();

		float getTemp();
		float getHum();
		float getSnowPro();
		float getReHum();
		bool getPow();
		int getIr();

		void setTemp(float input);
                void setHum(float input);
                void setSnowPro(float input);
                void setReHum(float input);
                void setIr(int input);
		void setPow(bool input);





};
#endif

