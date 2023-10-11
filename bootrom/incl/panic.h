#include <uart.h>

#ifndef PANIC_H
#define PANIC_H

void panic(char* errorString) {
    puts("An error has occured.\n");
    puts("Its means what critical error has occured. We cant continue.\n");

    puts("Reason: ");
    puts(errorString);
    puts("\n");

    for(;;) 
        asm("wfe");
    __builtin_unreachable();
}

#endif