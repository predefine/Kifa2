GNULatestToolchain="https://developer.arm.com/-/media/Files/downloads/gnu/12.3.rel1/binrel/arm-gnu-toolchain-12.3.rel1-mingw-w64-i686-aarch64-none-elf.zip"
GNUToolchainFolder="./toolchain"
echo Checking to GNU Toolchain...


echo Building..

cd boot && chmod +x make.sh && ./make.sh && cd ..