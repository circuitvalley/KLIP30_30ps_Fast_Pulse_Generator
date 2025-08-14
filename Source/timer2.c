
#include <xc.h>
#include <stdint.h>

void initTimer2() 
{
    T2CONbits.T2CKPS = 0x01; //presacler /4 , Timer is fed with 12M (48M/4) again /4 will have 3M ->333ns/ bit
    T2CONbits.TMR2ON = 1;
}
