#ifndef	_controlFun
#define _controlFun

void tossObject(){ //control for launcher. Currently no feedback, so time limit implimented to stop motors from breaking.

	if(TOSS){

		setMotor(Launcher1, 100);
		setMotor(Launcher2, 100);
		setMotor(Launcher3, 100);
		setMotor(Launcher4, 100);
		setMotor(Launcher5, 100);
		setMotor(Launcher6, 100);

		delay(100);

		setMotor(Launcher1, 0);
		setMotor(Launcher2, 0);
		setMotor(Launcher3, 0);
		setMotor(Launcher4, 0);
		setMotor(Launcher5, 0);
		setMotor(Launcher6, 0);
	}

	else if(ANTITOSS)
	{
		setMotor(Launcher1, -100);
		setMotor(Launcher2, -100);
		setMotor(Launcher3, -100);
		setMotor(Launcher4, -100);
		setMotor(Launcher5, -100);
		setMotor(Launcher6, -100);

		delay(100);

		setMotor(Launcher1, 0);
		setMotor(Launcher2, 0);
		setMotor(Launcher3, 0);
		setMotor(Launcher4, 0);
		setMotor(Launcher5, 0);
		setMotor(Launcher6, 0);
	}

}
void openClaws(){

	if(CLAWCLOSE)
	{
		SensorValue[claw1] = 1;  //Activate both solenoids at the same time.
		SensorValue[claw2] = 1;
	}
}

void closeClaws(){
	if(CLAWOPEN)
	{
		SensorValue[claw1] = 0;  //Activate both solenoids at the same time.
		SensorValue[claw2] = 0;
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
	openClaws();
	closeClaws();
	drive();
	tossObject();
}

#endif
