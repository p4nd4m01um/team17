#include<iostream>

using namespace std;

extern"C"{
	#include "ths.h"
}

int main(){
	int dht_11_val[5];
	float dht22[2];
	if(wiringPiSetup()==-1){
		exit(1);
	}
	while(1){
		dht11_read_val(dht_11_val, dht22);
		//delay(1000);
		//cout<<"this is value:"<<dht22[0]<<"this is value2:"<<dht22[1]<<endl;
	}
	return 0;
}
