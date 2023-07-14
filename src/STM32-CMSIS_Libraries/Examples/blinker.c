#include "stm32f103xb.h"


void wait() {
    // Do some NOPs for a while to pass some time.
    int j;
    for (unsigned int i = 0; i < 2000000; i=i+1)
	j++; 
}


void main() {
    // Enable port C clock gate.
    *((volatile unsigned int *)0x40021018) |= (1 << 4);

    // Configure GPIO C pin 13 as output.
    *((volatile unsigned int *)0x40011004) = ((0x44444444 // The reset value
        & ~(0xfU << 20))  // Clear out the bits for pin 13
        |  (0x3U << 20)); // Set both MODE bits, leave CNF at 0

    while (1) {
        // Set the output bit.
        *((volatile unsigned int *)0x40011010) = (1U << 13);
        wait();
        // Reset it again.
        *((volatile unsigned int *)0x40011010) = (1U << 29);
        wait();
    }
}

void Reset_Handler(void)
{
        /* Branch to main function */
        main();

        /* Infinite loop */
	for(;;);
}

extern void _exit(int status)
{
        for (;;);
}

