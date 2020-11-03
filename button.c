#include <avr/io.h>

void button_init(void) {
	DDRD &= ~(PORTD<<PIND2);
}
void button_print_state(void) {

}