//File to include libraries and other header file into project
#include "config.h" //config file for the project

#include <Keypad.h>
#include <TimerOne.h>

void libInit() {
    #ifdef DEBUG
        Serial.begin(9600);
    #endif
    
    Keypad key = Keypad( makeKeymap(KEY_KEYS), KEY_ROWS_PINS, KEY_COLS_PINS, KEY_ROWS, KEY_COLS);
    
}

#ifdef DEBUG
#define debug(n) Serial.println("***"+String(n)+"***")

#else
#define debug(n) NULL;
#endif