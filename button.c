#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include "serial.h"
#include <avr/pgmspace.h>
#include "state.h"


void button_init(void) //Sets the PD2 pin as input. This represents the pin2 on Arduino Uno.
{
	DDRD &= ~(PORTD<<PIND2);
}
bool button_state(void) //Checks to see if the PD2 is high or not and returns true if it is. Returns false otherwise.
{
	if ((PIND & (1 << PIND2)) == (1 << PIND2)) {
		return true;
	}
	else {
		return false;
	}
}
void print_button_state(void) //Prints HIGH if the button is pressed or LOW if it's not. Only prints if there's been a change of the button state.
{
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

enum STATE button_check(enum STATE s) //Checks to see if the button state changed. If it went from HIGH to LOW, returns the next state. Otherwise, returns the same state.
{
	static bool last_button_state;
	static bool button_pressed;
	button_pressed = button_state();
	if (button_pressed == true && last_button_state != button_pressed) {
		last_button_state = button_pressed;
	}
	else if (button_pressed == false && last_button_state != button_pressed) {
		s = get_next_state(s);
		last_button_state = button_pressed;
	}
	return s;
}

