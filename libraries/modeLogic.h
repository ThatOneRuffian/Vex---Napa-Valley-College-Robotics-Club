#ifndef	_MODE
#define _MODE

#include "lcdFunctions.h"

const int gameTime = 4800;//48s


void highHangMode(){

	if(AUTORUN){

		clearTimer(T4);
		while( time10[T4] < gameTime){
		lcdHandler();
		AUTORUN = false;
		}
	}
}

void autoMode(){//slam jam!

  if(AUTORUN){

	  clearTimer(T4);

		while( time10[T4] < gameTime){

			int delayTime = 1000;
			int distance = 500;

			openClaws();

			delay(delayTime);

			//pickup objects
			goDist(distance);
			closeClaws();

			//move to clear wall
			turnToGivenAngle(-90);
			goDist(distance/2);

			//turn around and dunk
			turnToGivenAngle(90);
			goDist(distance*-3);
			activateArm(1);
			delay(2000);

			lcdHandler();
			AUTORUN = false;
		}
	}
}

void manualMode(){

		lcdHandler();
		controllerHandeler();
	}

#endif
