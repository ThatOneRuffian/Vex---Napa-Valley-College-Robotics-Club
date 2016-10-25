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

		int invert;

		if(inverter == true){
			invert = 1;
			}

		else if(inverter == false){
			invert = -1;
			}

		else{
		invert = 0;
		}

		int motorSpeed = 100*invert;

		setMotor(LauncherL1, motorSpeed);
		setMotor(LauncherL2, motorSpeed);
		setMotor(LauncherL3, motorSpeed);
		setMotor(LauncherR4, motorSpeed);
		setMotor(LauncherR5, motorSpeed);
		setMotor(LauncherR6, motorSpeed);
}

void highToss(){
		while(ARMVALUE <= ARMHIGHTHROW)
		{
			activateArm(1);
		}
			if(ARMVALUE >= ARMHIGHTHROW)
			{
				openClaws();
				activateArm(-1);
				resetArm();
			}

}

void farToss(){
			while(ARMVALUE <= ARMFARTHROW)
		{
			activateArm(1);
		}

		if(ARMVALUE >= ARMFARTHROW)
			{
				openClaws();
				activateArm(-1);
				resetArm();
			}
}
#endif
