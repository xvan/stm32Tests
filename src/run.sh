arm-none-eabi-gcc -ggdb -Wall -O0 -mthumb -nostdlib -o main.o -I../CMSIS/  -c main.c
arm-none-eabi-gcc -ggdb -O0  -mthumb -mcpu=cortex-m3 -Wl,--gc-sections -Tlinker.ld -o main.elf main.o


