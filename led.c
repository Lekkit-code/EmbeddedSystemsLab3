#include <avr/io.h>
#include "led.h"
#include <stdint.h>
#include "state.h"
#include "timer.h"
#include "potentiometer.h"

#define LED_PIN 6
#define LED_PORT PORTD
#define BLINK_DELAY_TEN_MILLIS 100

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

void LED_off(void){
	LED_PORT &= ~(1 << LED_PIN);
}

void LED_blink(uint32_t current_ten_millis) {
	static uint32_t last_ten_millis = 0;
	if (BLINK_DELAY_TEN_MILLIS < current_ten_millis - last_ten_millis) {
		LED_flip();
		last_ten_millis = current_ten_millis;
	}
}

void handle_LED(enum STATE s, uint32_t current_ten_millis) //Checks the state and handles LED accordingly.
{
	switch (s) {
	case PULSE:
		enable_PWM();
		disable_ADC();
		break;
	case POTENTIOMETER:
		enable_PWM();
		enable_ADC();
		break;
	case BLINK:
		disable_ADC();
		disable_PWM();
		LED_blink(current_ten_millis);
		break;
	case OFF:
		LED_off();
		disable_ADC();
		disable_PWM();
		break;
	}
}