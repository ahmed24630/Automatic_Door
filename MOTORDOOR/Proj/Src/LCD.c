/*
/1 	01 	Clear display screen
2 	02 	Return home
3 	04 	Decrement cursor (shift cursor to left)
4 	06 	Increment cursor (shift cursor to right)
5 	05 	Shift display right
6 	07 	Shift display left
7 	08 	Display off, cursor off
8 	0A 	Display off, cursor on
9 	0C 	Display on, cursor off
10 	0E 	Display on, cursor blinking
11 	0F 	Display on, cursor blinking
12 	10 	Shift cursor position to left
13 	14 	Shift cursor position to right
14 	18 	Shift the entire display to the left
15 	1C 	Shift the entire display to the right
16 	80 	Force cursor to beginning ( 1st line)
17 	C0 	Force cursor to beginning ( 2nd line)/*/

#include "drivers.h"

uint8_t txt[5];

void lcd_init(){
	INIT_PORT;
	#if RW_SUPPORT
	Rw(0);
	#endif
	lcd_write_cmd(0x2);
	lcd_write_cmd(0x28);  // 4data line
	lcd_write_cmd(0x01);
	lcd_write_cmd(0x0c);  // display on cursor off
	lcd_write_cmd(0x06);  // increment cursor right
	lcd_write_cmd(0x80);  // set courser at the beginning of the first line
	_delay_ms(20);
}

void lcd_write(uint8_t cmd){
	// read first 4 bit
	D7(READBIT(cmd,7));
	D6(READBIT(cmd,6));
	D5(READBIT(cmd,5));
	D4(READBIT(cmd,4));
	lcd_send_pulse_for_update_data_or_cmd();

	// read second 4 bit
	D7(READBIT(cmd,3));
	D6(READBIT(cmd,2));
	D5(READBIT(cmd,1));
	D4(READBIT(cmd,0));

	lcd_send_pulse_for_update_data_or_cmd();
}


void lcd_write_cmd(uint8_t cmd){
	RS(0); // Rs = 0
	lcd_write(cmd);
}

void lcd_write_char(uint8_t cmd){
	RS(1); // Rs = 1
	lcd_write(cmd);
}


void lcd_write_txt(uint8_t *x){
	for(int i = 0; x[i] != '\0'; i++)
	lcd_write_char(x[i]);
}

void lcd_write_number(uint16_t data){
	IntToString(data,txt);
	lcd_write_txt(txt);
}

void IntToString(uint16_t number, uint8_t *txt){
	
	if(number < 10){
		txt[0] = number % 10 + 48;
		txt[1] = '\0';
	}
	else if(number < 100){
		txt[0] = number / 10 + 48;
		txt[1] = number % 10 + 48;
		txt[2] = '\0';
	}
	else if(number < 1000){
		txt[0] = number / 100 + 48;
		number = number % 100 ;
		txt[1] = number / 10 + 48;
		txt[2] = number % 10 + 48;
		txt[3] = '\0';
	}
	else  if(number < 10000){
		txt[0] = number / 1000 + 48;
		number = number % 1000 ;
		txt[1] = number / 100 + 48;
		number = number % 100 ;
		txt[2] = number / 10 + 48;
		txt[3] = number % 10 + 48;
		txt[4] = '\0';
	}
	else  if(number < 100000){
		txt[0] = number / 10000 + 48;
		number = number % 10000 ;
		txt[1] = number / 1000 + 48;
		number = number % 1000 ;
		txt[2] = number / 100 + 48;
		number = number % 100 ;
		txt[3] = number / 10 + 48;
		txt[4] = number % 10 + 48;
		txt[5] = '\0';
	}
}

void lcd_send_pulse_for_update_data_or_cmd(){
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}

void LCDWriteTXT_XY(uint8_t * TXT,uint8_t X,uint8_t Y)
{
	if(Y==0 && X<16)
	{
		lcd_write_cmd(0x80+X);
	}
	else if(Y==1 && X<16)
	{
		lcd_write_cmd(0xC0+X);
	}
	lcd_write_txt(TXT);
}
uint8_t readbit(uint8_t PORT,uint8_t pinno)
{
	if((((PORT&(1<<pinno))>>(pinno))==1))
	{
		return 1;

	}
	else
	
	return 0;
}