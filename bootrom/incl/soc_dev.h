// QEMU
#pragma message "Development env"
#define MMIO_BASE 0x0a000000
#define GPIO_BASE "Later."
#define UART0_BASE 0x09000000
#define UART0_DR HW_REGISTER_RW(UART0_BASE + 0x0)
#define UART0_FR HW_REGISTER_RW(UART0_BASE + 0x18)