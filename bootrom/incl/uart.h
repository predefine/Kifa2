#ifndef UART_H
#define UART_H

void putc(unsigned char c);
void puts(const char* str);
unsigned char getc();
void puthex(unsigned int d);

#endif