#!/usr/bin/sh
echo Testing a build

echo Building a NAND

echo OK # nothing 

echo Run!

qemu-system-aarch64 -machine virt,secure=on -cpu cortex-a76 -bios bootrom/out/boot.bin -serial stdio
