#pragma config(Sensor, dgtl1,  claw1,          sensorDigitalOut)
#pragma config(Sensor, dgtl2,  claw2,          sensorDigitalOut)
#pragma config(Sensor, dgtl3,  armLocker,      sensorDigitalOut)
#pragma config(Sensor, dgtl4,  ultraSonic,     sensorSONAR_cm)         //Input is connected to this pin and the Output is connected to digital pin+1.
#pragma config(Motor,  port1,           MotorLeft1,    tmotorNone, openLoop)
#pragma config(Motor,  port2,           MotorLeft2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           MotorRight1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           MotorRight2,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Launcher1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Launcher2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Launcher3,     tmotorNone, openLoop)
#pragma config(Motor,  port8,           Launcher4,     tmotorNone, openLoop)
#pragma config(Motor,  port9,           Launcher5,     tmotorNone, openLoop)
#pragma config(Motor,  port10,          Launcher6,     tmotorNone, openLoop)
/***************^^^^^^^^^^^^^^ PIN DECLARATIONS AND THEIR FUNCTIONS ^^^^^^^^^^^^^^*********************/

#include "macroDefines.h"
#include "controllerFunctions.h"

task main()
{
	while(1)
	{
		controllerHandeler();
	}
}
