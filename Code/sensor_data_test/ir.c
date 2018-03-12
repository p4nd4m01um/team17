#include "ir.h"

int Read_PIRsensor(){
	sleep(2);                    //to stablize the sensor
	int a;
	pinMode(PIR , INPUT);
	a = digitalRead(PIR);
	if (a==1){
		printf("motion detected \n");
	}
	else{
		printf("nothing detected \n");
	}

	return a;
}
