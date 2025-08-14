
#include "system.h"
#include <xc.h>
#include <stdint.h>
#include "timer1.h"

void initTimer1()
{
        // Configure T1CON Register
    T1CONbits.TMR1CS = 0b00;     // Clock source = FOSC/4
    T1CONbits.T1CKPS = 0b10;     // Prescaler = 1:4 // with 48M FOSC, make 333.333ns LSbit
    T1CONbits.T1OSCEN = 0;       // Dedicated Timer1 oscillator disabled
    T1CONbits.nT1SYNC = 1;       // Do not synchronize external clock input (OK even for internal)
    T1CONbits.TMR1ON = 1;        // Turn on Timer1

    // Optional: Clear the Timer1 counter registers
    TMR1H = 0;
    TMR1L = 0;

    // T1GCON (Gate Control) Configuration - not using gate, but ensure gate is disabled
    T1GCONbits.TMR1GE = 0;       // Timer1 counts regardless of gate
}
