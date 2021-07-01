#include <16F876.h>
#fuses XT,NOWDT
#use delay( clock = 4000000)
#use fast_io(B)
void main()
{
    port_b_pullups (TRUE);
    set_tris_B(0x01);
    output_low(PIN_B1);
    while (1)
    {
        if (input(PIN_B0) == 1)
            output_low(PIN_B1);
        else
            output_high(PIN_Bl);
    }
}
