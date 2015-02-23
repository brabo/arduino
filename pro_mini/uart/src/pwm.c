#include "pwm.h"


int init_timers(void) {
	// Timer 3 B = LED 1
	TCCR0A |= (1 << WGM00); // set PWM mode 10 bits
	TCCR0A &= ~(1 << WGM01);
	TCCR0B &= ~(1 << WGM02);
	TCCR0B |= (1 << CS00);
	TCCR0B |= (1 << CS01); // set PWM frequency to prescale 64
	DDRD |= (1 << PD6); //set LED 1 as output
	DDRD |= (1 << PD5); //set LED 2 as output
	//DDRE |= (1 << PE5); //set LED 3 as output

	//TCCR4A |= (1 << WGM40); // set PWM mode 10 bits
	//TCCR4A |= (1 << WGM41); 
	//TCCR4B |= (1 << WGM42);
	//TCCR4B |= (1 << CS40);
	//TCCR4B |= (1 << CS41); // set PWM frequency to prescale 64
	//DDRH |= (1 << PH5); //set LED 4 as output
	//DDRH |= (1 << PH4); //set LED 5 as output
	//DDRH |= (1 << PH3); //set LED 6 as output 
	return 0;
}


int init_output(void) {
	TCCR0A |= (1 << COM0B1); // turn on OCR3B output
	TCCR0A |= (1 << COM0A1); // turn on OCR3A output
	//TCCR3A |= (1 << COM3C1); // turn on OCR3C output
	//TCCR4A |= (1 << COM4A1); // turn on OCR4A output
	//TCCR4A |= (1 << COM4B1); // turn on OCR4B output
	//TCCR4A |= (1 << COM4C1); // turn on OCR4C output
	return 0;
}


int hard_off(void) {
	OCR0A = 0;
	OCR0B = 0;
	//OCR3C = 0;
	//OCR4C = 0;
	//OCR4B = 0;
	//OCR4A = 0;	
	//TCCR3A &= ~(1 << COM3B1); // turn off OCR3B output
	//TCCR3A &= ~(1 << COM3A1); // turn off OCR3A output
	//TCCR3A &= ~(1 << COM3C1); // turn off OCR3A output
	//TCCR4A &= ~(1 << COM4C1); // turn off OCR3B output
	//TCCR4A &= ~(1 << COM4B1); // turn off OCR3A output
	//TCCR4A &= ~(1 << COM4A1); // turn off OCR3A output
	return 0;
}


int hard_on(void) {
	//init_timers();
	init_output();
	OCR0A = 1023;
	OCR0B = 1023;
	//OCR3C = 1023;
	//OCR4C = 1023;
	//OCR4B = 1023;
	//OCR4A = 1023;
	return 0;
}


int fade_off(void) {
    uint16_t brightness;
    //init_timers();
    init_output();
    for (brightness = 100; brightness >0; brightness--) { // demo fade in
	OCR0A = brightness;
	OCR0B = brightness;
	//OCR3C = brightness;
	//OCR4C = brightness;
	//OCR4B = brightness;
	//OCR4A = brightness;    	
	_delay_ms(10);
    }
    hard_off();
    return 0;
}


int fade_on(void) {

    uint16_t brightness;
    //init_timers();
    init_output();
    for (brightness = 0; brightness <100; brightness++) { // demo fade in
	OCR0A = brightness;
	OCR0B = brightness;
	//OCR3C = brightness;
	//OCR4C = brightness;
	//OCR4B = brightness;
	//OCR4A = brightness;    	
	_delay_ms(10);
    }
    return 0;
}

