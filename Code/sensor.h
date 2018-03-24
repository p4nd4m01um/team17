

#ifndef SENSOR_H
#define SENSOR_H

class sensor {
	private:
		int ir, data_tempHumSensor[5];
		float data_temp, data_hum;

	public:

		void readIrSensor();
		void readTempHumSensor();

		int getTemp();
		int getHum();





};
#endif

