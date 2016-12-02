#ifndef	_macros
#define _macros

//*************Controller Macros - Start*****************//
#define THROTTLE    vexRT[Ch3]
#define TURN        vexRT[Ch1]
#define CLAWCLOSE   vexRT[Btn8D]
#define CLAWOPEN    vexRT[Btn8R]
#define HIGHTOSS    vexRT[Btn6U]
#define FARTOSS  	   vexRT[Btn6D]
#define debug1				vexRT[Btn7U]  //test arm lock
#define debug2				vexRT[Btn7D]	// test arm lock ^
#define HANG					vexRT[Btn7L]	//high hand strength test
#define LINE					vexRT[Btn7R] 	//test for line movement
#define SCAN					vexRT[Btn5U]  //scan for baddies

//*************Controller Macros - End*****************//


//*************Ultra Sonic Sensor Macros - Start*****************//
#define FRONTDISTANCE SensorValue[ultraSonic]
//*************Ultra Sonic Sensor Macros - End*****************//

//*************Toss - start*****************//
#define ARMVALUE 		  SensorValue(armPot)
#define RESTING 			0										//defined resting value for pot. shouldn't be implmented here. will fix later.
//*************Toss - end*****************//

#endif
