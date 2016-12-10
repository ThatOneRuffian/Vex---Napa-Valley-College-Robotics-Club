#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in1,    armPot,         sensorPotentiometer)
#pragma config(Sensor, in2,    l1,             sensorLineFollower)
#pragma config(Sensor, in3,    l2,             sensorLineFollower)
#pragma config(Sensor, in4,    l3,             sensorLineFollower)
#pragma config(Sensor, dgtl1,  claw1,          sensorDigitalOut)
#pragma config(Sensor, dgtl2,  claw2,          sensorDigitalOut)
#pragma config(Sensor, dgtl3,  ultraSonic,     sensorSONAR_mm)
#pragma config(Sensor, dgtl8,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl10, armLocker,      sensorDigitalOut)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)
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
#include "controllerFunctions.h"
#include "autoFunctions.h"
#include "macroDefines.h"
#include "modeLogic.h"

task main()
{

intScreen(); //setup screen
	setupSensors(); // zero out sensors
	turn90CCW();
 //			autoMode();
/*
	while(true){

		while(Mode == 0){ // manual mode

			manualMode();
		}

		while(Mode == 1){ //Automatic mode

			autoMode();
		}
		while(Mode == 2){ // high hang mode

			highHangMode();
		}
	}*/
}
