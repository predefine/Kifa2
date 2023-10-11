#include <stdint.h>

#ifndef INTERRUPT_HELPER_H
#define INTERRUPT_HELPER_H

uint16_t esr_get_imm16(uint64_t esr) {
    return (esr & ((1 << 17) - 1));
}

uint8_t esr_get_ec(uint64_t esr) {
    return esr >> 26;
}

#endif