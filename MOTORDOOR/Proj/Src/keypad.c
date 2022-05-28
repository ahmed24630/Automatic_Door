
#include <avr\io.h>
extern uint8_t Key;
#include "drivers.h"
void keyPadInit()
{
	
	DDRC|=(1<<DDC5)|(1<<DDC6);// o/p
	PORTC |=(1<<DDC0)|(1<<DDC1)|(1<<DDC2)|(1<<DDC3)|(1<<DDC4);//activate pull up resistor
	PORTC |=(1<<DDC5)|(1<<DDC6);//put high on PORTC5-6 is default
	
}

void  Keypad (void )
{
	
	int i=0;
	uint8_t temp=0;
	uint8_t temp2=0;
	
	temp=PORTC|(1<<PC5)|(1<<PC6);
	
	for(;;)
	{
		
	
	for (i=PC5;i<PC7;i++)
	{
		
		PORTC=(~(1<<i))&(temp);
		
		
		temp2=PORTC&(0x60);

		switch(temp2)
		{
			
			case 0x20:
			if(((PINC&(1<<PINC0))==0))
			{   
				OpenBuzzer();
				while((PINC&(1<<PINC0))==0);
				CloseBuzzer();
				Key= '0';
			}
			else if(((PINC&(1<<PINC1))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC1))==0);
				CloseBuzzer();
				Key='2';
			}
			else if(((PINC&(1<<PINC2))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC2))==0);
				CloseBuzzer();
				Key= '4';
			}
			else if(((PINC&(1<<PINC3))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC3))==0);
				CloseBuzzer();
				Key= '6';
			}
			if(((PINC&(1<<PINC4))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC4))==0);
				CloseBuzzer();
				Key= '8';
			}
			
			break;
			
			case 0x40:
			
			if(((PINC&(1<<PINC0))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC0))==0);
				CloseBuzzer();
				Key= '1';
			}
			else if(((PINC&(1<<PINC1))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC1))==0);
				CloseBuzzer();
				Key= '3';
			}
			else if(((PINC&(1<<PINC2))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC2))==0);
				CloseBuzzer();
				Key= '5';
			}
			else if(((PINC&(1<<PINC3))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC3))==0);
				CloseBuzzer();
				Key= '7';
			}
			else if(((PINC&(1<<PINC4))==0))
			{
				OpenBuzzer();
				while((PINC&(1<<PINC4))==0);
				CloseBuzzer();
				Key= '9';
			}
			break;
		}
	}
  }
}

