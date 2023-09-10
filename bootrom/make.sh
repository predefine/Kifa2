ld="$GNUToolchainBinaries/aarch64-none-elf-ld"
gcc="$GNUToolchainBinaries/aarch64-none-elf-gcc"
as="$GNUToolchainBinaries/aarch64-none-elf-as"

cd out

# Compila!
$as ../src/boot.s -o boot.o 

cd ..

