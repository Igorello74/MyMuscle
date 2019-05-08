//---STICKS SETTINGS---
//STICK 1 - frequency setting (currently period setting)
#define STICK1_PIN      A0  //the pin which the stick is connected to
#define STICK1_MINVAL   1   //the maximal value that might be on the stick
#define STICK1_MAXVAL   30  //the minimal value that might be on the stick

//STICK 2 - duty setting
#define STICK2_PIN      A1  //same as in the stick 1 ^^^
#define STICK2_MINVAL   0   //non-used
#define STICK2_MAXVAL   0   //non-used


//---VALVE SETTINGS---
#define VALVE_PIN               9 //the pin which the valve is connected to
#define VALVE_DEFAULT_PERIOD    100000 /* the default period
off the timer (valve) in ?s (microseconds)*/
#define VALVE_DEFAULT_DUTY      512 /* the default duty off the timer (valve)
in fractions of 1024 (0 - 0%, 512 - 50%, 1024 - 100%) */

//---DISPLAY SETTINGS---
#define LCD_ADDRESS 0x27    //I²C address of the display
#define LCD_COLS    16      //number of columns on the display (characters)
#define LCD_ROWS    2       //number of rows on the display (lines)
#define LCD_DELAY   200     //delay between frame update