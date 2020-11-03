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
void print_button_state(void) {
	static bool last_button_state;
	static bool button_pressed;
	button_pressed = button_state();
	if (button_pressed == true && last_button_state != button_pressed) {
		printf("HIGH\n");
		last_button_state = button_pressed;
	}
	else if (button_pressed == false && last_button_state != button_pressed) {
		printf("LOW\n");
		last_button_state = button_pressed;
	}
}