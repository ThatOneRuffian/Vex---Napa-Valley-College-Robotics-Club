#ifndef	_macros
#define _macros

//*************Controller Macros - Start*****************//
#define THROTTLE    vexRT[Ch3]
#define TURN        vexRT[Ch1]
#define CLAWCLOSE   vexRT[Btn8D]
#define CLAWOPEN    vexRT[Btn8R]
#define HIGHTOSS    vexRT[Btn6U]
#define FARTOSS     vexRT[Btn6D]
#define debug1				vexRT[Btn7U]
#define debug2				vexRT[Btn7D]
//*************Controller Macros - End*****************//


//*************Ultra Sonic Sensor Macros - Start*****************//
#define FRONTDISTANCE SensorValue[ultraSonic]
//*************Ultra Sonic Sensor Macros - End*****************//

//*************Toss - start*****************//
#define ARMVALUE 		  SensorValue(armPot)
#define RESTING 				0
//*************Toss - end*****************//

#endif
