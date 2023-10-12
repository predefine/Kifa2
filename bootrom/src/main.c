#include <stdint.h>
#include <uart.h>
#include <regs.h>
#include <panic.h>
#include <virtio.h>

extern uint64_t __ivt;

void bmain() {
    // ничо я тебе не обязан и ничо давать не буду
    set_vbar_el3(&__ivt);
    puts("Current EL: ");
    puthex(get_current_el());
    puthex(scan_mmio_legacy_virtio_device((void*)0xa003e00)->config.capacity);
    for(;;) putc(getc());
}

void panic_int() {
    
    panic("An interrupt has occured. We dont should get this!");
}