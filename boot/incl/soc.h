#ifndef SOC_H
#define SOC_H

#define HW_REGISTER_RW(addr) (*(volatile uint32_t *)(addr))

#ifndef MODE_DEV || MODE_PROD || MODE_TEST
#warning "Mode not set. Using DEV"
#define MODE_DEV 1
#endif

#ifdef MODE_DEV
// QEMU
#pragma message "Development env"
#define MMIO_BASE 0x0a000000
#define GPIO_BASE "Later."
#define UART0_BASE MMIO_BASE + 0x1000000
#define UART0_DR HW_REGISTER_RW(UART0_BASE + 0x0)
#define UART0_FR HW_REGISTER_RW(UART0_BASE + 0x18)
#endif

#ifdef MODE_PROD
// Nothing. Because kifa is developing.
#endif

#endif