#include <avr/io.h>

void button_init(void) {
	DDRD &= ~_BR(DDRD2)
}