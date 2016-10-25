#ifndef	_LCD
#define _LCD

string myMenu[3] = { "Mode", "View Status", "Settings"};

void intScreen(){
  clearLCDLine(0);                    // Clear line 1 (0) of the LCD
  clearLCDLine(1);                    // Clear line 2 (1) of the LCD
}

void displayString(){}


#endif
