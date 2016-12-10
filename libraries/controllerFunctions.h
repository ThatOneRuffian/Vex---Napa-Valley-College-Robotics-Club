#ifndef	_controlFun
#define _controlFun

#include "TossFunctions.h"
#include "autoFunctions.h"

void tossHandler(){ //control for launcher. Currently no feedback, so time limit implimented to stop motors from breaking.

	if(HIGHTOSS){

				int motorSpeed = 200;

		setMotor(LauncherL1, motorSpeed);
		setMotor(LauncherL2, motorSpeed);
		setMotor(LauncherL3, motorSpeed);
		setMotor(LauncherR4, motorSpeed);
		setMotor(LauncherR5, motorSpeed);
		setMotor(LauncherR6, motorSpeed);
	}

  if(FARTOSS)
	{
		activateArm(0);
	}

	if(!FARTOSS && !HIGHTOSS)
	{
	 	activateArm(-1);
	}

	if(LOCK){
		lockArm();
	}

	if(UNLOCK){
			unlockArm();
	}
}
void clawHandler(){


	if(CLAWCLOSE)
	{
	closeClaws();
	}

	if(CLAWOPEN)
	{
		openClaws();
	}
}

void drive(){  //Handles Joystick -> movement\translation

	const int deadZoneBuffer = 27; //remove edge of analog joystick to make less sensitive. Also, makes signed bit max value 100 instead of 127.
	const int invert = -1;
	const int completeStop = 0;

	if(THROTTLE > deadZoneBuffer) //Forward Controls
	{
		int speedRight = (THROTTLE - TURN);
		int speedLeft = (THROTTLE + TURN);

		setMotor(MotorLeft1, speedLeft);
		setMotor(MotorLeft2, speedLeft);
		setMotor(MotorRight1, speedRight);
		setMotor(MotorRight2, speedRight);
	}

	else if(THROTTLE < deadZoneBuffer * invert) //Backward Controls
	{
		int speedRight = (THROTTLE  - TURN);
		int speedLeft = (THROTTLE  + TURN);

		setMotor(MotorLeft1, speedLeft );
		setMotor(MotorLeft2, speedLeft );
		setMotor(MotorRight1, speedRight);
		setMotor(MotorRight2, speedRight);
	}

	else if(TURN > deadZoneBuffer || TURN < deadZoneBuffer*invert ) //Point Turn.
	{
		setMotor(MotorLeft1, TURN);
		setMotor(MotorLeft2, TURN );
		setMotor(MotorRight1, TURN*invert);
		setMotor(MotorRight2, TURN*invert);
	}

	else	if (THROTTLE <= deadZoneBuffer && THROTTLE >= deadZoneBuffer * invert) //No acceleration controls.
	{
		setMotor(MotorLeft1, completeStop);
		setMotor(MotorLeft2, completeStop );
		setMotor(MotorRight1, completeStop);
		setMotor(MotorRight2, completeStop);
	}

}

void controllerHandeler(){
	clawHandler();
	drive();
	tossHandler();
}

#endif
