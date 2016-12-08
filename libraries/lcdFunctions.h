#ifndef	_LCD
#define _LCD

#include "autoFunctions.h"
#include "modeLogic.h"

void mainMenu(void);
void lcdHandler(void);

bool backLight = true;  //default backlight setting
bool isPressed = false;
bool rightAlt = false; //disable right input button
bool AUTORUN = true;

int menuChoice[2] = {0, 0};
int userInputs	= 0;
const int menuMax[2] = {4,3};

string myMenu[4][3] =
	{{ "Mode",       "View Status",         "Settings"},
	{"Auto-SlamJam",            "Battery1",         "LCD Light"},
	{"Manual",         "Battery2",        "Controller Alt"},
	{"High Hang", 			    "empty", 				"Reset Sensors"}};

void intScreen(){

	clearLCDLine(0);              // Clear line 1 (0) of the LCD
  clearLCDLine(1);              // Clear line 2 (1) of the LCD
	bLCDBacklight = backLight;
  }

void updateInput(){

	userInputs = 0;

	if( nLCDButtons != 0 && !isPressed){// Logic for input. Toggles pressed flag to stop screen looping.

		userInputs = nLCDButtons;
		isPressed = true;
		}

	else if (nLCDButtons == 0 && isPressed){

		isPressed = false;
		}
}


void updateScreen(){

	displayLCDCenteredString(0, myMenu[menuChoice[0]][menuChoice[1]]); //write menu options to screen
	//displayLCDNumber(0,0, nLCDButtons); //debug line

displayLCDCenteredString (1,"Back Select --->");
}

void determineAction(){

/*	{{ "Mode",       "View Status",         "Settings"},
	{"Auto",            "Battery1",         "LCD Light"},
	{"Manual",         "Battery2",        "Controller Alt"},
	{"Hang", 			    "empty", 							"empty"}};
*/

	if(menuChoice[0] == 1 && menuChoice[1] == 0){ // Auto selected
		clearTimer(T1);
		Mode = 1;
		mainMenu();
		AUTORUN = true;
	}
	if(menuChoice[0] == 2 && menuChoice[1] == 0){	//Manual mode selected
		clearTimer(T1);
		Mode = 0;
		mainMenu();
		AUTORUN = true;
	}

	if(menuChoice[0] == 3 && menuChoice[1] == 0){	//High hang mode selected
		clearTimer(T1);
		Mode = 2;
		mainMenu();
		AUTORUN = true;
	}

	if(menuChoice[0] == 1 && menuChoice[1] == 2){   //LCD light selected

		if(	bLCDBacklight ){

		bLCDBacklight = false;
		mainMenu();

		}

		else{

			bLCDBacklight = true;
			mainMenu();

			}
		}




}

void menuHandler(){


			if(menuChoice[0] != 0){ // if in the main menu.

				rightAlt = true;
			}
			else{
				rightAlt = false;
			}

		switch(userInputs){  //monitor user input

		case 1:

				mainMenu();
				break;

		case 2:


			if(menuChoice[0] == 0){

				menuChoice[0] ++;
				}
			else{
				determineAction();
			}

			break;

		case 4:

			if(!rightAlt){
			menuChoice[1] += 1;
			menuChoice[1] %= menuMax[1];
			}

			else{
				if(menuChoice[0] + 1 > menuMax[0]-1)
				{
					menuChoice[0] = 1;
				}
				else{
				menuChoice[0] ++;
				}
			}
			break;

		default:
			break;
		}

}

void mainMenu(){ // directs interfect to main menu.
	menuChoice[0] = 0;
	menuChoice[1] = 0;
	updateScreen();
}

void lcdHandler(){

	updateInput();
	menuHandler();
	updateScreen();
}


/*  clearLCDLine(0);                      // Clear line 1 (0) of the LCD
  clearLCDLine(1);                      // Clear line 2 (1) of the LCD

  bLCDBacklight = true;                 // Turn on LCD Backlight

  displayLCDPos(0,0);                   // Set the cursor to line 0, position 0 (top line, far left)

  displayNextLCDString("Hello from");   // Display "Hello from"

  displayLCDPos(1,0);                   // Set the cursor to line 1, position 0 (bottom line, far left)

  displayNextLCDString("ROBOTC  :]");   // Display "ROBOTC :]"
*/

#endif
