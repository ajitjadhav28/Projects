/*
 * File:   adc.c
 * Author: Ajit Jadhav
 *
 * Created on 16 March, 2016, 12:49 PM
 */

#include <p18f46k22.h>
#include <delays.h>
#include "adc.h"

void initADC(unsigned char ch)
{
  if(ch < 28)
    ADCON0 |= (ch << 2);
  ADCON2 = 0xAD;
  ADCON0bits.ADON = 1;
  return;
}

unsigned int readADC(void)
{
  unsigned int l,h;
  ADCON0bits.GO_DONE = 1;
  while(ADCON0bits.GO_DONE);
  l = ADRESL;
  h = ADRESH;
  return ((int) (h<<8)|l);
}