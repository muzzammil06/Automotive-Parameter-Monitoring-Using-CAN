#include <LPC21xx.h>
#include "interrupts.h"
volatile int flag1=1;
volatile int flag2=1;

volatile int blinkright;
volatile int blinkleft;

void eint0_isr(void) __irq
{
        if(flag1){
                blinkleft=1;
                blinkright=0;
                flag1=0;
                flag2=1;
        }else{
                blinkright=0;
                blinkleft=0;
                flag1=1;
                flag2=1;
        }
        EXTINT=1<<0;
        VICVectAddr=0;
}

void eint1_isr(void) __irq
{
        if(flag2){
                blinkright=1;
                blinkleft=0;
                flag2=0;
                flag1=1;

        }else{
                blinkright=0;
                blinkleft=0;
                flag2=1;
                flag1=1;
        }
        EXTINT=1<<1;
        VICVectAddr=0;
}

void Enable_EINTs(void){
        PINSEL0=((PINSEL0&~(3<<6))|(3<<6));
        PINSEL1=((PINSEL1&~(3<<0))|(1<<0));
        VICIntEnable = ((1<<EINT0_VIC_CHNO)|(1<<EINT1_VIC_CHNO));
        VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;
        VICVectAddr0=(unsigned int) eint0_isr;
        VICVectCntl1=(1<<5)|EINT1_VIC_CHNO;
        VICVectAddr1=(unsigned int) eint1_isr;
        EXTMODE =((1<<0)|(1<<1));
}
