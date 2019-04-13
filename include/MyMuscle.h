//File to include libraries and other header file into project
#include "config.h" //config file for the project

#include <TimerOne.h>

void libInit() {
    #ifdef DEBUG
        Serial.begin(9600);
    #endif

    ;
    
}

#ifdef DEBUG
#define debug(n) Serial.println("***"+String(n)+"***")

#else
#define debug(n) NULL;
#endif