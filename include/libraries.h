//File to include libraries and other header file into project
#include "config.h" //config file for the project

#include <Keypad.h>

void libInit() {
    Keypad keypad = Keypad( makeKeymap(KEY_KEYS), KEY_ROWS_PINS, KEY_COLS_PINS, KEY_ROWS, KEY_COLS);
}