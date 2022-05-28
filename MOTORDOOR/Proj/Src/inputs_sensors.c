/*
 * inputs_sensors.c
 *
 * Created: 17-Sep-18 6:41:55 PM
 *  Author: AbdelRhman
 */ 
#include "drivers.h"



void inputsinit()
{
	CLRBIT(DDRD,DDD2);		//inputs proximity 1
	CLRBIT(DDRD,DDD3);		//inputs proximity 2
	CLRBIT(DDRD,DDD0);		//inputs limit switch 1
	CLRBIT(DDRD,DDD1);		//inputs limit switch 2
	//Enable PullUp 
	SETBIT(PORTD,PD2);		
	SETBIT(PORTD,PD3);
	SETBIT(PORTD,PD0);
	SETBIT(PORTD,PD0);
	
}

uint8_t switch_1_read()   //Middle DOOR
{
	return !(READBIT(PIND , PIND1));
}
uint8_t switch_2_read()  // End door
{
	return !(READBIT(PIND , PIND0));
}

uint8_t proximity_1_read() // IN 
{ 
	return !(READBIT(PIND , PIND2));
}
uint8_t proximity_2_read()  //OUT
{
	return !(READBIT(PIND , PIND3));
}



