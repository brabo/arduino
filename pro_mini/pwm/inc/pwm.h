#ifndef __PWM_H__
#define __PWM_H__

#include "main.h"
#include <avr/io.h>

int init_timers(void);
int init_output(void);
int hard_off(void);
int hard_on(void);
int fade_off(void);
int fade_on(void);
//int special_fade(void);
//int special_fade2(void);
//int set_pwm(int pwm, uint16_t value);
//int get_pwm(int led_num);
//int go_loco(void);
#endif
