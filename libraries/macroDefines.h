#ifndef	_macros
#define _macros

//*************Controller Macros - Start*****************//
#define THROTTLE vexRT[Ch3]
#define TURN vexRT[Ch1]
#define CLAWCLOSE vexRT[Btn8D]
#define CLAWOPEN vexRT[Btn8R]
#define TOSS vexRT[Btn6U]
#define ANTITOSS vexRT[Btn6D]
//*************Controller Macros - End*****************//

//*************Ultra Sonic Sensor Macros - Start*****************//
#define FRONTDISTANCE SensorValue(ultraSonic)
//*************Ultra Sonic Sensor Macros - End*****************//
#endif
