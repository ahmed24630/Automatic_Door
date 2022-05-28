/*
 * Buzzer.c
 *
 * Created: 25-Sep-18 3:43:38 PM
 *  Author: AbdelRhman
 */ 

#include "drivers.h"

void BuzzerInit(void)
{
	SETBIT(DDRB,DDB2);//output
}

void OpenBuzzer(void)
{
	SETBIT(PORTB,PB2);
}
void CloseBuzzer(void)
{
	CLRBIT(PORTB,PB2);
}