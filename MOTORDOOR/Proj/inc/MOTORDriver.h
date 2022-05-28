/*
 * MOTORDriver.h
 *
 * Created: 15-Sep-18 12:46:50 PM
 *  Author: Abood
 */ 


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_
#include "drivers.h"
#define MOTOR_STOP	 CLRBIT(PORTD,PD6);\
CLRBIT(PORTD,PD5);\
CLRBIT(PORTD,PD4);

void MOTORINIT();
void RotateClockwise();
void Rotate_Counter_Clockwise();
void OpenDoor();
void CloseDoor();
void Default();
#define TWoSpeed 0 //if this flag enable twos peed will be supported
#endif /* MOTORDRIVER_H_ */