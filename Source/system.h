/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>


#include "io_mapping.h"
#include "fixed_address_memory.h"

#define VERSION_MAJOR 1
#define VERSION_MINOR 4

//Internal oscillator option setting.  Uncomment if using HFINTOSC+active clock 
//tuning, instead of a crystal.  
//#define USE_INTERNAL_OSC        //Make sure 1uF-8uF extra capacitance is added on VDD net
                                //to smooth VDD ripple from MAX3232 chip, before using this
                                //with the original Low Pin Count USB Development Kit board.
                                //If using the latest version of the board, this is not
                                //required and is already present.

typedef enum aux_ctrl_e
{
    AUX_SYNC_OUT,
    AUX_SYNC_IN,
    AUX_EXT_REF_IN
}aux_ctrl_t;

#define SANITY_WORD 0xAA55

typedef union AD4351_u
{
    struct
    {
        uint32_t        reg[6];             //24 bytes
        uint32_t        frequency;          // 4 bytes
        uint32_t        ref_freq;           // 4 bytes
        uint32_t        start_freq;         // 4 bytes
        uint32_t        stop_freq;          // 4 bytes
        uint32_t        step_freq;          // 4 bytes
        uint16_t        step_ms;            // 2 bytes
        uint16_t        aux_select;         // 2 byte
        uint8_t         isSweepEnabled;     // 1 byte 
        uint8_t         isStartOnBoot;      // 1 byte 
        uint8_t         isStartOfSweep;     // 1 byte 
        uint8_t         flashWritePending;  // 1 byte
        uint8_t         flashReadPending;   // 1 byte
        uint16_t        sanityCheck;        // 2 byte to indicate if flash is ever written
        uint8_t         padding[1];         // 1 byte 
    };
    uint8_t mem[56];
}ADF4351_reg_t;

typedef struct deviceinfo_s
{
    uint32_t   serialNumber;    //4bytes
    uint8_t    padding[52]; //flash block is 56 byte each
}deviceinfo_t;
        
extern char   __BUILD_DATE;
extern char   __BUILD_NUMBER;

extern ADF4351_reg_t adf4351System;
extern deviceinfo_t deviceinfo;

#define MAIN_RETURN void

/*** System States **************************************************/
typedef enum
{
    SYSTEM_STATE_USB_START,
    SYSTEM_STATE_USB_SUSPEND,
    SYSTEM_STATE_USB_RESUME
} SYSTEM_STATE;

/*********************************************************************
* Function: void SYSTEM_Initialize( SYSTEM_STATE state )
*
* Overview: Initializes the system.
*
* PreCondition: None
*
* Input:  SYSTEM_STATE - the state to initialize the system into
*
* Output: None
*
********************************************************************/
void SYSTEM_Initialize( SYSTEM_STATE state );

 void makeSerialNumber();
/*********************************************************************
* Function: void SYSTEM_Tasks(void)
*
* Overview: Runs system level tasks that keep the system running
*
* PreCondition: System has been initalized with SYSTEM_Initialize()
*
* Input: None
*
* Output: None
*
********************************************************************/
//void SYSTEM_Tasks(void);
#define SYSTEM_Tasks()

#endif //SYSTEM_H
