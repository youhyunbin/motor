#ifndef MOTOR2_H
#define MOTOR2_H

#include <wiringPi.h>

#define OUT5 5
#define OUT6 6
#define OUT7 13
#define OUT8 19

void setSteps(int y1, int y2, int y3, int y4){
  pinMode(OUT5,OUTPUT);
  digitalWrite(OUT5,y1);
  pinMode(OUT6,OUTPUT);
  digitalWrite(OUT6,y2);
  pinMode(OUT7,OUTPUT);
  digitalWrite(OUT7,y3);
  pinMode(OUT8,OUTPUT);
  digitalWrite(OUT8,y4);
}

void forward2(int steps2){
  int j;
  for(j=0;j<=steps2;j++){
    setSteps(1,1,0,0); // setSteps(w5,w6,w7,w8)
    delay(10);
    setSteps(0,1,1,0);
    delay(10);
    setSteps(0,0,1,1);
    delay(10);
    setSteps(1,0,0,1);
    delay(10);
  }
}

#endif
