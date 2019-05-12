#define MY_DEBUG	//debug on/off, comment to disable debug
#define MY_DEMO		//means that it doesn't care of potentiometers and uses a generator (increases frequency and then resets)

#include <Arduino.h>
#include "MyMuscle.h"

byte freq, duty;

#include "menu.h" // a file with definitions of some objects from LiquidMenu

void setup() {
	libInit(); //libraries initialization
	Timer1.pwm(VALVE_PIN, VALVE_DEFAULT_DUTY, VALVE_DEFAULT_PERIOD); //start generating PWM
	
}

void loop() {
	
	delay(CYCLE_DELAY);
	debug("Tick");
}