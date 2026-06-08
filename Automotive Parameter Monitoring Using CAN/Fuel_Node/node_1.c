#include <LPC21xx.h>
#include "adc.h"
#include "adc_defines.h"
#include "delay.h"
#include "can.h"

int adcDval;
float eAR;

CANF txF;
volatile int t;
int main(){
        Init_CAN1();
        Init_ADC(AIN1_0_27);
        txF.ID=2;
        txF.bfv.RTR=0;
        txF.bfv.DLC=1;
        while(1){
					Read_ADC(1,&eAR,&adcDval);
                if(adcDval>MAX_VAL)
                        adcDval=MAX_VAL;
                else if(adcDval<MIN_VAL)
                        adcDval=MIN_VAL;
                t=(((adcDval-MIN_VAL)*100)/(MAX_VAL-MIN_VAL));
                txF.Data1=t;
                CAN1_Tx(txF);
                delay_ms(500);
        }
}
