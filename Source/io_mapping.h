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
#include "system.h"

#define BUTTON_USB_DEVICE_HID_CUSTOM            BUTTON_S1
#define LED_USB_DEVICE_STATE                    LED_D1
#define LED_USB_DEVICE_HID_CUSTOM               LED_D2

#define DIO0_PORT       PORTAbits.RA5
#define DIO1_PORT       PORTAbits.RA4
#define DIO2_PORT       PORTAbits.RA3
#define DIO3_PORT       PORTCbits.RC5
#define DIO4_PORT       PORTCbits.RC4
#define DIO5_PORT       PORTCbits.RC3
#define DIO6_PORT       PORTCbits.RC6
#define DIO7_PORT       PORTCbits.RC7
#define DIO8_PORT       PORTCbits.RC0
#define DIO9_PORT       PORTCbits.RC1
#define DIO10_PORT      PORTCbits.RC2
#define DIO11_PORT      PORTBbits.RB4
#define DIO12_PORT      PORTBbits.RB5
#define DIO13_PORT      PORTBbits.RB6
#define DIO14_PORT      PORTBbits.RB7


#define DIO0_LAT        LATAbits.LATA5
#define DIO1_LAT        LATAbits.LATA4
#define DIO2_LAT        0              //this pin input only
#define DIO3_LAT        LATCbits.LATC5
#define DIO4_LAT        LATCbits.LATC4
#define DIO5_LAT        LATCbits.LATC3
#define DIO6_LAT        LATCbits.LATC6
#define DIO7_LAT        LATCbits.LATC7
#define DIO8_LAT        LATCbits.LATC0
#define DIO9_LAT        LATCbits.LATC1
#define DIO10_LAT       LATCbits.LATC2
#define DIO11_LAT       LATBbits.LATB4
#define DIO12_LAT       LATBbits.LATB5
#define DIO13_LAT       LATBbits.LATB6
#define DIO14_LAT       LATBbits.LATB7
    
#define DIO0_TRIS       TRISAbits.TRISA5
#define DIO1_TRIS       TRISAbits.TRISA4
#define DIO2_TRIS       0                   //this pin input only
#define DIO3_TRIS       TRISCbits.TRISC5
#define DIO4_TRIS       TRISCbits.TRISC4
#define DIO5_TRIS       TRISCbits.TRISC3
#define DIO6_TRIS       TRISCbits.TRISC6
#define DIO7_TRIS       TRISCbits.TRISC7
#define DIO8_TRIS       TRISCbits.TRISC0
#define DIO9_TRIS       TRISCbits.TRISC1
#define DIO10_TRIS      TRISCbits.TRISC2
#define DIO11_TRIS      TRISBbits.TRISB4
#define DIO12_TRIS      TRISBbits.TRISB5
#define DIO13_TRIS      TRISBbits.TRISB6
#define DIO14_TRIS      TRISBbits.TRISB7


#define ANIN0_ANSEL     ANSELAbits.ANSA4
#define ANIN1_ANSEL     ANSELCbits.ANSC3
#define ANIN2_ANSEL     ANSELCbits.ANSC6
#define ANIN3_ANSEL     ANSELCbits.ANSC7
#define ANIN4_ANSEL     ANSELCbits.ANSC0
#define ANIN5_ANSEL     ANSELCbits.ANSC1
#define ANIN6_ANSEL     ANSELBbits.ANSB4
#define ANIN7_ANSEL     ANSELBbits.ANSB5

#define ANIN0_TRIS     TRISAbits.TRISA4
#define ANIN1_TRIS     TRISCbits.TRISC3
#define ANIN2_TRIS     TRISCbits.TRISC6
#define ANIN3_TRIS     TRISCbits.TRISC7
#define ANIN4_TRIS     TRISCbits.TRISC0
#define ANIN5_TRIS     TRISCbits.TRISC1
#define ANIN6_TRIS     TRISBbits.TRISB4
#define ANIN7_TRIS     TRISBbits.TRISB5


#define ALT_PWM1_MASK       1 << 3    // io 3
#define ALT_PWM2_MASK       1 << 6    // io 3
#define ALT_DAC_MASK        1 << 10    // io 10 , in byte 2

