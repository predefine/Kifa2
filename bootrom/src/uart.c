#include <soc.h>
#include <stddef.h>

void wait_tx_transfer_end() {
    while ( UART0_FR & (1 << 5) ) { }
}

void wait_rx_transfer_get_something() {
    while ( UART0_FR & (1 << 4) ) { }
}

void putc(unsigned char c) {
    wait_tx_transfer_end();
    UART0_DR = c;
}

unsigned char getc() {
    wait_rx_transfer_get_something();
    return UART0_DR;
}

void puts(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i ++)
		putc((unsigned char)str[i]);
}