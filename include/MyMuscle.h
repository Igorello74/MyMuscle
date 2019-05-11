//File to include libraries and other header file into project
#include "config.h" //config file for the project

#include <TimerOne.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(LCD_ADDRESS,LCD_COLS,LCD_ROWS);

void libInit() {
    #ifdef DEBUG
        Serial.begin(9600);
    #endif
    
	//---VALVE---
    Timer1.initialize(); //TimerOne initialization (included object)
    pinMode(VALVE_PIN, OUTPUT);

	//---DISPLAY---
	lcd.init();
	lcd.backlight();

}

#ifdef DEBUG
#define debug(n) Serial.println("***"+String(n)+"***")

#else
#define debug(n) NULL;
#endif

#ifndef DEMO
class Stick {
	public:
		Stick(byte _pin, byte _minVal, byte _maxVal) {
			pin = _pin;
			minVal = _minVal;
			maxVal = _maxVal;
			
			pinMode(pin, INPUT);
		}
		byte getVal() {return map(getValRaw(), 0, 1024, minVal, maxVal);}
		uint16_t getValRaw() {return analogRead(pin);}
	private:
		byte pin, minVal, maxVal;
};
#endif

void lcdWelcome() {
	debug("LCD greeting started");
	lcd.home();
	lcd.print(F("   Welcome to   "));
	lcd.setCursor(0, 1);
	lcd.print(F("MyMuscle system!"));
	delay(5000);
	lcd.clear();
	debug("LCD greeting finished");
}