#include <p18f46k22.h>
#include <delays.h>
#include "led.h"

// Green LED pin 
#define LED_DIR TRISBbits.TRISB5 
#define LED LATBbits.LATB5

void eventL(void)
{
    LED_DIR = 1;
    LED = 1;
    Delay10KTCYx(10);
    LED = 0;
    Delay10KTCYx(10);
    LED = 1;
    Delay10KTCYx(10);
    LED = 0;
    Delay10KTCYx(10);
}

void pirIndicate(void)
{
    LED_DIR = 1;
    LED = 1;
    Delay10KTCYx(20);
    LED = 0;
    Delay10KTCYx(20);
}