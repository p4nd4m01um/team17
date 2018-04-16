
#include"sensor.h"

sensor::sensor(){		//constructor sets pin mode when the object is created.

	pinMode(MOTOR_PIN, OUTPUT);
	pinMode(POWER_PIN,INPUT);
	pinMode(PIR_PIN, INPUT);

}

void sensor::readIrSensor(){


	while(1){

		sleep(1);

		this->pow = digitalRead(POWER_PIN); //read the main power circumstance (whether user trun on/off the toggle) 

		if (this->pow == 1){

			this->ir = digitalRead(PIR_PIN); //read PIR sensor pin value

			if (this->ir==1){

				cout<<"=================="<<endl;
				cout<<"motion detected \n"<<endl;
				cout<<"=================="<<endl;

				digitalWrite(MOTOR_PIN, LOW); //stop the motor

				this->irDetect = true; // true on the detected value (the temperature & humidity sensor stop working )

				auto startIr = system_clock::now();
				sleep(5);		//stop for 5 second for pedestrian pass through.
				this->irDetect = false;
				auto endIr = system_clock::now();
                       		auto durationIr = duration_cast<microseconds>(endIr - startIr);
                       		cout<<"sleep ->>"<<double(durationIr.count()) * microseconds::period::num/microseconds::period::den<<"Second"<<endl;

			}

			else{
				cout<<"=================="<<endl;
				cout<<"Nothing detected\n"<<endl;
				cout<<"=================="<<endl;

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
			cout<<"==================================================================="<<endl;
			cout<<"Temperature :"<< this->data_temp<<" Humidity : "<< this->data_hum<<endl;
			cout<<"==================================================================="<<endl;
			cout<<"Fetching T&H spends ->>"<<double(duration.count()) * microseconds::period::num/microseconds::period::den<<"Second"<<endl;
			cout<<"==================================================================="<<endl;
			sleep(3); //sleep for 3 seconds and then start for next data fetching.


		}

	}
}

void sensor::snowCal(){

	// this is a equation which produces a icing probability with the given temperature and humidity values.
	this->data_reHum = 9.5 * exp((-17.27*this->data_temp)/(this->data_temp + 238.3))*(10.5 - this->data_temp);
	this->data_snowPro = this->data_reHum/this->data_hum;

	cout<<"====================="<<endl;
	cout<<"The main power is "<<this->pow<<endl;
	cout<<"====================="<<endl;
	cout<<"Icing probability value ===>"<<this->data_snowPro<<endl;
	cout<<"====================="<<endl;

	this->pow = digitalRead(POWER_PIN);

	if (this->pow ==1){

		//Since we do not have snow condition outdoors right now
		//the indoor temperature and humidity are unlikly to trigger the motor
		//So, we set a threshould which suitable for triggering the motor with the indoor weather conditions.
		//With indoor weather condition, the calculator gives icing value around "-0.7", we set "-0.6" as the threshould to trriger motor.
		if (this->data_snowPro <= -0.6 && this->irDetect == false){

			cout<<"It will snow"<<endl;

			digitalWrite(MOTOR_PIN, HIGH);
			cout<<"==========================="<<endl;
			cout<<"Motor starts for 10 seconds"<<endl;
			sleep(10);

			cout<<"==========================="<<endl;
			cout<<"Motor stops for 6 hours"<<endl;
			digitalWrite(MOTOR_PIN,LOW);
			sleep(20); //for testing we set 20 seconds

			cout<<"============================"<<endl;
			cout<<"Trigger starts working again"<<endl;
			cout<<"============================"<<endl;
		}
		else{
			digitalWrite(MOTOR_PIN, LOW);
		}

	}
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

bool sensor::getPow(){

	return this->pow;
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
void sensor::setPow(bool input){

	this->pow = input;
}
