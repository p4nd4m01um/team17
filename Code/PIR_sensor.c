#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PIR    8
#define motor  10

int Read_PIRsensor()
{
pinMode(PIR , INPUT);
a= digitalRead(PIR);
return a;
}

int main (void)
{
  wiringPiSetup () ;
  
  pinMode(motor , OUTPUT);
  while(1)
  {
    if ( Read_PIRsensor() ){
      digitalwrite(motor, LOW);
    }
    else{
      digitalwrite(motor, HIGH);
    }
  }
 return 0;
}
