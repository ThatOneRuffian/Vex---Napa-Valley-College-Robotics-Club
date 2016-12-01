#ifndef	_SENSE
#define _SENSE

int lineArray[3] = {0,0,0};
int encoderArray[2] = {0,0};
int sonarValue = 0;
int potValue = 0;
int lineAvg[2] = {0,0}; //store line sensor offset.
int getLineAvg(void);

void updateSensors(void);

int getLineAvg(){//returns true if a line is detected

	int myAvg = 0;

	updateSensors();

	for(int i = 0; i < (sizeof(lineArray)/sizeof(int)); i++){

		myAvg += lineArray[i];
	}

	 myAvg /= sizeof(lineArray)/sizeof(int);

	 return myAvg;
}



int degreeToSensVar(int mydegree){
	const int sensorMul = 10;
	return mydegree * sensorMul;
}

#endif
