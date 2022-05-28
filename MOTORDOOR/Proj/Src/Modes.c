#include "drivers.h"
#include <string.h>
void MANUAL_MODE()
{
		lcd_clear();
		LCDWriteTXT_XY((uint8_t*)"ON",6,0);
		LCDWriteTXT_XY((uint8_t*)"Manual Mode",2,1);
		MOTOR_STOP;
		#if DEBUg
		lcd_clear();
		LCDWriteTXT_XY((uint8_t*)"STOPPED",5,0);
		#endif
		
		
		
}

void WINTER_MODE()
{
	lcd_clear();
	LCDWriteTXT_XY((uint8_t*)"ON",6,0);
	LCDWriteTXT_XY((uint8_t*)"Winter Mode",2,1);
	
}

void EXIT_()
{
	lcd_clear();
	LCDWriteTXT_XY((uint8_t*)"Thanks",4,0);
	
}

void OPEN_MODE()
{
	lcd_clear();
	LCDWriteTXT_XY((uint8_t*)"ON",6,0);
	LCDWriteTXT_XY((uint8_t*)"OPEN MODE",3,1);
	OpenDoor();
	MOTOR_STOP;
	
}

void MENU_()
{
	lcd_clear();
    LCDWriteTXT_XY((uint8_t*)"WeLcome",5,0);
    LCDWriteTXT_XY((uint8_t*)"PleaseSelectMODE",0,1);
    
}

void AUTOMATIC_MODE()
{
	lcd_clear();
	LCDWriteTXT_XY((uint8_t*)"ON",6,0);
	LCDWriteTXT_XY((uint8_t*)"AUTOMATIC",3,1);
	

	
	if(     ((proximity_1_read()==0) && (proximity_2_read()==0) && (switch_1_read()==0) && (switch_2_read()==0)  ) ||
			((proximity_1_read()==0) && (proximity_2_read()==1) && (switch_1_read()==0) && (switch_2_read()==0)  ) ||
			((proximity_1_read()==1) && (proximity_2_read()==0) && (switch_1_read()==0) && (switch_2_read()==0)  ) ||
			((proximity_1_read()==1) && (proximity_2_read()==1) && (switch_1_read()==0) && (switch_2_read()==0)  )
	
			)
	 {
		  Default();			//default
		
		  MOTOR_STOP;
		 #if DEBUg
		 lcd_clear();
	   	 LCDWriteTXT_XY((uint8_t*)"STOPPED",5,0);
		 #endif
		 
	 }
	 
	else if((proximity_1_read()==0) && (proximity_2_read()==0) && (switch_1_read()==0) && (switch_2_read()==1)  )
	 {
		 CloseDoor();		//close
		 MOTOR_STOP;
		#if DEBUg
		lcd_clear();
		LCDWriteTXT_XY((uint8_t*)"STOPPED",5,0);
		#endif
	 }	 

  else if(    ((proximity_1_read()==0) && (proximity_2_read()==1) && (switch_1_read()==1) && (switch_2_read()==0)  ) ||
		      ((proximity_1_read()==1) && (proximity_2_read()==0) && (switch_1_read()==1) && (switch_2_read()==0)  ) ||
			  ((proximity_1_read()==1) && (proximity_2_read()==1) && (switch_1_read()==1) && (switch_2_read()==0)  )
		         
		  ) 
		{
			 
			  	OpenDoor();			//open
			  	MOTOR_STOP;
				#if DEBUg
				lcd_clear();
				LCDWriteTXT_XY((uint8_t*)"STOPPED",5,0);
				#endif
			  
		  }
   
 
		 }

   


void DOWN_()
{
	
}

void ONEWAY_()
{
	lcd_clear();
	LCDWriteTXT_XY((uint8_t*)"ON",6,0);
	LCDWriteTXT_XY((uint8_t*)"ONE WAY MODE",2,1);
	
	
	 if(((proximity_1_read()==0)  && (switch_1_read()==0) && (switch_2_read()==0)  ) ||

		((proximity_1_read()==1)  && (switch_1_read()==0) && (switch_2_read()==0)  )
	
	)
	{
		Default();			//default
		
		MOTOR_STOP;
		#if DEBUg
		lcd_clear();
		LCDWriteTXT_XY((uint8_t*)"STOPPED",5,0);
		#endif
		
	}
	
	else if((proximity_1_read()==0)&& (switch_1_read()==0) && (switch_2_read()==1)  )
	{
		CloseDoor();		//close
		MOTOR_STOP;
		#if DEBUg
		lcd_clear();
		LCDWriteTXT_XY((uint8_t*)"STOPPED",5,0);
		#endif
	}

	else if(	((proximity_1_read()==1) && (switch_1_read()==1) && (switch_2_read()==0)  )
	
		   )
	{
		
		OpenDoor();			//open
		MOTOR_STOP;
		#if DEBUg
		lcd_clear();
		LCDWriteTXT_XY((uint8_t*)"STOPPED",5,0);
		#endif
		
	}
	
	
}

void UP_()
{

}

void CLOSEDMODE_()
{
	lcd_clear();
	LCDWriteTXT_XY((uint8_t*)"ON",6,0);
	LCDWriteTXT_XY((uint8_t*)"CLOSED Mode",3,1);
	CloseDoor();
	MOTOR_STOP;
}