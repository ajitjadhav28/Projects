/*
 * File:   main.c
 * Author: root
 *
 * Created on March 13, 2016, 1:38 PM
 */


#include <p18f46k22.h>
#include "config.h"
#include <delays.h>

// LCD Control Bits
#define RS PORTEbits.RE0
#define RW PORTEbits.RE1
#define E  PORTEbits.RE2
#define LCD_PORT PORTD
#define LCD_BUSY_PIN PORTDbits.RD3

void msDelay(unsigned int i)
{
    for(; i>0; i--)
        Delay1KTCYx(4);
}

void usDelay(unsigned int i)
{
    for(; i>0; i--)
    {
        Nop();
        Nop();
        Nop();
        Nop();
    }
}

void lcdStrobe(void)
{
    E = 1;
    usDelay(1);
    E = 0;
}

void lcdBusy(void)
{
    TRISDbits.RD3 = 1;
    RS = 0;
    RW = 1;
    do
    {
        E = 0;
        msDelay(1);
        E = 1;
    }while(LCD_BUSY_PIN);
    TRISDbits.RD3 = 0;
}

void lcdCmd(char c)
{
    RS = 0;
    lcdBusy();
    LCD_PORT = (c >> 4);
    lcdStrobe();
    lcdBusy();
    LCD_PORT = c;
    lcdStrobe();
}

void lcdData(char d)
{
    RS = 1;
    lcdBusy();
    LCD_PORT = (d >> 4);
    lcdStrobe();
    lcdBusy();
    LCD_PORT = d;
    lcdStrobe();
}

void lcdString(char *str)
{
    while(*str != '\0')
    {
        lcdData(*str++);
    }
}

void lcdInit(void)
{
    msDelay(1000);
    RS = 0;
    LCD_PORT = 0x03;
    lcdStrobe();
    msDelay(100);
    LCD_PORT = 0x03;
    lcdStrobe();
    msDelay(100);
    LCD_PORT = 0x03;
    lcdStrobe();
    msDelay(100);
    lcdCmd(0x20);
    lcdCmd(0x28);
    lcdCmd(0x0c);
    lcdCmd(0x01);
    lcdCmd(0x06);
}

void main(void) {
    OSCCON = 0x76;
    msDelay(100);
    TRISD = 0;
    TRISB = 0;
    PORTBbits.RB5 = 1;
    TRISE = 0;
    lcdInit();
    lcdData('A');
    msDelay(1);
    lcdData('J');
    msDelay(1);
    PORTBbits.RB5 = 0;
    while(1)
    {
        PORTBbits.RB5 = 1;
        msDelay(500);
        PORTBbits.RB5 = 0;
        msDelay(500);
    }
}
