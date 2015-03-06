#include "main.h"

int main(void)
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

	printf("testing 123\r\n");
	printf("NaNaNaNaNa WATMAN\r\n");

	init_sd();
	printf("cmd> ");

	while(1) {
		printf("NaNaNaNaNa WATMAN\r\n");
		_delay_ms(1000);
		init_sd();

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
	return 0;
}