/*
 * File:   pwm.c
 * Author: gaurav
 *
 * Created on October 22, 2017, 7:20 PM
 */

#include <adc.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include <pwm.h>
#include "system.h"


void setPWMDuty(uint8_t channel, uint16_t duty) //duty in format of x10 --> 100% duty == 1000
{
    if ( channel == PWM_CHANNEL_1 )
    {
        usb_io_system.pwm1_duty = duty;
    }else
    {
        usb_io_system.pwm2_duty = duty;
    }
    
    setPWM10bit( channel, ( (uint32_t) (PR2 << 2) * duty ) / 1000);
}

inline void setPWM10bit(uint8_t channel , uint16_t value)
{
    value = value & 0x3FF;
    if ( channel == PWM_CHANNEL_1)
    {
        PWM1DCL = value << 6;
        PWM1DCH = value >> 2;
    }else
    {
        PWM2DCL = value << 6;
        PWM2DCH = value >> 2;       
    }
}


void setPWMFrequency(uint32_t frequency)
{
	if(frequency >2999 &&  frequency <11718)                //prescaler 64 , mimum frequency possible with 8bit pr2 is ~3Khz
	{		
			PR2 = ((750000/frequency)-1) & 0xFF;            //PR2= CLK/Freq with prescaler 64 clock is 750k
			T2CON= 0x06;			
	}else if(frequency  <46874)                             //requires prescaler 16 
	{
			PR2 = ((3000000/frequency)-1) & 0xFF;           //PR2= CLK/Freq with prescaler 16 clock is 3M
			T2CON= 0x05;
		
	}else if(frequency <=200000)                             //requires prescaler 4
	{
			PR2 =  ((12000000/frequency)-1) & 0xFF;         //PR2= CLK/Freq with prescaler 4 clock is 12M
			T2CON= 0x04;
	}
    usb_io_system.pwm_frequency = frequency;
}
/*********************************************************************
* Function: bool PWM_Enable(PWM_CHANNEL channel, PWM_CONFIGURATION configuration);
*
* Overview: Enables specified channel
*
* PreCondition: none
*
* Input: PWM_CHANNEL channel - the channel to enable
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool PWM_Enable(PWM_CHANNEL channel , bool en )
{
    
    T2CONbits.TMR2ON = 1;
    
    if(channel == PWM_CHANNEL_1 )
    {
        PWM1CONbits.PWM1OE = en;
        PWM1CONbits.PWM1EN = en;
    }else
    {
        PWM2CONbits.PWM2OE = en;
        PWM2CONbits.PWM2EN = en;        
    }
    
    return true;
}

/*********************************************************************
* Function: bool PWM_SetConfiguration(PWM_CONFIGURATION configuration)
*
* Overview: Configures the PWM module to specified setting
*
* PreCondition: none
*
* Input: PWM_CONFIGURATION configuration - the mode in which to run the PWM
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool PWM_SetConfiguration(PWM_CONFIGURATION configuration)
{
   if(configuration == PWM_CONFIGURATION_DEFAULT)
    {
        PWM1CON = 0; //active high , PWMx pin is disabled , PWM module disabled
        PWM1DCL = 0;
        PWM1DCH = 0x20;
        
        PWM2CON = 0; //active high , PWMx pin is disabled , PWM module disabled
        PWM2DCL = 0; 
        PWM2DCH = 0x20;
        
        TRISCbits.TRISC5 = 0;
        
        T2CON = 0; //timer off Prescaler 1 , Postscaler 1
        PR2 = 255;
        
        
        return true;
    }
   return false;
}
