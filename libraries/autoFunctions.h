#ifndef	_AUTOFUN
#define _AUTOFUN

#include "sensors.h"
#include "TossFunctions.h"

void driveForward(void);
void updateMotorVals(void);
void clearMotors(void);
void lockHandeler(void);
void closeDistance(int dist);
void scoopObject(void);
void armHoldHandler();
void scanArea(void);
void parseData(void);
void updateSensors(void);
void lineHandler(void);
void goLeft(void);
void turn45CW(void);


float getArclength(unsigned int radiusAvg, int angle1, int angle2);

//=======================================================================

const int autoSampleRate = 200;
const int autoSpeed = 25;  //auto mode speed

const float armLength = 431; //mm
const float wheelCir = 0.0; // circumference of the wheel
const float gameObject[5] = { 0.0, 0.0, 0.0, 0.0, 0.0,}; // Pipe, Gate feet, cube, jack, field(?)
const float disPerRotation = 329.7415649; //mm
const float mmPerRotation = 1.0917640914004165933404290700629; // degree per mm
const float sweetSpot = 254; // distance in mm for grabbing sweet spot

const int autoStepLength  = 500; // move vect step length

const int maxClawCycles = 24; // max number of times the claw can be activated

const int depthTrigger = 127; // how deep something must be to trigger an edge detection on the sonar sensor

int parsedScanData[3][360]; //contains (theta1, theta2, radius, estimated object type)
int rawSonarScan[360]; //contains full data from 360* scan

int motorArray[2][2] = {{0, 0}, {0, false}}; // motorlogic {left | right}

bool lockStatus = false; //default unlocked
bool leftPad = false;
int Mode = 0;  //indicate manual | auto | high hang

int threshold = 500; // Amount sensor has to change for the module to register

int myAngle = 0; //angle offset from start

float holdAngle = 45;
//============================================================


bool lineDetected(){

const int myBuffer = 200;
		updateSensors();

		if( lineArray[1] > lineThreshold[1] - 200 && leftPad){

			return true;
		}

		else{

			return false;
		}
}

void go2Line(){//go forward until line is detected

	while(!lineDetected())
	{

	driveForward();  //need break statement
	}

	clearMotors();
	updateSensors();
}

void turn45CW(){

		const int myTurnTime = 1500;

	goLeft();
	delay(myTurnTime);
	clearMotors();
	updateMotorVals();
}

void turn45CCW(){

		const int myTurnTime = 1500;

	goLeft();
	delay(myTurnTime);
	clearMotors();
	updateMotorVals();
}

void lockHandeler(){

if(lockStatus){
		lockArm();
	}
	else{
		unlockArm();
	}
}

void goDist(float myDist){

	const int wheelStuckMax = 3;
	float degreeTotal = abs(myDist * mmPerRotation); // total degrees needed to make request

  SensorValue[leftEncoder] =0;
  SensorValue[rightEncoder] =0;

	encoderArray[0] = SensorValue[leftEncoder];
	encoderArray[1] = SensorValue[rightEncoder];

	int myProjectedClick[2] = { encoderArray[0] + degreeTotal, encoderArray[1] + degreeTotal}; //projected click count to achieve distance

	int wheelPosCheck[3][2]; //{first, last, difference}

	int wheelStuckCount = 0;

 	while( encoderArray[0] < myProjectedClick[0] ||  encoderArray[1] < myProjectedClick[1]){

	  encoderArray[0] = SensorValue[leftEncoder];
		encoderArray[1] = SensorValue[rightEncoder];

		wheelPosCheck[0][0] = encoderArray[0];
		wheelPosCheck[0][1] = encoderArray[1];
		driveForward();

		delay(autoSampleRate);

		encoderArray[0] = SensorValue[leftEncoder];
		encoderArray[1] = SensorValue[rightEncoder];

		wheelPosCheck[1][0] = encoderArray[0];
		wheelPosCheck[1][1] = encoderArray[1];

		wheelPosCheck[2][0] = wheelPosCheck[0][0] - wheelPosCheck[1][0];
		wheelPosCheck[2][1] = wheelPosCheck[0][1] - wheelPosCheck[1][1];

		if(wheelPosCheck[2][0] == 0 || 	wheelPosCheck[2][1] == 0){

			wheelStuckCount++;
			}

		if(wheelStuckCount > wheelStuckMax){
				break; //break out of loop because wheel is stuck.
			}
	}
	clearMotors();
	encoderArray[0] = SensorValue[leftEncoder];
	encoderArray[1] = SensorValue[rightEncoder];
}

