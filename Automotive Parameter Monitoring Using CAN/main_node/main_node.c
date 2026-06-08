#include<LPC21xx.h>
#include "Lcd1.h"
#include "delay.h"
#include "types.h"
#include "defines.h"
#include "can.h"
#include "ds18b20.h"
#include "interrupts.h"

CANF txF;
CANF rxF;

extern int blinkleft;
extern int blinkright;

int main()
{
        int temp,fuel=0;
        Init_CAN1();
        Init_LCD();
        Enable_EINTs();
        txF.ID=1;
        txF.bfv.RTR=0;
        txF.bfv.DLC=1;
        while(1){
                cmdLCD(0x80);
                stringLCD(" SMART VEHICLE SYS  ");
                cmdLCD(0x94);
                stringLCD("TEMP :");
                temp=ReadTemp();
                if(temp==-1){
                        stringLCD("TEMP ERR");
                }else{
                        integerLCD(temp>>4);
                        charLCD(223);
                        stringLCD("C    ");
                }
                cmdLCD(0xD4);
                stringLCD("TURN:");
                cmdLCD(0x48);
                LIndicatorDisp();
                cmdLCD(0x40);
                RIndicatorDisp();
                cmdLCD(0xD4+13);
                charLCD(1);
                cmdLCD(0xD4+16);
                charLCD(0);
                cmdLCD(0x50);
                fuel1();
                cmdLCD(0x58);
                fuel2();
                cmdLCD(0x60);
                fuel3();
                cmdLCD(0x68);
                fuel4();
                if(blinkleft){
                        txF.Data1=1;
                        CAN1_Tx(txF);
                        cmdLCD(0xD4);
                        stringLCD("TURN: LEFT   ");
                        cmdLCD(0xD4+13);
                        charLCD(1);
                        cmdLCD(0xD4+16);
                        charLCD(0);
                        delay_ms(500);
                        cmdLCD(0xD4+13);
                        charLCD(' ');
                        delay_ms(500);
                }else if(blinkright){
                        txF.Data1=2;
                        CAN1_Tx(txF);
                        cmdLCD(0xD4);
                        stringLCD("TURN: RIGHT   ");
                        cmdLCD(0xD4+13);
                        charLCD(1);
                        cmdLCD(0xD4+16);
                        charLCD(0);
                        delay_ms(500);
                        cmdLCD(0xD4+16);
                        charLCD(' ');
                        delay_ms(500);
                }else{
                        txF.Data1=3;
                        CAN1_Tx(txF);

                        cmdLCD(0xD4);
                        stringLCD("TURN: OFF   ");

                        cmdLCD(0xD4+13);
                        charLCD(1);

                        cmdLCD(0xD4+16);
                        charLCD(0);
                }
                if(C1GSR&1){
                        CAN1_Rx(&rxF);
                        if(rxF.ID == 2) {
                                fuel=rxF.Data1;
                        }
                }
        cmdLCD(0xC0);
                stringLCD("TANK:");
                if(fuel<=25){
                        charLCD(2);
                        charLCD(' ');
                        charLCD(' ');
                        charLCD(' ');
                }
                else if(fuel<=50){
                        charLCD(2);
                        charLCD(3);
                        charLCD(' ');
                        charLCD(' ');
                }
                else if(fuel<=75){
                        charLCD(2);
                        charLCD(3);
                        charLCD(4);
                        charLCD(' ');
                }else{
                        charLCD(2);
                        charLCD(3);
                        charLCD(4);
                        charLCD(5);
                }
                cmdLCD(0xC9);
                integerLCD(fuel);
                stringLCD("%  ");
                delay_ms(10);
        }
}
