#include <p18f46k22.h>
#include <delays.h>
#include "ultrasonic.h"

// Ultrasonic Module pin definations
#define US_TRIG_DIR TRISAbits.TRISA4
#define US_TRIG LATAbits.LATA4
#define US_ECHO_DIR TRISBbits.TRISB0
#define US_ECHO PORTBbits.RB0

void initUltrasonic(void)
{
    T0CON = 0x01;
    US_ECHO_DIR = 1;
    US_TRIG_DIR = 0;
    US_ECHO = 1;
    WPUBbits.WPUB0 = 1;
    return;
}

float readUltrasonic(void)
{
    unsigned int regL,regH,res;
    float r;
    TMR0H = 0;
    TMR0L = 0;
    US_TRIG = 1;
    Delay10TCYx(4);
    US_TRIG = 0;
    while(!US_ECHO);
    T0CONbits.TMR0ON = 1;
    while(US_ECHO);
    T0CONbits.TMR0ON = 0;
    regL = TMR0L;
    regH = TMR0H;
    res = (regH << 8) | regL;
    r = (float) (((res*0.000001)*34000)/2);
    if(r <= 400.0)
        return r;
    else 
        return 0;
}