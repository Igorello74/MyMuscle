//------------KEYPAD------------
#define KEYPAD_ROWS 5 //number of rows in the keypad
#define KEYPAD_COLS 4 //columns

const char KEYPAD_KEYS [KEYPAD_ROWS][KEYPAD_COLS] = { //set of keys in the keypad
  {'(',')','#', '*'},
  {'1','2','3', 'U'},
  {'4','5','6', 'D'},
  {'7','8','9', '-'},
  {'L','0','R', '+'}
};

const byte KEYPAD_ROWS_PINS[KEYPAD_ROWS] = {12, 11, 10, 9, 8}; //connect to the row pinouts of the keypad
const byte KEYPAD_COLS_PINS[KEYPAD_COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad
//------------KEYPAD------------