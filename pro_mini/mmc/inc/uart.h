#ifndef UART_H
#define UART_H

#include "main.h"

void uart_init(void);
void uart_sendbyte(uint8_t byte);
uint8_t uart_getbyte(void);
int uart_send(uint8_t *string);


#endif