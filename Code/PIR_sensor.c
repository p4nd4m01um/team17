#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PIR    8
#define motor  10

int Read_PIRsensor()
{
int a;
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
    int sensor;
    sensor=Read_PIRsensor();
    if ( sensor ){
      digitalWrite(motor, LOW);

    }
    else{
      digitalWrite(motor, HIGH);
       }
     delay(1000);
    printf("%d \n",sensor); 
  }
 return 0;
}
