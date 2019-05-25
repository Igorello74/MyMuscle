#define MY_DEBUG	//debug on/off, comment to disable debug
#define MY_DEMO		//means that it doesn't care of potentiometers and uses a generator (increases frequency and then resets)

#include <Arduino.h>

byte freq, duty; // it HAS TO be global, otherwise it's impossible
char currentKey; // that too

#include "MyMuscle.h"


void setup() {
	libInit(); //libraries initialization
	
	menu::greeting(); //display greeting lines
	
	valve::pwm(VALVE_DEFAULT_DUTY,
		VALVE_DEFAULT_FREQ); //start generating PWM
	
}

void keyHandler() {
	if (currentKey >= '1' and currentKey <= '9') {
		menu::menu.call_function(MENU_ADD_NUMB);
	}
	else if (currentKey == 'Y') {
		valve::pwm(duty, freq);
}

void loop() {
	currentKey = matrix::matrix.getKey();
	
	if (currentKey) keyHandler();
	
	delay(CYCLE_DELAY);
	debug("Tick");
}