#!/usr/bin/sh
GNULatestToolchain="https://developer.arm.com/-/media/Files/downloads/gnu/12.3.rel1/binrel/arm-gnu-toolchain-12.3.rel1-x86_64-aarch64-none-elf.tar.xz"
GNUToolchainFolder="./toolchain"
export GNUToolchainBinaries="$(pwd)/toolchain/bin"
echo Checking to GNU Toolchain...

if [ -d $GNUToolchainFolder ]
then 
    echo OK
else
    echo Not found
    echo Downloading ARM Toolchain
    curl -o toolchain.tar.xz -L $GNULatestToolchain
    mkdir $GNUToolchainFolder
    tar -xf toolchain.tar.xz -C ./toolchain
    mv -v ./toolchain/arm-gnu-toolchain-*/* ./toolchain/
    rm -rf toolchain.tar.xz
    echo Restart script please.
    exit 1
fi

echo Building..

cd bootrom && chmod +x make.sh && ./make.sh && cd ..
cd krnl && chmod +x make.sh && ./make.sh && cd ..
cd sm && chmod +x make.sh && ./make.sh && cd ..
cd trusted_krnl && chmod +x make.sh && ./make.sh && cd ..
