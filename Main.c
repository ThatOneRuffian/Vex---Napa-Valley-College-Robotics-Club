#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    armPot,         sensorNone)
#pragma config(Sensor, in2,    l1,             sensorLineFollower)
#pragma config(Sensor, in3,    l2,             sensorLineFollower)
#pragma config(Sensor, in4,    l3,             sensorLineFollower)
#pragma config(Sensor, dgtl1,  claw1,          sensorDigitalOut)
#pragma config(Sensor, dgtl2,  claw2,          sensorDigitalOut)
#pragma config(Sensor, dgtl3,  armLocker,      sensorDigitalOut)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  leftEncoder,    sensorQuadEncoder)
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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/***************^^^^^^^^^^^^^^ PIN DECLARATIONS AND THEIR FUNCTIONS ^^^^^^^^^^^^^^*********************/

#include "myInclude.h" //contains all project includes.

task main()
{
	intScreen(); //setup screen

	//int myValue;

	while(true)
	{
		lcdHandler();
		controllerHandeler();
	}
}



			/*myValue = LEFTPOS;
		  if(myValue > 2) //Forward Controls
		{
			int speedRight = (THROTTLE - TURN);
			int speedLeft = (THROTTLE + TURN);

			setMotor(MotorLeft1, speedLeft);
			setMotor(MotorLeft2, speedLeft);
			setMotor(MotorRight1, speedRight);
			setMotor(MotorRight2, speedRight);
		}*/
