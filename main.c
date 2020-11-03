#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdbool.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"

int main (void) {

	LED_init();
	uart_init();
	timer_init();
	button_init();

	while (1) {
		print_button_state();
	}
	return 0;
}

