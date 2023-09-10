#ifndef SOC_H
#define SOC_H

#define HW_REGISTER_RW(addr) (*(volatile uint32_t *)(addr))

#ifndef MODE_DEV || MODE_PROD || MODE_TEST
#warning "Mode not set. Using DEV"
#define MODE_DEV 1
#endif

#ifdef MODE_DEV
#include <soc_dev.h>
#endif

#ifdef MODE_PROD
#error but currently prod isnt available
#endif

#endif