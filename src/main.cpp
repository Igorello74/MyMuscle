#define DEBUG	//debug on/off, comment to disable debug
#define DEMO	//means that it doesn't care of potentiometers and uses a generator (increases frequency and then resets)

#include <Arduino.h>
#include "MyMuscle.h"

#ifndef DEMO
Stick stick[2]={
	Stick(STICK1_PIN,STICK1_MINVAL,STICK1_MAXVAL),
	Stick(STICK2_PIN,STICK2_MINVAL,STICK2_MAXVAL)
};
#endif

void setup() {
	libInit(); //libraries initialization
	lcdWelcome(); //a welcome message on the lcd display
	Timer1.pwm(VALVE_PIN, VALVE_DEFAULT_DUTY, VALVE_DEFAULT_PERIOD); //start generating PWM
	
}

void loop() {
	static byte lastFreq = 0;
	static uint16_t lastDuty = 0;
	
	#ifndef DEMO
	byte currentFreq = stick[0].getVal();
	uint16_t currentDuty = stick[1].getValRaw();
	#else
	byte currentFreq = lastFreq + 1;
	uint16_t currentDuty = lastDuty;
	#endif
	
	if (currentFreq != lastFreq or currentDuty != lastDuty) {
		debug("New values: freq=" + String(currentFreq) +
			", duty=" + String(currentDuty));
		
		lcd.clear();
		lcd.print(F("frequency   duty")); //the top line of the message
		lcd.setCursor(0, 1);
		lcd.print(String(currentFreq)+" Hz");
		lcd.setCursor(LCD_COLS-4, 1);	//setting a cursor to a needed position
		lcd.print(String(map(currentDuty, 0, 1024, 0, 100))+'%'); //converting Duty to percentage format and printing that

		Timer1.pwm(VALVE_PIN, currentDuty, 1000000/currentFreq); //setting new PWM parameters
		
		lastFreq = currentFreq; //remembering the last condition of variables
		lastDuty = currentDuty;
	}
	delay(CYCLE_DELAY);
	debug("Tick");
}