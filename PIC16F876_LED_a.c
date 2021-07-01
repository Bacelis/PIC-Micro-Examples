#include <16F876.h>
#fuses XT,NOWDT
#use delay( clock = 4000000)    //Reloj de 4 MHz
#BYTE TRISB = 0x86              //TRISB en 86h
#BYTE PORTB = 0x06              //PORTB en 06h
#BYTE OPTION_REG = 0x81         //OPTION_REG en 81h
void main()
{
    bit_clear(OPTION_REG,7);    //Habilitar Pull-up
    bit_set(TRISB,0);           //B0 Entrada
    bit_clear(TRISB,1);         //B1 Salida
    bit_clear(PORTB,1);         //Apaga LED
    while(1)
    {
        if(bit_test(PORTB,0) == 1)    //Si RB0 es 1, apaga LED
            bit_clear(PORTB,1);
        else
            bit_set(PORTB,1);        //Si RB0 es 0, enciende LED
    }
}
