#ifndef	_LCD
#define _LCD


#define lineWidth 16

bool backLight = true;
bool isPressed = false;
bool rightAlt = false; //disable right input button

int menuChoice[2] = {0, 0};
int userInputs	= 0;
const int menuMax[2] = {4,3};

string myMenu[4][3] =
	{{ "Mode",       "View Status",         "Settings"},
	{"Auto",            "Battery1",         "LCD Light"},
	{"Manual",         "Battery2",        "Controller Alt"},
	{"empty", 			    "empty", 							"empty"}};

void intScreen(){

	clearLCDLine(0);              // Clear line 1 (0) of the LCD
  clearLCDLine(1);              // Clear line 2 (1) of the LCD
	bLCDBacklight = backLight;
  }

void updateInput(){

	userInputs = 0;
	const int maxCount = 2;
	int counter = 0;

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

	if(menuChoice[0] == 1 && menuChoice[1] == 0){

			menuChoice[0] = 0;
				menuChoice[1] = 0;

	}

	}
void menuHandler(){

	/*menuChoice[][] //position in menu array
	userInputs[3]
	int menuChoice[2] = {0, 0};*/

			if(menuChoice[0] != 0){

				rightAlt = true;
			}
			else{
				rightAlt = false;
			}

		switch(userInputs){

		case 1:
				if(menuChoice[0] > 0)
			{
				menuChoice[0] = 0;
				menuChoice[1] = 0;
			}

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
