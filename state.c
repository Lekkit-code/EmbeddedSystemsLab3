#include "state.h"

enum STATE get_next_state(enum STATE s) //Takes the current state and returns the next one.
{
	switch (s) {
	case PULSE:
		return POTENTIOMETER;
	case POTENTIOMETER:
		return BLINK;
	case BLINK:
		return OFF;
	case OFF:
		return PULSE;
	default:
		return s;
	}

}