#include <stdint.h>
#include <uart.h>
#include <regs.h>
#include <panic.h>
#include <virtio.h>

extern uint64_t __ivt;

void bmain() {
    // ничо я тебе не обязан и ничо давать не буду
    set_vbar_el3(&__ivt);
    if(get_current_el() < 3) {
        panic("EL is too small!");
    }

    struct virtio_device_legacy* blk;
    
    blk = scan_mmio_legacy_virtio_device((void*)0xa003e00);

    legacy_virtio_begin_init(blk);

    puts("Init seems to be ok\n");
    for(;;) putc(getc());
}

void panic_int() {
    
    panic("An interrupt has occured. We dont should get this!");
}