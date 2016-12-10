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
	lcdHandler();
  lockStatus = true;
  lockHandeler();
  delay(1000);

	if(AUTORUN){

		clearTimer(T4);

			while( time10[T4] < gameTime){

				const int delayTime = 250;
				const float distance0 = 250;
				const float distance1 = 750;
				const float distance2 = 1000;

				openClaws();

				delay(delayTime);

				//pickup objects

				goDist(distance1);

				closeClaws();

				turn45CW();

				goDist(distance1);

				delay(20000);

				AUTORUN = false;
		}
	}
}
/* push stuff under the fence
		while( time10[T4] < gameTime){

			int delayTime = 250;
			float distance = 750;

			openClaws();

			delay(delayTime);

			//pickup objects

			goDist(distance);

			closeClaws();

			turn45CCW();

			goDist(distance);

			delay(20000);

			AUTORUN = false;
		}

	}
}*/

void manualMode(){

	lcdHandler();
	controllerHandeler();
}

#endif
