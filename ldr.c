#include <p18f46k22.h>
#include "adc.h"
#include "ldr.h"

unsigned int readLDR(void)
{
    initADC(0);
    return readADC();
}