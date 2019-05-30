//A file to include other header files into project and declare classes

#ifdef MY_DEBUG
#define debug(n) Serial.println("***"+String(n)+"***")
#else
#define debug(n) NULL;
#endif

#include "config.h" //a config file for the project

#include "libraries.h" //a file that includes  and declares some libraries

#include "valve.h"
#include "menu.h"
#include "matrix.h"

void libInit() {
	#ifdef MY_DEBUG
	Serial.begin(9600);
	#endif
	
	//---VALVE---
	Timer1.initialize(); //TimerOne initialization
	pinMode(VALVE_PIN, OUTPUT);

	//---DISPLAY---
	lcd.init();
	lcd.backlight();
	
	//---MENU---
	menu::init();
}

void timerStart() {
	timer_init_ISR_2Hz(_TIMER2);
}

