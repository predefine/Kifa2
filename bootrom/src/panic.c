#include <uart.h>
#include <panic.h>

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
