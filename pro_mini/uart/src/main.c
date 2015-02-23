#include "main.h"

void main(void)
{
	FILE usartout = FDEV_SETUP_STREAM(uart_sendbyte, NULL, _FDEV_SETUP_WRITE);
	stdout = &usartout;

	char cmd[85];
	char cmdchar;
	uint8_t len = 0;
	uint8_t maxlen = 80;
	char *ptr;
	ptr = cmd;

	uart_init();
	init_timers();
	init_output();
	hard_on();

	printf("testing 123\r\n");
	printf("NaNaNaNaNa WATMAN\r\n");
	printf("cmd> ");

	while(1) {
		printf("NaNaNaNaNa WATMAN\r\n");
		_delay_ms(10);
		fade_off();
		_delay_ms(10);
		fade_on();
/*		cmdchar = uart_getbyte();
		if( cmdchar == '\r' || cmdchar == '\n' || len >= maxlen ) {
			if( len >= maxlen ) {
				uart_sendbyte(cmdchar);
				cmd[len++] = cmdchar;
			}
			cmd[len] = '\0';
			printf("\r\n");
			uart_send(ptr);
			printf("\r\n");
			len = 0;
			//uart_send(string_cmd);
			printf("cmd> ");
		} else {
			uart_sendbyte(cmdchar);
			cmd[len++] = cmdchar;
		} */
	}
}