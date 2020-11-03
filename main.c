#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>
#include <avr/interrupt.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "potentiometer.h"

volatile uint16_t adc_value = 0;

int main (void) {

	LED_init();
	uart_init();
	timer_init();
	button_init();
	potentiometer_init();
	sei();

	while (1) {
	}
	return 0;
}

ISR(TIMER2_COMPA_vect) //When the interrupt triggers, updates the brightness of the LED, starts a new ADC-conversion and clears the interrupt flag.
{
	OCR0A = adc_value;
	ADCSRA |= (1 << ADSC);
	TIFR2 &= ~(1 << OCF2A);
}

ISR(ADC_vect) //When the interrupt triggers because an ADC-conversion is complete, updates the read value.
{
	adc_value = ADCH;
	ADCSRA &= ~(1 << ADIF);
}