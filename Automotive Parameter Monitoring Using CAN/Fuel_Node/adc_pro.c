#include <LPC21xx.h>
#include "delay.h"
#include "adc_defines.h"

void Init_ADC(unsigned char pin){
        PINSEL1&=~(1<<pin);
        PINSEL1|=(1<<pin);
        ADCR=((1<<PDN_BIT)|(CLKDIV<<CLKDIV_BITS));
}

void Read_ADC(int chNo,float *eAR,int *adcDval){
        ADCR&=0xFFFFFF00;
        ADCR|=((1<<START_BIT)|(1<<chNo));
        delay_us(3);
        while(((ADDR>>DONE_BIT)&1)==0);
        ADCR&=~(1<<START_BIT);
        *adcDval=((ADDR>>DIGITAL_CONV_DATA)&1023);
        *eAR=*adcDval*(3.3/1023);
}
