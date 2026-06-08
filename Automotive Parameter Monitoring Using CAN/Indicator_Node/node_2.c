#include <LPC21xx.h>
#include "delay.h"
#include "can.h"

CANF rxF;

void leftshift()
{
        unsigned char n;
        while(1)
        {
                n=0x01;
                while(n)
                {
                        IOCLR0 = n;
                        delay_ms(200);
                        IOSET0 = n;
                        if(C1GSR & 1)
                        {
                                CAN1_Rx(&rxF);
                                if((rxF.ID==1) && (rxF.Data1 != 1))
                                {
                                        IOSET0 = 0xff;
                                        return;
                                }
                        }
                        n<<=1;
                }
                        IOSET0 = 0xff;
                        delay_ms(200);
        }
}

void rightshift()
{
        unsigned char n;
        while(1)
        {
                n=0x80;
                while(n)
                {
                        IOCLR0 = n;
                        delay_ms(200);
                        IOSET0 = n;
                        if(C1GSR & 1)
                        {
                                CAN1_Rx(&rxF);
                                if((rxF.ID==1) && (rxF.Data1 != 2))
                                {
                                        IOSET0 = 0xff;
                                        return;
                                }
                        }
                        n>>=1;
                }
                IOSET0 = 0xff;
                delay_ms(200);
        }
}
int main()
{
         Init_CAN1();
         IODIR0 |= 0xff;
         IOSET0 = 0xff;
         while(1)
         {
                if(C1GSR & 1)
                {
                        CAN1_Rx(&rxF);
                        if(rxF.ID == 1)
                        {
                                switch(rxF.Data1)
                                {
                                        case 1:
                                                leftshift();
                                                break;
                                        case 2:
                                                rightshift();
                                                break;
                                        default:
                                                IOSET0 = 0xff;
                                                break;
                                }
                        }
                }

         }
}
