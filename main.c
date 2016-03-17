/* Main.c file generated by New Project wizard
 * Author : Ajit Jadhav
 * Created:   Thu Mar 3 2016
 * Processor: PIC18F46K22
 * Compiler:  MPLAB C18
 */

#include <p18f46k22.h>
#include <delays.h>
#include <stdio.h>
#include "config.h"
#include "lcd.h"
#include "adc.h"
#include "pir.h"
#include "ultrasonic.h"
#include "ldr.h"
#include "led.h"


char line1[16];
char line2[16];
unsigned int t;

void lcdinit();
void lcdstring(unsigned char *);

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

void setBrightness(unsigned int i)
{
    VREFCON2 = i;
}
void main(void) {
    unsigned int resLDR;
    float resUS;
    short f;
    OSCCON = 0x76;
    VREFCON1 = 0xE0;
    msDelay(1000);
    lcdinit();
    lcdcmd(0x01);
    lcdcmd(0x80);
    f=0;
    while(1)
    {
        if(readPIR())
        {
            pirIndicate();
            resUS = readUltrasonic();
            while(resUS < 80.0)
            {
                eventL();
                resUS = readUltrasonic();
                sprintf(line1,"Distance = %f",resUS);
                lcdstring(line1);
            }
        }
    }
    
}