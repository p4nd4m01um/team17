

#ifndef SENSOR_H
#define SENSOR_H

class sensor {
	private:
		int ir, data_tempHumSensor[5];
		float data_temp, data_hum, data_reHum, data_snowPro;

	public:

		void readIrSensor();
		void readTempHumSensor();
		void snowCal();
		float getTemp();
		float getHum();
		float getSnowPro();
		float getReHum();





};
#endif

