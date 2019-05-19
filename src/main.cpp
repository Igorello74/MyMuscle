#define MY_DEBUG	//debug on/off, comment to disable debug
#define MY_DEMO		//means that it doesn't care of potentiometers and uses a generator (increases frequency and then resets)

#include <Arduino.h>
byte freq, duty;
#include "MyMuscle.h"


void setup() {
	libInit(); //libraries initialization
	
	menu::welcome(); //display greeting lines
	
	Timer1.pwm(VALVE_PIN, VALVE_DEFAULT_DUTY,
		VALVE_DEFAULT_PERIOD); //start generating PWM
	
}

void loop() {
	
	delay(CYCLE_DELAY);
	debug("Tick");
}

// ----------------------------------------------------------TO USE LATER
/*
void keyHandler(KeypadEvent key) {
	switch (keypad.getState())	{
		case PRESSED:
			if (key >= "1" and key <= "9") { // range 48-57 is digits in ASCII table
				NULL;
			}
			break;
	
		default:
			NULL;
			break;
	}
}
*/