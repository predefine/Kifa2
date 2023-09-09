GNULatestToolchain="https://developer.arm.com/-/media/Files/downloads/gnu/12.3.rel1/binrel/arm-gnu-toolchain-12.3.rel1-mingw-w64-i686-aarch64-none-elf.zip"
GNUToolchainFolder="./toolchain"
echo Checking to GNU Toolchain...

if [ -d $GNUToolchainFolder ]
then 
    echo OK
else
    echo Not found
    echo Downloading ARM Toolchain
    curl -o toolchain.zip -L $GNULatestToolchain
    mkdir $GNUToolchainFolder
    unzip ./toolchain.zip "arm-gnu-toolchain-*/*" -d "$GNUToolchainFolder"
    rm -rf toolchain.zip
    echo Restart script please.
    exit 1
fi

echo Building..

cd boot && chmod +x make.sh && ./make.sh && cd ..
cd krnl && chmod +x make.sh && ./make.sh && cd ..
cd sm && chmod +x make.sh && ./make.sh && cd ..
cd trusted_krnl && chmod +x make.sh && ./make.sh && cd ..