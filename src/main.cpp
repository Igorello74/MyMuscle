#define DEBUG //debug on/off, comment to disable

#include <Arduino.h>
#include "MyMuscle.h"

Stick sticks[2]={
	Stick(STICK1_PIN,STICK1_MINVAL,STICK1_MAXVAL),
	Stick(STICK2_PIN,STICK2_MINVAL,STICK2_MAXVAL)
};

void setup() {
  // put your setup code here, to run once:
	libInit();
}

void loop() {
    // put your main code here, to run repeatedly:

}