/*
int set_pwm(int pwm, uint16_t value) {

	switch(pwm) {
		case 1:
			//OCR4A = 0;
			if(value == 0) {
				TCCR4A &= ~(1 << COM4A1);
			} else {
				TCCR4A |= (1 << COM4A1);
			}		
			OCR4A = value;
			break;

		case 2:
			if(value == 0) {
				TCCR4A &= ~(1 << COM4B1);
			} else {
				TCCR4A |= (1 << COM4B1);
			}		
			OCR4B = value;
			break;

		case 3:
			if(value == 0) {
				TCCR4A &= ~(1 << COM4C1);
			} else {
				TCCR4A |= (1 << COM4C1);
			}		
			OCR4C = value;
			break;

		case 4:
			if(value == 0) {
				TCCR3A &= ~(1 << COM3C1);
			} else {
				TCCR3A |= (1 << COM3C1);
			}
			OCR3C = value;		
			break;

		case 5:
			if(value == 0) {
				TCCR3A &= ~(1 << COM3A1);
			} else {
				TCCR3A |= (1 << COM3A1);
			}
			OCR3A = value;
			break;

		case 6:
			if(value == 0) {
				TCCR3A &= ~(1 << COM3B1);
			} else {
				TCCR3A |= (1 << COM3B1);
			}
			OCR3B = value;		
			break;
	}
}


int special_fade(void) {
	uint16_t brightness0;
	uint16_t brightness1 = 0;
	uint16_t brightness2 = 0;
	uint16_t brightness3 = 0;
	hard_off();
	//init_timers();
	//init_output();
	//hard_off();
	TCCR4A |= (1 << COM4A1);
	for(brightness0 = 0; brightness0<20; brightness0++) {
		OCR4A = brightness0;
		_delay_ms(10);
	}
	TCCR4A |= (1 << COM4B1);
	for(brightness0 = 20; brightness0<40; brightness0++) {
		OCR4A = brightness0;
		
		_delay_ms(10);
	}
	TCCR4A |= (1 << COM4C1);
	for(brightness0 = 40; brightness0 >20; brightness0--) {
		OCR4A = brightness0;
		OCR4B = brightness1++;
		OCR4C = brightness2++;
		_delay_ms(10);
	}
	TCCR3A |= (1 << COM3C1);
	for(brightness1 = 40; brightness1 >20; brightness1--) {
		OCR4A = brightness0--;
		OCR4B = brightness1;
		OCR4C = brightness2++;	
		OCR3C = brightness3++;	
		_delay_ms(10);
	}
	OCR4A = 0;
	TCCR4A &= ~(1 << COM4A1);
	TCCR3A |= (1 << COM3A1);
	for(brightness2 = 40; brightness2 >20; brightness2--) {
		OCR4B = brightness1--;
		OCR4C = brightness2;
		OCR3C = brightness3++;
		OCR3A = brightness0++;
		_delay_ms(10);
	}
	OCR4B = 0;
	TCCR4A &= ~(1 << COM4B1);
	TCCR3A |= (1 << COM3B1);
	for(brightness3 = 40; brightness3 >20; brightness3--) {
		OCR4C = brightness2--;
		OCR3C = brightness3;
		OCR3A = brightness0++;
		OCR3B = brightness1++;
		_delay_ms(10);
	}
	OCR4C = 0;
	TCCR4A &= ~(1 << COM4C1);
	for(brightness0 = 40; brightness0 >20; brightness0--) {
		OCR3C = brightness3--;
		OCR3A = brightness0;
		OCR3B = brightness1++;
		_delay_ms(10);
	}
	OCR3C = 0;
	TCCR3A &= ~(1 << COM3C1);	
	for(brightness1 = 40; brightness1 >20; brightness1--) {
		OCR3B = brightness1;
		OCR3A = brightness0--;
		_delay_ms(10);
	}
	OCR3A = 0;
	TCCR3A &= ~(1 << COM3A1);
	for(brightness1 = 20; brightness1 !=0; brightness1--) {
		OCR3B = brightness1;
		_delay_ms(10);
	}
	hard_off();
	return 0;
} 

int special_fade2(void) {
	uint16_t brightness0;
	uint16_t brightness1 = 0;
	uint16_t brightness2 = 0;
	uint16_t brightness3 = 0;
	//hard_off();
	//init_timers();
	//init_output();
	hard_off();
	_delay_ms(20);
	OCR3B = 0;
	TCCR3A |= (1 << COM3B1);
	for(brightness0 = 0; brightness0<20; brightness0++) {
		OCR3B = brightness0;
		_delay_ms(10);
	}
	OCR3A = 0;
	TCCR3A |= (1 << COM3A1);
	for(brightness0 = 20; brightness0<40; brightness0++) {
		OCR3B = brightness0;
		OCR3A = brightness1++;
		_delay_ms(10);
	}
	OCR3C = 0;
	TCCR3A |= (1 << COM3C1);
	for(brightness0 = 40; brightness0 >20; brightness0--) {
		OCR3B = brightness0;
		OCR3A = brightness1++;
		OCR3C = brightness2++;
		_delay_ms(10);
	}
	OCR4C = 0;
	TCCR4A |= (1 << COM4C1);
	for(brightness1 = 40; brightness1 >20; brightness1--) {
		OCR3B = brightness0--;
		OCR3A = brightness1;
		OCR3C = brightness2++;	
		OCR4C = brightness3++;	
		_delay_ms(10);
	}
	OCR4B = 0;
	OCR3B = 0;
	TCCR3A &= ~(1 << COM3B1);
	TCCR4A |= (1 << COM4B1);
	for(brightness2 = 40; brightness2 >20; brightness2--) {
		OCR3A = brightness1--;
		OCR3C = brightness2;
		OCR4C = brightness3++;
		OCR4B = brightness0++;
		_delay_ms(10);
	}
	OCR4A = 0;
	OCR3A = 0;
	TCCR3A &= ~(1 << COM3A1);
	TCCR4A |= (1 << COM4A1);
	for(brightness3 = 40; brightness3 >20; brightness3--) {
		OCR3C = brightness2--;
		OCR4C = brightness3;
		OCR4B = brightness0++;
		OCR4A = brightness1++;
		_delay_ms(10);
	}
	OCR3C = 0;
	TCCR3A &= ~(1 << COM3C1);
	for(brightness0 = 40; brightness0 >20; brightness0--) {
		OCR4C = brightness3--;
		OCR4B = brightness0;
		OCR4A = brightness1++;
		_delay_ms(10);
	}
	OCR4C = 0;
	TCCR4A &= ~(1 << COM4C1);	
	for(brightness1 = 40; brightness1 >20; brightness1--) {
		OCR4B = brightness0--;
		OCR4A = brightness1;
		_delay_ms(10);
	}
	OCR4B = 0;
	TCCR4A &= ~(1 << COM4B1);
	for(brightness1 = 20; brightness1 !=0; brightness1--) {
		OCR4A = brightness1;
		_delay_ms(10);
	}
	hard_off();
	return 0;
}

int get_pwm(int led_num) {
	uint16_t val;
	char buffer[13];

	switch(led_num) {
		case 1:
			val = OCR4A;
			sprintf (buffer, "\"pwm1\",%d", val);
			break;
		case 2:
			val = OCR4B;
			sprintf (buffer, "\"pwm2\",%d", val);
			break;
		case 3:
			val = OCR4C;
			sprintf (buffer, "\"pwm3\",%d", val);
			break;
		case 4:
			val = OCR3C;
			sprintf (buffer, "\"pwm4\",%d", val);
			break;
		case 5:
			val = OCR3A;
			sprintf (buffer, "\"pwm5\",%d", val);
			break;
		case 6:
			val = OCR3B;
			sprintf (buffer, "\"pwm6\",%d", val);
			break;
	}

	//sprintf (buffer, "%d", val);

    char *ptr;
    ptr = buffer;

    send_uart0(ptr);
    send_uart1(ptr); 
}

int go_loco(void) {
	hard_off();
    fade_on();
    hard_off();
    special_fade();
    special_fade2();
    hard_on();
    _delay_ms(20);
    hard_off();
    _delay_ms(20);
    hard_on();
    _delay_ms(20);
    hard_off();
    _delay_ms(20);
    hard_on();
    _delay_ms(20);
    hard_off();	
    _delay_ms(20);
    hard_off();
    _delay_ms(20);
    hard_on();
    _delay_ms(20);
    hard_off();
    _delay_ms(20);
    hard_on();
    _delay_ms(20);
    special_fade2();
    special_fade();
    special_fade2();
    special_fade();
} */