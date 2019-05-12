//A file to include other header files into project and declare classes

#include "config.h" //a config file for the project

#include "libraries.h" //a file that includes  and declares some libraries

#include "menu.h" // a file with definitions of some objects from LiquidMenu

void libInit() {
	#ifdef MY_DEBUG
		Serial.begin(9600);
	#endif
	
	//---VALVE---
	Timer1.initialize(); //TimerOne initialization (included object)
	pinMode(VALVE_PIN, OUTPUT);

	//---DISPLAY---
	lcd.init();
	lcd.backlight();

}

#ifdef MY_DEBUG
#define debug(n) Serial.println("***"+String(n)+"***")

#else
#define debug(n) NULL;
#endif

/*
void lcdWelcome() {
	debug("LCD greeting started");
	lcd.home();
	lcd.print(F("   Welcome to   "));
	lcd.setCursor(0, 1);
	lcd.print(F("MyMuscle system!"));
	delay(5000);
	lcd.clear();
	debug("LCD greeting finished");
}*/