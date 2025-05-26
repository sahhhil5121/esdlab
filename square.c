// SQUARE

#include "lpc214x.h"
#include "stdint.h"

void delay_ms(uint16_t j)
{
    uint16_t x, i;
    for(i = 0; i < j; i++)
    {
        for(x = 0; x < 6000; x++);  /* loop to generate delay */
    }
}

int main (void)
{
    uint16_t value;
    uint16_t ti = 0;

    PINSEL1 = 0x00080000;     /* P0.25 as DAC output */
    IO0DIR = 0xFFFFFFFF;

    while(1)
    {
        DACR = 1023 << 6;
        delay_ms(10);
        DACR = 0;
        delay_ms(10);
    }
}
