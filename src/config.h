//---GENERAL SETTINGS---
#define CYCLE_DELAY 200 //delay between every cycle (I mean, every tick)

//---VALVE SETTINGS---
#define VALVE_PIN               9 //the pin which the valve is connected to
#define VALVE_DEFAULT_FREQ 10 /* the default period
off the timer (valve) in μs (microseconds)*/
#define VALVE_DEFAULT_DUTY 512 /* the default duty off the timer (valve)
in fractions of 1024 (0 - 0%, 512 - 50%, 1024 - 100%) */

//---DISPLAY SETTINGS---
#define LCD_ADDRESS 0x27    //I²C address of the display
#define LCD_COLS    16      //number of columns on the display (characters)
#define LCD_ROWS    2       //number of rows on the display (lines)

//---KEYPAD SETTINGS---
#define KEYPAD_ROWS 5 //number of rows in the keypad
#define KEYPAD_COLS 4 //columns

const byte KEYPAD_ROWS_PINS[KEYPAD_ROWS] = {
	12, 11, 10, 9, 8
}; //connect to the row pinouts of the keypad

const byte KEYPAD_COLS_PINS[KEYPAD_COLS] = {
		4, 5, 6, 7
}; //connect to the column pinouts of the keypad