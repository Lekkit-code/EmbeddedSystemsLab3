#ifndef _LED_H_
#define _LED_H_
#include "state.h"

void LED_init(void);

uint8_t simple_ramp(void);

void LED_flip(void);

void LED_blink(uint32_t current_ten_millis);

void handle_LED(enum STATE s, uint32_t current_ten_millis);

void LED_off(void);

#endif // _LED_H_

