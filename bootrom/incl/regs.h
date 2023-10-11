// Thanks to Atmosphere

#include <stdint.h>

#ifndef REGS_H
#define REGS_H

/**
 * Access to system registers.
 */
#define WRITE_SYSREG(sysreg, val, type) \
    asm volatile ("msr        "#sysreg", %0\n" : : "r"((type)(val)))
#define READ_SYSREG(sysreg, val, type) \
    asm volatile ("mrs        %0, "#sysreg"\n" : "=r"((type)(val)))

#define READ_SYSREG_32(sysreg, val)   READ_SYSREG(sysreg, val, uint32_t)
#define WRITE_SYSREG_32(sysreg, val)  WRITE_SYSREG(sysreg, val, uint32_t)

#define READ_SYSREG_64(sysreg, val)   READ_SYSREG(sysreg, val, uint64_t)
#define WRITE_SYSREG_64(sysreg, val)  WRITE_SYSREG(sysreg, val, uint64_t)

/**
 * Sets the base address of the EL2 exception table.
 */
inline static void set_vbar_el3(void * address) {
    WRITE_SYSREG_64(vbar_el3, (uint64_t)address);
}

/**
 * Returns the system's current Execution Level (EL).
 */
inline static uint32_t get_current_el(void) {
    uint32_t val;

    // Read the CurrentEl register, and extract the bits that tell us our EL.
    READ_SYSREG_32(CurrentEl, val);
    return val >> 2;
}

#endif