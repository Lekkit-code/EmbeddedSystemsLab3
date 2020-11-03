#include <avr/io.h>
#include "timer.h"

#define MYOCR2A ((16000000/1024)*0.010)

void timer_init() {
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1); //Set the mode of TC0 to Fast PWM non-inverted mode.
	TCCR0B |= (1 << CS01) | (1 << CS00);	//Set the prescaler of TC0 to 64.
	TCCR2A |= (1 << WGM21); //Set the mode of TC2 to CTC.
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);	//Set the prescaler of TC2 to 1024.
	OCR2A = MYOCR2A;	//Set the value to count to to MYOCR0A.
	TIMSK2 |= (1 << OCIE2A);	//Enable the ISR COMPA vector.
}