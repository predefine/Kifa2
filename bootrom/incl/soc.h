#include <stdint.h>

#ifndef SOC_H
#define SOC_H

#define HW_REGISTER_RW(addr) (*(volatile uint32_t *)(addr))

#if !defined(MODE_DEV) || !defined(MODE_PROD) || !defined(MODE_TEST)
#pragma message "Mode not set. Using DEV"
#define MODE_DEV 1
#endif

#ifdef MODE_DEV
#include <soc_dev.h>
#endif

#ifdef MODE_PROD
#error because currently prod isnt available
#endif

#endif