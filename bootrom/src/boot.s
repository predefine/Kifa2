.global _start

_start:
    ldr x30, =stack_top
    mov sp, x30
    bl bmain
    b halt

halt:
    nop
    wfe
    b halt

.global __ivt
.balign 0x800
__ivt:

_exc_sp0_sync:
    b panic_int
.balign 0x80
_exc_sp0_irq:
    b panic_int
.balign 0x80
_exc_sp0_fiq:
    b panic_int
.balign 0x80
_exc_sp0_serror:
    b panic_int

.balign 0x80
_exc_spx_sync:
    b panic_int
.balign 0x80
_exc_spx_irq:
    b panic_int
.balign 0x80
_exc_spx_fiq:
    b panic_int
.balign 0x80
_exc_spx_serror:
    b panic_int

.balign 0x80
_exc_lower_sync:
    b panic_int

.balign 0x80
_exc_lower_irq:
    b panic_int

.balign 0x80
_exc_lower_fiq:
    b panic_int

.balign 0x80
_exc_lower_serror:
    b panic_int
.balign 0x80

_exc_lower_32_sync:
    b panic_int
.balign 0x80
_exc_lower_32_irq:
    b panic_int
.balign 0x80
_exc_lower_32_fiq:
    b panic_int
.balign 0x80
_exc_lower_32_serror:
    b panic_int

