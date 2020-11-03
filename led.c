#include <avr/io.h>
#include "led.h"
#include <stdint.h>

#define LED_PIN 6
#define LED_PORT PORTD

void LED_init(void) {
	DDRD |= (1 << LED_PIN);
}

uint8_t simple_ramp() {
	static uint8_t brightness = 0;
	static int8_t dir = 1;
	if (brightness == 255) {
		dir = -1;
	}
	else if (brightness == 0) {
		dir = 1;
	}
	brightness += dir;
	return brightness;
}

void LED_flip(void) {
	LED_PORT ^= (1 << LED_PIN);
}