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
