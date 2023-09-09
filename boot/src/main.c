#include <stdint.h>

#define PL011_BASE 0x09000000
#define PL011_DATA HW_REGISTER_RW(PL011_BASE + 0x0)