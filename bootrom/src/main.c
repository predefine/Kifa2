#include <stdint.h>
#include <uart.h>

void bmain() {
    // ничо я тебе не обязан и ничо давать не буду
    puts("Hello world!\r\n");
    for(;;) putc(getc());
}