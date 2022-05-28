/*
 * interrupt.c
 *
 * Created: 15-Sep-18 11:30:28 PM
 *  Author: Abood
 */ 
#include "drivers.h"

void INT0INIT()
{
	CLRBIT(DDRD,PD2);
	sei();
	GICR|=(1<<INT0);
	MCUCR|=(1<<ISC01)|(1<<ISC00);
}

void ACTIVATEINT()
{
	SETBIT(DDRC,PC7);
	SETBIT(PORTC,PC7);
	
}