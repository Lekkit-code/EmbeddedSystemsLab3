#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include "serial.h"
#include <avr/pgmspace.h>


void button_init(void) {
	DDRD &= ~(PORTD<<PIND2);
}
bool button_state(void) {
	if ((PIND & (1 << PIND2)) == (1 << PIND2)) {
		return true;
	}
	else {
		return false;
	}
}