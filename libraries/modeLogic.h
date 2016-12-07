#ifndef	_MODE
#define _MODE

void highHangMode(){

	lcdHandler();
	}

void autoMode(){//slam jam!
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
	}

void manualMode(){

		lcdHandler();
		controllerHandeler();
	}

#endif
