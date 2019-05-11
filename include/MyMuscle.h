//A file to include other header files into project and declare classes

#include "config.h" //a config file for the project

#include "libraries.h" //a file that includes  and declares some libraries



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