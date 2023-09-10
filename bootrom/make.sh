ld="$GNUToolchainBinaries/aarch64-none-elf-ld"
gcc="$GNUToolchainBinaries/aarch64-none-elf-gcc"
as="$GNUToolchainBinaries/aarch64-none-elf-as"

cd out

# Compila!
$as ../src/boot.s -o boot.o 

for f in ../src/*.c ; do 
    echo $f
    $gcc -ffreestanding -I ../incl -c $f -o "${f%.c}.o" 
done

mv ../src/*.o . # индусы проснулись изза ебанутого кода

$ld -nostdlib -T../src/link.lds *.o -o boot.elf # ура

cd ..

