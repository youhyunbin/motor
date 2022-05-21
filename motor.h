#ifndef MOTOR_H
#define MOTOR_H

#include <wiringPi.h>

#define OUT1 22
#define OUT2 23
#define OUT3 24
#define OUT4 25

void setSteps(int x1, int x2, int x3, int x4){
  pinMode(OUT1,OUTPUT);
  digitalWrite(OUT1,x1);
  pinMode(OUT2,OUTPUT);
  digitalWrite(OUT2,x2);
  pinMode(OUT3,OUTPUT);
  digitalWrite(OUT3,x3);
  pinMode(OUT4,OUTPUT);
  digitalWrite(OUT4,x4);
}

void forward3(int steps){
  int i;
  for(i=0;i<=steps;i++){
    setSteps(1,1,0,0);
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
