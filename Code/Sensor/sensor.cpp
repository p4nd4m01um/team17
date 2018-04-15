
#include"sensor.h"

sensor::sensor(){

	pinMode(MOTOR_PIN, OUTPUT);
	pinMode(POWER_PIN,INPUT);
	pinMode(PIR_PIN, INPUT);

}

void sensor::readIrSensor(){


	while(1){

		sleep(1);
		this->pow = digitalRead(POWER_PIN);

		if (this->pow == 1){

			this->ir = digitalRead(PIR_PIN);

			if (this->ir==1){
				cout<<"motion detected \n"<<endl;
				digitalWrite(MOTOR_PIN, LOW);
				this->irDetect = true;
				auto startIr = system_clock::now();
				sleep(10);
				this->irDetect = false;
				auto endIr = system_clock::now();
                       		auto durationIr = duration_cast<microseconds>(endIr - startIr);
                       		cout<<"sleeep ->>"<<double(durationIr.count()) * microseconds::period::num/microseconds::period::den<<"Second"<<endl;


			}

			else{
				cout<<"nothing detected \n"<<endl;

			}
		}

	}

}

void sensor::readTempHumSensor(){

	while(1){

		auto start = system_clock::now();
		uint8_t lststate = HIGH; //last state
		uint8_t counter = 0;
		uint8_t j = 0, i;

		for(i=0; i<5; i++){
			this->data_tempHumSensor[i] = 0;
		}

		//host send start signal
		pinMode(DHT22_PIN,OUTPUT); //set pin to output
		digitalWrite(DHT22_PIN,LOW); //set to low at least 18ms
		delay(18);
		digitalWrite(DHT22_PIN,HIGH); //set to high 20-40us
		delayMicroseconds(30);
		//start recieve dht response
		pinMode(DHT22_PIN,INPUT); //set pin to input

		for(i=0; i<MAX_TIME; i++){

			counter=0;
			while(digitalRead(DHT22_PIN) == lststate){
			 //read pin state to see if dht responsed. if dht always high for 255 + 1 times, break this while circle
				counter++;
				delayMicroseconds(1);
				if(counter == 255){
	     				break;
     				}

			}

			lststate = digitalRead(DHT22_PIN); //read current state and store as last state. 
			if(counter == 255){ //if dht always high for 255 + 1 times, break this for circle

				break;
			}

			// top 3 transistions are ignored, maybe aim to wait for dht finish response signal
			if((i >= 4)&&(i%2 == 0)){
				this->data_tempHumSensor[j/8]<<=1; //write 1 bit to 0 by moving left (auto add 0)
				if(counter > 16) //long mean 1
				this->data_tempHumSensor[j/8]|=1; //write 1 bit to 1 
				j++;
			}
		}

		// verify checksum and print the verified data
		if((j>=40)&&(this->data_tempHumSensor[4]==((this->data_tempHumSensor[0] +
							    this->data_tempHumSensor[1] +
							    this->data_tempHumSensor[2] +
							    this->data_tempHumSensor[3]) & 0xFF))){

			this->data_hum = this->data_tempHumSensor[0] * 256 + this->data_tempHumSensor[1];
			this->data_hum /= 10;
			this->data_temp = (this->data_tempHumSensor[2] & 0x7F)* 256 + this->data_tempHumSensor[3];
			this->data_temp /= 10.0;

			if (this->data_tempHumSensor[2] & 0x80){
				this->data_temp *= -1;
			}

			auto end = system_clock::now();
			auto duration = duration_cast<microseconds>(end - start);

			cout<<"Temperature :"<< this->data_temp<<" Humidity : "<< this->data_hum<<endl;
			cout<<"spend ->>"<<double(duration.count()) * microseconds::period::num/microseconds::period::den<<"Second"<<endl;

			sleep(3);


		}

	}
}

void sensor::snowCal(){

	this->data_reHum = 9.5 * exp((-17.27*this->data_temp)/(this->data_temp + 238.3))*(10.5 - this->data_temp);
	this->data_snowPro = this->data_reHum/this->data_hum;
	cout<<"the pow number is "<<this->pow<<endl;

	this->pow = digitalRead(POWER_PIN);

	if (this->pow ==1){

		cout<<"run snow"<<endl;
		if (this->data_snowPro <= -0.6 && this->irDetect == false){

			cout<<"it will snow"<<endl;
			this->startMotor = true;
			this->startMotorTime = system_clock::now();


                        this->duration = duration_cast<microseconds>(endIr - startIr);
                        double(duration.count()) * microseconds::period::num/microseconds::period::den<<"Second"<<endl;




                        this->irDetect = false;

			digitalWrite(MOTOR_PIN, HIGH);
			sleep(30);

		}
	}
	else{
		digitalWrite(MOTOR_PIN, LOW);
	}

	cout<<"snow pro===>"<<this->data_snowPro<<endl;
}

float sensor::getTemp(){

	return this->data_temp;
}

float sensor::getHum(){

	return this->data_hum;
}

float sensor::getSnowPro(){

	return this->data_snowPro;
}

float sensor::getReHum(){

	return this->data_reHum;
}

int sensor::getIr(){

	return this->ir;
}

void sensor::setTemp(float input){

	this->data_temp = input;
}

void sensor::setHum(float input){

        this->data_hum = input;
}

void sensor::setSnowPro(float input){

        this->data_snowPro = input;
}

void sensor::setReHum(float input){

        this->data_reHum = input;
}

void sensor::setIr(int input){

	this->ir = input;
}
