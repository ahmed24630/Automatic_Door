/*
 * MOTORDriver.c
 *
 * Created: 15-Sep-18 12:45:24 PM
 *  Author: Abood
 */ 

#include <avr/io.h>
#include "drivers.h"

void MOTORINIT()
{
	DDRD|=(1<<DDD6)|(1<<DDD5)|(1<<DDD4);//O\P
}

void RotateClockwise()
{
	PORTD |= (1<<PD5) ;				//clockwise full speed
	#if TWoSpeed
	_delay_ms(1000);
	PORTD |= (1<<PD6) ;				//half speed
	#endif
}
void Rotate_Counter_Clockwise()
{
	PORTD |= (1<<PD4) ;				//counterclockwise full speed
	#if TWoSpeed
	_delay_ms(1000);
	PORTD |= (1<<PD6) ;				//half speed
	#endif
}

void CloseDoor()
{      
	   if((switch_1_read()==0))
	   { 
		   lcd_clear();
	   }
	    while(switch_1_read()==0)
		{	
			LCDWriteTXT_XY((uint8_t*)"Closing",4,0);
			Rotate_Counter_Clockwise();
		}
}

void OpenDoor()
{
	if((switch_2_read()==0))
	{
		lcd_clear();
	}
	while(switch_2_read()==0)
	{
		LCDWriteTXT_XY((uint8_t*)"OPening",4,0);
		RotateClockwise();
	}
}

void Default()
{		
	//MoOtor Run in low speed and closing door 
    lcd_clear();
	while(switch_1_read()==0)
	{
	LCDWriteTXT_XY((uint8_t*)"DEF CLOSE",3,0);
	PORTD |= (1<<PD4) ;				//counterclockwise full speed
	#if TWoSpeed
	PORTD |= (1<<PD6) ;				//half speed
	#endif
	}
}