#ifndef	_SENSE
#define _SENSE

int lineArray[3] = {0,0,0}; //left center right
int lineValues[3] = {0, 0, 0};
int encoderArray[2] = {0,0};
int sonarValue = 0;
int potValue = 0;
int lineAvg[2] = {0,0}; //store line sensor offset.
int getLineAvg(void);

int degreeToSensVar(int mydegree){
	const int sensorMul = 10;
	return mydegree * sensorMul;
}

#endif
