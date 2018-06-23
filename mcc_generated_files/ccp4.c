/**
  CCP4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp4.c

  @Summary
    This is the generated driver implementation file for the CCP4 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for CCP4.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1937
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
         MPLAB 	          :  MPLAB X 4.15
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "ccp4.h"

/**
  Section: Compare Module APIs:
*/

void CCP4_Initialize(void)
{
    // Set the CCP4 to the options selected in the User Interface
	
	// CCP4M Setoutput; DC4B 0; 
	CCP4CON = 0x08;    
	
	// CCPR4L 0; 
	CCPR4L = 0x00;    
	
	// CCPR4H 0; 
	CCPR4H = 0x00;    

    
    // Clear the CCP4 interrupt flag
    PIR3bits.CCP4IF = 0;

    // Enable the CCP4 interrupt
    PIE3bits.CCP4IE = 1;
}

void CCP4_SetCompareCount(uint16_t compareCount)
{
    CCP_PERIOD_REG_T module;
    
    // Write the 16-bit compare value
    module.ccpr4_16Bit = compareCount;
    
    CCPR4L = module.ccpr4l;
    CCPR4H = module.ccpr4h;
}

void CCP4_CompareISR(void)
{
    // Clear the CCP4 interrupt flag
    PIR3bits.CCP4IF = 0;
}
/**
 End of File
*/