ld="$GNUToolchainBinaries/aarch64-none-elf-ld"
gcc="$GNUToolchainBinaries/aarch64-none-elf-gcc"
as="$GNUToolchainBinaries/aarch64-none-elf-as"
objcopy="$GNUToolchainBinaries/aarch64-none-elf-objcopy"

cd out

# Compila!
$as ../src/boot.s -o boot.o 

for f in ../src/*.c ; do 
    echo $f
    $gcc -ffreestanding -Wall -Wextra -Wpedantic -Werror -I ../incl -I ../../general/include -c $f -o "${f%.c}.o" 
done

mv ../src/*.o . 

$ld -nostdlib -T../src/link.lds *.o -o boot.elf # ура

$objcopy -O binary boot.elf boot.bin

echo ... boot.bin ...

cd ..

