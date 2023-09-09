#ifndef SOC_H
#define SOC_H

#ifndef MODE_DEV || MODE_PROD || MODE_TEST
#warning "Mode not set. Using DEV"
#define MODE_DEV 1
#endif

#ifdef MOVE_DEV
#pragma message "Development env"
#endif

#endif