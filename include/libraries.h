//File to include libraries and other header file into project
#include "config.h" //config file for the project

#include <Keypad.h>
#include <TimerOne.h>

void libInit() {
    #ifdef DEBUG
        Serial.begin(9600);
    #endif

    Keypad keypad = Keypad( makeKeymap(KEYPAD_KEYS), KEYPAD_ROWS_PINS, KEYPAD_COLS_PINS, KEYPAD_ROWS, KEYPAD_COLS);
    
}

#ifdef DEBUG
#define debug(n) Serial.println("***"+String(n)+"***")

#else
#define debug(n) NULL;
#endif