//File to include libraries and other header file into project
#include "config.h" //config file for the project

#include <TimerOne.h>

void libInit() {
    #ifdef DEBUG
        Serial.begin(9600);
    #endif
    
    //TimerOne initialization
    Timer1.initialize();
    pinMode(VALVE_PIN, OUTPUT);
}

#ifdef DEBUG
#define debug(n) Serial.println("***"+String(n)+"***")

#else
#define debug(n) NULL;
#endif

class Stick() {
	public:
		Stick(byte &_pin, byte &_minVal, byte &_maxVal) {
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