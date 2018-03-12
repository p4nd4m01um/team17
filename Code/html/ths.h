#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>

#define MAX_TIME 100
#define DHT11PIN 7
#define ATTEMPTS 5
//int dht11_val[5] = {0,0,0,0,0};
extern int dht11_read_val(int dht11_val[], float dht22[]);
