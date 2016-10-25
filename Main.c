#pragma config(Sensor, in3,    armPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  claw1,          sensorDigitalOut)
#pragma config(Sensor, dgtl2,  claw2,          sensorDigitalOut)
#pragma config(Sensor, dgtl3,  armLocker,      sensorDigitalOut)
#pragma config(Sensor, dgtl4,  ultraSonic,     sensorSONAR_mm)
#pragma config(Motor,  port1,           LauncherL1,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           MotorLeft1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           MotorLeft2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           MotorRight1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           MotorRight2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LauncherL2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LauncherL3,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LauncherR4,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LauncherR5,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          LauncherR6,    tmotorVex393_HBridge, openLoop)
/***************^^^^^^^^^^^^^^ PIN DECLARATIONS AND THEIR FUNCTIONS ^^^^^^^^^^^^^^*********************/

#include "myInclude.h" //contains all project includes.

task main()
{
	//intScreen();

	while(true)
	{
		controllerHandeler();
	}
}
