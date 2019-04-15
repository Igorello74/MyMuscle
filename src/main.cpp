#define DEBUG //debug on/off, comment to disable

#include <Arduino.h>
#include "MyMuscle.h"

Stick stick[2]={
	Stick(STICK1_PIN,STICK1_MINVAL,STICK1_MAXVAL),
	Stick(STICK2_PIN,STICK2_MINVAL,STICK2_MAXVAL)
};

void setup() {
	libInit(); //libraries initialization
	lcdWelcome(); //a welcome message on the lcd display
	Timer1.pwm(VALVE_PIN, VALVE_DEFAULT_DUTY, VALVE_DEFAULT_PERIOD); //start generating PWM
	
}

void loop() {
	static byte lastFreq = 0;
	static uint16_t lastDuty = 0;
	
	byte currentFreq = stick[0].getVal();
	uint16_t currentDuty = stick[1].getValRaw();
	
	if (currentFreq != lastFreq or currentDuty != lastDuty) {
		debug("New values: freq=" + String(currentFreq) +
			", duty=" + String(currentDuty));
		
		lcd.clear();
		lcd.print(F("F              %")); //the top line of the message
		lcd.setCursor(0, 1);
		lcd.print(currentFreq);
		lcd.setCursor(LCD_COLS-4, 1);	//setting a cursor to a needed position
		lcd.print(map(currentDuty, 0, 1024, 0, 100)); //converting Duty to percentage format and printing that

		Timer1.pwm(VALVE_PIN, currentDuty, 1000000/currentFreq); //setting new PWM parameters
		
		lastFreq = currentFreq; //remembering the last condition of variables
		lastDuty = currentDuty;
	}
	debug("Tick");
}