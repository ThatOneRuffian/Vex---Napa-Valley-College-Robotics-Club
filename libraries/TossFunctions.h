#ifndef	_Toss
#define _Toss
#include "macroDefines.h"

bool tossBusy = false;

void activateArm(int inverter);

void resetArm(){

	const int maxSpeed = 35;
	const int sampleSpeed = 10;
	const int motorPluseTime = 20;

	int armVelocity;
	int armValues[2];

	while( ARMVALUE > RESTING){

		armValues[0] = ARMVALUE;
		delay(sampleSpeed);
		armValues[1] = ARMVALUE;

		armVelocity = armValues[0] - armValues[1];

		if(armVelocity >= maxSpeed){
			activateArm(1);
			delay(motorPluseTime);
			activateArm(-1);
		}

		else if (armVelocity == 0){
			activateArm(0);
			delay(motorPluseTime);
			activateArm(-1);
		}

	}
}

void openClaws(){
			SensorValue[claw1] = 1;  //Activate both solenoids at the same time.
			SensorValue[claw2] = 1;
}

void closeClaws(){
			SensorValue[claw1] = 0;  //Activate both solenoids at the same time.
			SensorValue[claw2] = 0;
}

void activateArm(int inverter){

		int MUL;

		if(inverter == true){
			MUL = 1;
			}

		else if(inverter == false){
			MUL = -1;
			}

		else{
		MUL = 0;
		}

		int motorSpeed = 100*MUL;

		setMotor(LauncherL1, motorSpeed);
		setMotor(LauncherL2, motorSpeed);
		setMotor(LauncherL3, motorSpeed);
		setMotor(LauncherR4, motorSpeed);
		setMotor(LauncherR5, motorSpeed);
		setMotor(LauncherR6, motorSpeed);
}

void tossObject(float releaseAngle){

		releaseAngle /= 0.045; // convert angle to sensor value

    const int delayTime = 150;
    const int timesTillQuit = 3; //How many times this thing can be bad at it's job.

    bool loopFlag = true;

    int armCount = 0;       //read how many times arm has not been doing its job
    int armPos[2] = {0,0};  //stores arms to find difference

    while(loopFlag)
    {
        armPos[0] = ARMVALUE; //read initial value

        activateArm(1);       //activate arm

        delay(delayTime);     //wait for next sample

        armPos[1] = ARMVALUE;  // read next sample into array

        if(armPos[0] == armPos[1] || armPos[0] <= armPos[1]){ // see if arm positions are equal or decreasing. Not good.
            armCount++;
        }

        if(armCount >= timesTillQuit || ARMVALUE >= releaseAngle){
            loopFlag = false; //Break the loop.
        }
    }

    if(ARMVALUE >= releaseAngle)
    {
        openClaws();      //release object
        activateArm(-1);  //disable arm motors
        resetArm();       //Go to resting position
    }
    else{
        resetArm();
    }
}
#endif
