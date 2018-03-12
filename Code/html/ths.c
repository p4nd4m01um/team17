#include "ths.h"


int dht11_read_val(int dht11_val[], float dht22[])
{
	uint8_t lststate=HIGH; //last state
	uint8_t counter=0;
	uint8_t j=0,i;
	float *result[2];

	for(i=0;i<5;i++){
		dht11_val[i] = 0;
	}

	//host send start signal
	pinMode(DHT11PIN,OUTPUT); //set pin to output 
	digitalWrite(DHT11PIN,LOW); //set to low at least 18ms 
	delay(18);
	digitalWrite(DHT11PIN,HIGH); //set to high 20-40us
	delayMicroseconds(30);
	//start recieve dht response
	pinMode(DHT11PIN,INPUT); //set pin to input
	for(i=0;i<MAX_TIME;i++)
	{
		counter=0;
		while(digitalRead(DHT11PIN)==lststate)
		{ //read pin state to see if dht responsed. if dht always high for 255 + 1 times, break this while circle
			counter++;
			delayMicroseconds(1);
			if(counter==255)
     			{
     				break;
     			}

		}

		lststate=digitalRead(DHT11PIN); //read current state and store as last state. 
		if(counter==255) //if dht always high for 255 + 1 times, break this for circle
		{
			break;
		}

		// top 3 transistions are ignored, maybe aim to wait for dht finish response signal
		if((i>=4)&&(i%2==0))
		{
			dht11_val[j/8]<<=1; //write 1 bit to 0 by moving left (auto add 0)
			if(counter>16) //long mean 1
			dht11_val[j/8]|=1; //write 1 bit to 1 
			j++;
		}
	}

	// verify checksum and print the verified data
	if((j>=40)&&(dht11_val[4]==((dht11_val[0]+dht11_val[1]+dht11_val[2]+dht11_val[3])& 0xFF)))
	{
		float f, h;

		h = dht11_val[0] * 256 + dht11_val[1];
		h /= 10;
		f = (dht11_val[2] & 0x7F)* 256 + dht11_val[3];
		f /= 10.0;
		if (dht11_val[2] & 0x80) f *= -1;
		printf("Temp = %.1f *C, Hum = %.1f \%\n", f, h);
	
		dht22[0] = f;
		dht22[1] = h;

		return 1;
	}
	else
	{
		return 0;
	}

}
