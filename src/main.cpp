#define MY_DEBUG	//debug on/off, comment to disable debug
#define MY_DEMO
//means that it doesn't care of potentiometers and uses a generator (increases frequency and then resets)

#include <Arduino.h>

byte freq, duty; // it HAS TO be global, otherwise it's impossible
char currentKey; // that too

#include "MyMuscle.h"


void setup() {
	libInit(); //libraries initialization
	
	menu::greeting(); //display greeting lines
	
	valve::pwm(VALVE_DEFAULT_DUTY,
		VALVE_DEFAULT_FREQ); //start generating PWM
	debug("PWM initialization competed");
	
	timerStart();
	
}

void keyHandler() {
	debug("'" + String(currentKey)+"' was pressed");
	
	if (currentKey >= '1' and currentKey <= '9') {
		menu::menu.call_function(MENU_ADD_DIGIT);
		debug("A digit was added");
	}
	else if (currentKey == 'Y') {
		valve::pwm(duty, freq);
		debug(
			"New parameters was applied:\n\tfrequency = " +
			String(freq) +
			"\n\t duty = " +
			String(duty)
		);
	}
	else if (currentKey == 'N') {
		menu::menu.call_function(MENU_CLEAN);
	}
	else if (currentKey == '*') {
		menu::menu.call_function(MENU_RETURN);
	}
	else if (currentKey == 'L') {
		menu::menu.switch_focus(false);
	}
	else if (currentKey == 'R') {
		menu::menu.switch_focus(true);
	}
	else if (currentKey == 'U') {
		menu::menu.call_function(MENU_INCR);
	}
	else if (currentKey == 'D') {
		menu::menu.call_function(MENU_DECR);
	}
		
}

void loop() {
	static byte lastFreq, lastDuty;
	
	currentKey = matrix::matrix.getKey();
	if (currentKey) {
		keyHandler();
		debug("Key was handled");
	}
	else debug("No key was found");
	
	debug("Tick");
}

void timer_handle_interrupts(int timer) {
	menu::menu.update();
	if (lastFreq != freq 
	or lastDuty != duty) {
		menu::menu.update();
		
		lastFreq = freq;
		lastDuty = duty;
		
		debug("Menu was updated");
	}
	else debug("There was no change");
}