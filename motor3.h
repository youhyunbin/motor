#ifndef MOTOR3_H
#define MOTOR3_H

#include <wiringPi.h>

#define OUT9 16
#define OUT10 20

void forward1(int time){
  int t;
  for(t=0;t<=time;t++)
  {
    pinMode(OUT9,OUTPUT);
    pinMode(OUT10,OUTPUT);
    digitalWrite(OUT9,LOW);
    digitalWrite(OUT10,HIGH);
    delay(time*17);
    digitalWrite(OUT9,LOW);
    digitalWrite(OUT10,LOW);
  }
}

#endif
