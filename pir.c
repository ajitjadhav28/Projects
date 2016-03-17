/* 
 * File:   pir.c
 * Author: Ajit Jadhav
 *
 * Created on March 17, 2016, 3:51 AM
 */

#include <p18f46k22.h>
#include "adc.h"
#include "pir.h"

unsigned char readPIR(void)
{
    unsigned int r;
    initADC(1);
    r = readADC();
    if(r > 500)
        return 1;
    else
        return 0;
}