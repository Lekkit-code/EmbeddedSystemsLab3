#include "potentiometer.h"
#include <avr/io.h>

void potentiometer_init(void) {
	ADMUX |= (1 << REFS0); //Sets the reference to Vcc.
	ADMUX &= ~(1 << MUX0) | ~(1<< MUX1) | ~(1<<MUX2) | ~(1<<MUX3); //Sets the pin we want to use to ADC0. This is A0 on the Arduino Uno.
	ADMUX |= (1 << ADLAR); //Sets out conversion results to be left adjusted.
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1); //Sets the prescaler to 8.
	ADCSRA |= (1 << ADIE); //Enables the conversion complete interrupt.
	ADCSRA |= (1 << ADEN); //Enables the ADC.
}