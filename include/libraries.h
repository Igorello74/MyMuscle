//A file to include and declare libraries

#include <TimerOne.h>

#include "timer-api.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(LCD_ADDRESS,LCD_COLS,LCD_ROWS);

#include <LiquidMenu.h>

#include <Keypad.h>

// #include <IRremote.h>
// IRrecv 