/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _PWM_H
#define	_PWM_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define PWM_DEFAULT_VALUE 128

typedef enum
{ 
    PWM_CHANNEL_1 = 1,
    PWM_CHANNEL_2 = 2,
} PWM_CHANNEL;

typedef enum
{
    PWM_CONFIGURATION_DEFAULT
} PWM_CONFIGURATION;

void setPWMFrequency(uint32_t frequency);

inline void setPWM10bit(uint8_t channel, uint16_t value);
void setPWMDuty(uint8_t channel, uint16_t duty); //duty in format of x10 --> 100% duty == 1000

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
bool PWM_Enable(PWM_CHANNEL channel , bool en );

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
bool PWM_SetConfiguration(PWM_CONFIGURATION configuration);

#endif	/* XC_HEADER_TEMPLATE_H */

