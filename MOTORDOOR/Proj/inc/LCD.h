
#ifndef _LCD_
#define _LCD_
#include "drivers.h"
#define F_CPU 8000000UL

#define clear 0x01
#define home  0x02
#define inc_cur_left 0x04
#define inc_cur_right 0x06
#define shift_cur_left 0x10
#define shift_cur_right 0x14
#define shift_display_left 0x18
#define shift_display_right 0x1c

#define nd_line 0xc0
#define st_line 0x80
#define INIT_PORT DDRB |=(1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4)|(1<<PB1)|(1<<PB0);
#define  CLRBIT(PORT,pno) PORT&=~(1<<pno)
#define  SETBIT(PORT,pno) PORT|=(1<<pno)
#define  READBIT(PORT,pno) readbit(PORT,pno)
#define EN(x)   if (x == 0) CLRBIT(PORTB,1); else SETBIT(PORTB,1);;
#if RW_SUPPORT
#define Rw(x)   if (x == 0) CLRBIT(PORTB,2); else SETBIT(PORTB,2);;
#endif
#define RS(x)   if (x == 0) CLRBIT(PORTB,0); else SETBIT(PORTB,0);;
#define D7(x)   if (x == 0) CLRBIT(PORTB,7); else SETBIT(PORTB,7);;
#define D6(x)   if (x == 0) CLRBIT(PORTB,6); else SETBIT(PORTB,6);;
#define D5(x)   if (x == 0) CLRBIT(PORTB,5); else SETBIT(PORTB,5);;
#define D4(x)   if (x == 0) CLRBIT(PORTB,4); else SETBIT(PORTB,4);;
#define lcd_clear()  lcd_write_cmd(clear)
                     

// configure LCD port
void lcd_init();

// to  send command to LCD
void lcd_write_cmd(uint8_t);

// to  send data to LCD
void lcd_write_char(uint8_t);

// write complete txt
void lcd_write_txt(uint8_t *);

// write number
void lcd_write_number(uint16_t data);

// to update data
void lcd_send_pulse_for_update_data_or_cmd();

//Convert from int to ascii string
void IntToString(uint16_t number, uint8_t *txt);

uint8_t readbit(uint8_t PORT,uint8_t pinno);

void LCDWriteTXT_XY(uint8_t * TXT,uint8_t X,uint8_t Y);
#endif