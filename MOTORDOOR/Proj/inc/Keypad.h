/*
 * Keypad1.h
 *
 * Created: 15-Sep-18 1:09:02 PM
 *  Author: Abood
 */ 


#ifndef KEYPAD1_H_
#define KEYPAD1_H_

enum {
	MANUALMODE=48,
	WINTERMODE,
	EXIT,
	OPENMODE,
	MENU,
	AUTOMATICMODE,
	DOWN,
	ONEWAY,
	UP,
	CLOSEDMODE
	};

void keyPadInit();
void  Keypad (void );
#endif /* KEYPAD1_H_ */