void updateMotorVals(){

		setMotor(MotorLeft1, autoSpeed*motorArray[0][0] );
		setMotor(MotorLeft2, autoSpeed*motorArray[0][1] );
		setMotor(MotorRight1, autoSpeed*motorArray[1][0] );
		setMotor(MotorRight2, autoSpeed*motorArray[1][1] );
}

void clearMotors(){

		motorArray[0][0] = 0; //left front
		motorArray[0][1] = 0; //left back
		motorArray[1][0] = 0; //right back
		motorArray[1][1] = 0; //right back
		updateMotorVals();
}

void driveBackwards(){

	motorArray[0][0] = -1; //left front
	motorArray[0][1] = -1; //left back
	motorArray[1][0] = -1; //right back
	motorArray[1][1] = -1; //right back
	updateMotorVals();
}

void driveForward(){

	motorArray[0][0] = 1; //left front
	motorArray[0][1] = 1; //left back
	motorArray[1][0] = 1; //right back
	motorArray[1][1] = 1; //right back
	updateMotorVals();
}

void goLeft(){

	motorArray[0][0] = -1; //left front
	motorArray[0][1] = -1; //left back
	motorArray[1][0] = 1; //right back
	motorArray[1][1] = 1; //right back
	updateMotorVals();
}


void goRight(){

	motorArray[0][0] = 1; //left front
	motorArray[0][1] = 1; //left back
	motorArray[1][0] = -1; //right back
	motorArray[1][1] = -1; //right back
	updateMotorVals();
}

void lockProceedure(){

	updateSensors();

	while( potValue > RESTING){

			activateArm(0);
			updateSensors();
		}

  	lockStatus = true; // lock arm
  	delay(250);
		updateSensors();  //update lock status
}
/*
void hangProceedure(float angle){

		lockStatus = false; // unlock arm
		updateSensors();
		delay(2000); // wait for arm to release

		angle /= 0.045; // convert angle to sensor value

    const int delayTime = 200;
    const int timesTillQuit = 4; //How many times this thing can be bad at it's job.

    bool loopFlag = true;

    int armCount = 0;       //read how many times arm has not been doing its job
    int armPos[2] = {0,0};  //stores arms to find difference

    while(loopFlag)
    {
    	  updateSensors();
        armPos[0] = potValue; //read initial value

        activateArm(1);       //activate arm

        delay(delayTime);     //wait for next sample
				updateSensors();
        armPos[1] = potValue;  // read next sample into array

        if(armPos[0] == armPos[1] || armPos[1] <= armPos[0]){ // see if arm positions are equal or decreasing. Not good.
            armCount++;
        }

        if(armCount >= timesTillQuit || potValue >= angle){
            loopFlag = false; //Break the loop.
        }
    }

    goDist(100); //Go forward slightly
    							//then contract
    loopFlag = true;

		while(loopFlag)
    {

    	  updateSensors();

        lockProceedure();

        armPos[1] = potValue;  // read next sample into array

        if(potValue <= 4){  //if arm in resting pos then
            loopFlag = false; //Break the loop.
        }
    }
}
*/
void turnToGivenAngle(int myAngleReq){

	const int angleBuffer = 1; //turn buffer

	myAngleReq = degreeToSensVar(myAngleReq); // convert angle to sensor value
	updateSensors();

	while(myAngle + angleBuffer > myAngleReq || myAngle - angleBuffer < myAngleReq ){ //is in range of the required value

		if(myAngleReq > myAngle){
			goLeft();
			updateSensors();
		}
		else if(myAngleReq < myAngle){
			goRight();
			updateSensors();
		}

		clearMotors();
		updateSensors();
	}
}


void scoopObject(){ //close in on object and turn towards gate

	const int startingAngle = 0;
	const int myScoopDistance = 0;

	closeDistance(myScoopDistance);
	turnToGivenAngle(startingAngle);
	goDist(2000);
}

void turn90CCW(){

	const int myTurnTime = 3000;

	goLeft();
	delay(myTurnTime);
	clearMotors();
	updateMotorVals();
}

void turn90CW(){
	const int myTurnTime = 3000;

	goRight();
	delay(myTurnTime);
	clearMotors();
	updateMotorVals();
}

