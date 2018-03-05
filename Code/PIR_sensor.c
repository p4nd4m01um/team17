#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PIR		8
#define motor 9

int Read_PIRsensor()
{
pinMode(PIR , INPUT);
a= digitalRead(PIR);
return a;
}

int main ()
{
  if (wiringPiSetup()==-1)
    exit(1);
  pinMode(motor , OUTPUT);
  if ( Read_PIRsensor() )
    digitalwrite(motor, LOW)

}
