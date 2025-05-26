//Sine

#include "lpc214x.h"
#include "stdint.h"

void delay_ms(uint16_t j)
{
    uint16_t x, i;
    for (i = 0; i < j; i++) {
        for (x = 0; x < 6000; x++) {
           
        }
    }
}

int main (void)
{
    uint16_t value;
    uint16_t i = 0;
    uint16_t sintable[64] = {
        512, 562, 611, 660, 707, 753, 796, 836, 873, 907, 937, 963, 984,
        1001, 1013, 1021, 1023, 1021, 1013, 1001, 984, 963, 937, 907, 873, 836, 796, 753, 707, 660,
        611, 562, 512, 461, 412, 363, 316, 270, 227, 187, 150, 116, 86, 60, 39, 22, 10, 2, 0, 2, 10,
        22, 39, 60, 86, 116, 150, 187, 227, 270, 316, 363, 412, 461
    };

    PINSEL1 = 0x00080000;  /* P0.25 as DAC output */
    IO0DIR = 0xFFFFFFFF;

    while (1)
    {
        while (i < 64)
        {
            value = (sintable[i] << 6);
            DACR = value;
            delay_ms(1);
            i++;
        }
        i = 0;
    }
}
