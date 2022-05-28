/*
 * MOTORDOOR.c
 *
 * Created: 13-Sep-18 8:07:22 PM
 * Author : AbdelRhman
 */ 

#include "drivers.h"
   
 uint8_t Key=0;
  
int main(void)
{
	

    keyPadInit();
    lcd_init();
	MOTORINIT();
	inputsinit();
    BuzzerInit();

	
	LCDWriteTXT_XY((uint8_t*)"WeLcome",4,0);
	LCDWriteTXT_XY((uint8_t*)"PleaseSelectMODE",0,1);
	
	xTaskCreate
	(Keypad,(signed char *)"KeyPad",80,NULL,tskIDLE_PRIORITY,NULL); 

	xTaskCreate
	(Main_task,(signed char *)"Main_task",80,NULL,tskIDLE_PRIORITY,NULL);

   //start scheduler
   vTaskStartScheduler();
 for (;;)
 {
 }
	
	
}


void vApplicationIdleHook()
{
}
		
	