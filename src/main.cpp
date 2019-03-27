#define DEBUG //debug on/off, comment to disable

#include <Arduino.h>
#include "MyMuscle.h"


void setup() {
  // put your setup code here, to run once:
	libInit();
	keypad.addEventListener(NULL);

}

void loop() {
    // put your main code here, to run repeatedly:

}

void keyHandler(KeypadEvent key) {
	switch (keypad.getState())	{
		case PRESSED:
			if (key >= 48 and key <= 57) { // range 48-57 is digits in ASCII table
				debug("I saw a number!");
			}
			break;
	
		default:
			NULL;
			break;
	}
}