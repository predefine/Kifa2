#include <stdint.h>
#include <uart.h>

void bmain() {
    // ничо я тебе не обязан и ничо давать не буду
    puts("Hello world wtf!\r\n");
    puthex(10);
    for(;;) putc(getc());
}