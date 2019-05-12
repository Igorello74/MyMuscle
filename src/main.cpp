#define DEBUG	//debug on/off, comment to disable debug
#define DEMO	//means that it doesn't care of potentiometers and uses a generator (increases frequency and then resets)

#include <Arduino.h>
#include "MyMuscle.h"

void setup() {
	libInit(); //libraries initialization
	lcdWelcome(); //a welcome message on the lcd display
	Timer1.pwm(VALVE_PIN, VALVE_DEFAULT_DUTY, VALVE_DEFAULT_PERIOD); //start generating PWM
	
}

void loop() {
	
	delay(CYCLE_DELAY);
	debug("Tick");
}