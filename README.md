# Secret development of Kifa system software

# Folders
- littlefs - a littlefs filesystem library (dont delete please.)
- bootrom - BootROM a first code what running on main ARMv9 CPU and load a flat binary (boot) from nand
- boot - Boot (after BootROM) a second code what running on ARMv9 CPU, which simply checks something and loading a secure monitor and loads kernel into specific address (noKASLR?) and provides addr into x30
- krnl - Normal kernel development
- sm - Secure Monitor - please ask to me if you know vulnerability

## Not protected by DMCA (yet™️)