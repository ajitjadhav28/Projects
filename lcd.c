/* 
 * File:   lcd.c
 * Author: Ajit Jadhav
 *
 * Created on 14 March, 2016, 6:39 PM
 */
#include <p18f46k22.h>
#include <delays.h>
#include "lcd.h"

#define RS LATEbits.LATE0
#define RW LATEbits.LATE1
#define E  LATEbits.LATE2

char lcdBuf[16];

void lcdcmd1(unsigned char command)
{
	LATDbits.LATD0 = (command) & 0x1;		
	LATDbits.LATD1 = (command >> 1 ) & 0x1;	
	LATDbits.LATD2 = (command >> 2)  & 0x1;	
	LATDbits.LATD3 = (command >> 3 ) & 0x1;	
	E=0;
	RS=0;
	Delay1KTCYx(2);
	E=1;
	Delay1KTCYx(2);
	E=0;
	Delay1KTCYx(2);
}

void lcdcmd(unsigned char value)
{
    char lowernibble=0,highernibble=0;
	lowernibble = value & 0x0f;								
	highernibble = value & 0xf0;						
	highernibble = (highernibble  >>4) & 0x0f ;	
	lcdcmd1(highernibble);
	lcdcmd1(lowernibble);
	Delay1KTCYx(2);
}

void lcddata1(unsigned char data)
{
	LATDbits.LATD0 = (data) & 0x1;		    
	LATDbits.LATD1 = (data >> 1 ) & 0x1;	
	LATDbits.LATD2 = (data >> 2)  & 0x1;	
	LATDbits.LATD3 = (data >> 3 ) & 0x1;	
	RS=1;
	Delay1KTCYx(2);
	E = 0;
	Delay1KTCYx(2);
	E = 1;
	Delay1KTCYx(2);
	E = 0;
	Delay1KTCYx(2);
}

void lcddata(unsigned char value)
{
    char lowernibble=0,highernibble=0;

	lowernibble  = value & 0x0f;						
	highernibble = value & 0xf0;					
	highernibble = (highernibble  >>4) & 0x0f ;		
	lcddata1(highernibble);
	lcddata1(lowernibble);
	Delay1KTCYx(2);
}

void lcdstring(unsigned char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
      lcddata(str[i]);
      i++;
    }
}

void lcdinit()
{
	TRISEbits.RE0 = 0	;	
	TRISEbits.RE1 = 0	;	
	TRISDbits.RD0 = 0	;	
	TRISDbits.RD1 = 0	;	
	TRISDbits.RD2 = 0	;	
	TRISDbits.RD3 = 0	;	
	TRISEbits.TRISE2 = 0;
            
	PORTEbits.RE0 =  0;
	PORTEbits.RE1 =  0;
    PORTEbits.RE2 = 0;
	PORTDbits.RD0 =  0;
	PORTDbits.RD1 =  0;
	PORTDbits.RD2 =  0;
	PORTDbits.RD3 =  0;
    
	Delay10KTCYx(80);
	lcdcmd(0x03);
	Delay10KTCYx(16);
	lcdcmd(0x03);
	Delay10KTCYx(16);
	lcdcmd(0x03);
	Delay10KTCYx(16);
	lcdcmd(0x02);
	Delay10KTCYx(16);
	lcdcmd(0x28);
	lcdcmd(0x08);
	lcdcmd(0x0c);
	lcdcmd(0x06);
}
