ENTRY(_start)

MEMORY
{
    FLASH(rx) : ORIGIN = 0x00000000, LENGTH = 2048k
    RAM(rwx) : ORIGIN = 0x40000000, LENGTH = 256k
}

SECTIONS {
    .startup . : { boot.o(.text) } > FLASH
    .text : { *(.text) } > FLASH
    .data : { *(.data) } > RAM
    .bss : { *(.bss COMMON) } > RAM
    .stack : {
        . += 0x1000;
        . = ALIGN(8);
        stack_top = .;
    } > RAM

    /DISCARD/ :
	{
		*(.comment)
		*(.eh_frame)
		*(.note.gnu.build-id)
	} # from ToaruOS
}