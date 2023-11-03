.global _start

_start:
    b panic

panic:
    wfe
    nop
    b panic