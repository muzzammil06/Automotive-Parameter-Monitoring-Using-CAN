#include<LPC21xx.h>
#include "delay.h"
#include "types.h"
#include "defines.h"
#include "Lcd1.h"
#define CAT 0xff
#define RS 4
#define RW 6
#define EN 5
void Init_LCD(void){
        IODIR0|=((CAT<<8)|(1<<RS)|(1<<RW)|(1<<EN));
        delay_ms(20);
        cmdLCD(0x30);
        delay_ms(10);
        cmdLCD(0x30);
        delay_ms(1);
        cmdLCD(0x30);
        delay_ms(1);
        cmdLCD(0x38);
        cmdLCD(0x10);
        cmdLCD(0x01);
        cmdLCD(0x06);
        cmdLCD(0x0C);
}

void cmdLCD(u8 cmd){
        IOCLR0=1<<RS;
        dispLCD(cmd);
}
void charLCD(u8 data){
        IOSET0=1<<RS;
        dispLCD(data);
}
void dispLCD(u8 val){
        IOCLR0=1<<RW;
        WRITEBYTE(IOPIN0,8,val);
        IOSET0=1<<EN;
        delay_us(1);
        IOCLR0=1<<EN;
        delay_ms(2);
}
void stringLCD(char *ptr){
        while(*ptr)
                charLCD(*ptr++);
}
void integerLCD(s32 data){
        u8 a[30];
        int i=0,n;
        if(data==0)
                charLCD('0');
        if(data<0){
                data=-data;
                charLCD('-');
        }
        while(data){
                a[i++]=(data%10)+48;
                data/=10;
        }
        for(n=i-1;n>=0;n--)
                charLCD(a[n]);
}
void floatLCD(f32 f){
        int num1=f,num2,n=0;
        f=f-num1;
        while(n++<6)
                f*=10;
        num2=f;
        integerLCD(num1);
        charLCD('.');
        integerLCD(num2);
}

void RIndicatorDisp(){
        int i;
        char LUT[]={0x04,0x06,0x1F,0x1F,0x06,0x04,0x00,0x00};
        for(i=0;i<8;i++){
                charLCD(LUT[i]);
        }
}

void LIndicatorDisp(){
        int i;
        char LUT[]={0x04,0x0C,0x1F,0x1F,0x0C,0x04,0x00,0x00};
        for(i=0;i<8;i++){
                charLCD(LUT[i]);
        }
}

void fuel1(){
        int i;
        char LUT[]={0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x00};
        for(i=0;i<8;i++){
                charLCD(LUT[i]);
        }
}

void fuel2(){
        int i;
        char LUT[]={0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00};
        for(i=0;i<8;i++){
                charLCD(LUT[i]);
        }
}

void fuel3(){
         int i;
        char LUT[]={0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x00};
        for(i=0;i<8;i++){
                charLCD(LUT[i]);
        }
}

void fuel4(){
        int i;
        char LUT[]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00};
        for(i=0;i<8;i++){
                charLCD(LUT[i]);
        }
}
