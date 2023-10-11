ESR values
 - ESR >> 26 = EC (for example 0x17 for smc)
 - (ESR & ((1 << 17) - 1)) = ISS (imm16, a number from call for example smc #0 for 0)