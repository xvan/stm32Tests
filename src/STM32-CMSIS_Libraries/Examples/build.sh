arm-none-eabi-gcc -ggdb -Wall -O0 -mthumb -nostdlib -o blinker.o -I../CMSIS/  -c blinker.c
arm-none-eabi-gcc -ggdb -O0  -mthumb -mcpu=cortex-m3 -T../STM32F103C8TX_FLASH.ld -o blinker.elf  blinker.o startup.o