void closeDistance(int dist){ //move the object in question into the sweet spot of the grabbing device

	int timeOutCounter = 0;
	int maxCounts = 4;
	int dataBuffer[2] = {0, 0};
	int minDist = 5; // mm per delayTime
	const int delayTime = 200;

	while(  sonarValue > dist ){

	driveForward(); //need a break function just in case

	updateSensors();

	dataBuffer[0] = sonarValue;

	delay(delayTime);

	updateSensors();

	dataBuffer[1] = sonarValue;


		if ( ( dataBuffer[0] - dataBuffer[1]) > minDist ){

			timeOutCounter++;
		}

		if(timeOutCounter >= maxCounts){

			break;
		}
	}
}

void setupSensors(){

	delay(100);
	const int sampleSize = 3;
	int myDataBuffer = 0;

	lockHandeler(); 								//default unlocked
	openClaws(); 										// open for deafult state
	SensorValue[armPot] = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	SensorValue[l1] = 0;
	SensorValue[l2] = 0;
	SensorValue[l3] = 0;

	lineArray[0] = SensorValue[l1];
	lineArray[1] = SensorValue[l2];
	lineArray[2] = SensorValue[l3]; //just incase values cannot be cleared like it states.


	for(int i = 0; i < sampleSize; i++){

		myDataBuffer += SensorValue[l2];
}
 myDataBuffer /= sampleSize;

 lineThreshold[0] = myDataBuffer;

 //SensorValue[degree] = 0;
}

void armHoldHandler(){
	float holdingAngle = holdAngle;

	holdingAngle /= 0.045; // convert angle to sensor value

	if(potValue < (int)holdingAngle)
	{
		activateArm(1); //turn on
	}
	else{
		activateArm(-1); //turn off
	}
}

void setHoldAngle(float myAngle)
{
	holdAngle=myAngle;
	if(myAngle == 0)
	{
		clearMotors();
		updateSensors();
	}
		else
			updateSensors();
}

void updateSensors(){
	lineHandler();
	lockHandeler();
	armHoldHandler();
	lineArray[0] = SensorValue[l1];
	lineArray[1] = SensorValue[l2];
	lineArray[2] = SensorValue[l3];

	encoderArray[0] = SensorValue[leftEncoder];
	encoderArray[1] = SensorValue[rightEncoder];

	sonarValue = SensorValue[ultraSonic];

	potValue = SensorValue[armPot];

	//myAngle = SensorValue[degree];
}

float getArclength(unsigned int radiusAvg, int angle1, int angle2){

	const int circle = 360;
	return (float)(2 * PI * radiusAvg * (( angle1 - angle2 )/circle )  ); //arclength formula
}

void parseData(){

}

void scanArea(){

	updateSensors();

	const int degreesInCircle = 360;
	const int angleBuffer = 1;
	const int pulseTime = 250; //time to pulse motor around circle
	const int myAngleReq = myAngle + degreesInCircle;
	int i = 0; //array indexer
	while ( myAngle < myAngleReq ){

			goLeft();
			updateSensors();
			delay(pulseTime);
			clearMotors();
			updateSensors();
			rawSonarScan[i] = sonarValue;
			i++;
			}

		clearMotors();
		updateSensors();
}

int getLineAvg(){//returns true if a line is detected

	int myAvg = 0;

	lineArray[0] = SensorValue[l1];
	lineArray[1] = SensorValue[l2];
	lineArray[2] = SensorValue[l3];

	for(int i = 0; i < (sizeof(lineArray)/sizeof(int)); i++){

		myAvg += lineArray[i];
	}

	 myAvg /= sizeof(lineArray)/sizeof(int);

	 return myAvg;
}
void checkPad(){

	const int myBuffer = 100; // darker

	lineArray[1] = SensorValue[l2];


	if (lineArray[1] > lineThreshold[0] + myBuffer && lineThreshold != 0 ){

		leftPad = true;
		lineThreshold[1] = lineArray[1];
	}

	else{
		leftPad = false;
		}

}
void lineHandler(){


	checkPad(); //set flag to indicate that second line threshold as been set and ready to look for lines.




}
void followLine(){

		//myLineLevels[2] = threshold

    // RIGHT sensor sees dark:
		int threshold = 1;

		//how long should this nonsense continue?

		updateSensors();


    if(lineArray[2] > threshold)
    {
      // counter-steer right:
      goRight();
    }
    // CENTER sensor sees dark:
    if(lineArray[1] > threshold)
    {
      // go straight
     driveForward();
    }
    // LEFT sensor sees dark:
    if(lineArray[0] > threshold)
    {
      // counter-steer left:
     goLeft();
    }
  }

#endif
