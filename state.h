#ifndef STATE_H_
#define STATE_H_

enum STATE {
	PULSE,
	POTENTIOMETER,
	BLINK,
	OFF
};

enum STATE get_next_state(enum STATE s);

#endif