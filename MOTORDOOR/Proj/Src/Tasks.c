/*
 * Tasks.c
 *
 * Created: 16-Sep-18 6:25:43 PM
 *  Author: Abood
 */ 
#include "drivers.h"
extern uint8_t Key;
void Main_task()
{


for(;;)
{
	
	_delay_ms(300);
	switch (Key)
	{
		
		
		case MANUALMODE: //
		MANUAL_MODE();
		break;
		
		case WINTERMODE:	//
		WINTER_MODE();
		break;
		
		case EXIT: //
		EXIT_();
		break;
		
		case OPENMODE://
		OPEN_MODE();
		break;
		
		case MENU: //
		MENU_();
		break;
		
		case AUTOMATICMODE: //
		AUTOMATIC_MODE();
		break;
		
		
		case DOWN: //
		DOWN_();
		break;
		
		case ONEWAY: //
		ONEWAY_();
		break;
		
		
		case UP: //
		UP_();
		break;
		
		case CLOSEDMODE: //
		CLOSEDMODE_()	;
		break;
		
	}

}
}