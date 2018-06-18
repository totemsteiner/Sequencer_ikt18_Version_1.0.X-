/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0


// get/set POT_LED aliases
#define POT_LED_TRIS                 TRISAbits.TRISA1
#define POT_LED_LAT                  LATAbits.LATA1
#define POT_LED_PORT                 PORTAbits.RA1
#define POT_LED_ANS                  ANSELAbits.ANSA1
#define POT_LED_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POT_LED_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POT_LED_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POT_LED_GetValue()           PORTAbits.RA1
#define POT_LED_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POT_LED_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POT_LED_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define POT_LED_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set S0 aliases
#define S0_TRIS                 TRISAbits.TRISA2
#define S0_LAT                  LATAbits.LATA2
#define S0_PORT                 PORTAbits.RA2
#define S0_ANS                  ANSELAbits.ANSA2
#define S0_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define S0_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define S0_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define S0_GetValue()           PORTAbits.RA2
#define S0_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define S0_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define S0_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define S0_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set S1 aliases
#define S1_TRIS                 TRISAbits.TRISA3
#define S1_LAT                  LATAbits.LATA3
#define S1_PORT                 PORTAbits.RA3
#define S1_ANS                  ANSELAbits.ANSA3
#define S1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define S1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define S1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define S1_GetValue()           PORTAbits.RA3
#define S1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define S1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define S1_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define S1_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set S2 aliases
#define S2_TRIS                 TRISAbits.TRISA4
#define S2_LAT                  LATAbits.LATA4
#define S2_PORT                 PORTAbits.RA4
#define S2_ANS                  ANSELAbits.ANSA4
#define S2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define S2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define S2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define S2_GetValue()           PORTAbits.RA4
#define S2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define S2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define S2_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define S2_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)



// get/set LED_S2 aliases
#define LED_S2_TRIS                 TRISAbits.TRISA7
#define LED_S2_LAT                  LATAbits.LATA7
#define LED_S2_PORT                 PORTAbits.RA7
#define LED_S2_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED_S2_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED_S2_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED_S2_GetValue()           PORTAbits.RA7
#define LED_S2_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED_S2_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set ENC_A aliases
#define ENC_A_TRIS                 TRISBbits.TRISB0
#define ENC_A_LAT                  LATBbits.LATB0
#define ENC_A_PORT                 PORTBbits.RB0
#define ENC_A_WPU                  WPUBbits.WPUB0
#define ENC_A_ANS                  ANSELBbits.ANSB0
#define ENC_A_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define ENC_A_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define ENC_A_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define ENC_A_GetValue()           PORTBbits.RB0
#define ENC_A_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define ENC_A_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define ENC_A_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define ENC_A_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define ENC_A_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define ENC_A_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set ENC_B aliases
#define ENC_B_TRIS                 TRISBbits.TRISB1
#define ENC_B_LAT                  LATBbits.LATB1
#define ENC_B_PORT                 PORTBbits.RB1
#define ENC_B_WPU                  WPUBbits.WPUB1
#define ENC_B_ANS                  ANSELBbits.ANSB1
#define ENC_B_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define ENC_B_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define ENC_B_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define ENC_B_GetValue()           PORTBbits.RB1
#define ENC_B_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define ENC_B_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define ENC_B_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define ENC_B_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define ENC_B_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define ENC_B_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set ENC_SW aliases
#define ENC_SW_TRIS                 TRISBbits.TRISB2
#define ENC_SW_LAT                  LATBbits.LATB2
#define ENC_SW_PORT                 PORTBbits.RB2
#define ENC_SW_WPU                  WPUBbits.WPUB2
#define ENC_SW_ANS                  ANSELBbits.ANSB2
#define ENC_SW_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define ENC_SW_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define ENC_SW_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define ENC_SW_GetValue()           PORTBbits.RB2
#define ENC_SW_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define ENC_SW_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define ENC_SW_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define ENC_SW_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define ENC_SW_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define ENC_SW_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISBbits.TRISB3
#define SW1_LAT                  LATBbits.LATB3
#define SW1_PORT                 PORTBbits.RB3
#define SW1_WPU                  WPUBbits.WPUB3
#define SW1_ANS                  ANSELBbits.ANSB3
#define SW1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SW1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SW1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SW1_GetValue()           PORTBbits.RB3
#define SW1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SW1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SW1_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set LED_SW1 aliases
#define LED_SW1_TRIS                 TRISBbits.TRISB4
#define LED_SW1_LAT                  LATBbits.LATB4
#define LED_SW1_PORT                 PORTBbits.RB4
#define LED_SW1_WPU                  WPUBbits.WPUB4
#define LED_SW1_ANS                  ANSELBbits.ANSB4
#define LED_SW1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LED_SW1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LED_SW1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LED_SW1_GetValue()           PORTBbits.RB4
#define LED_SW1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LED_SW1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LED_SW1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LED_SW1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LED_SW1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define LED_SW1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set Clock_In aliases
#define Clock_In_TRIS                 TRISBbits.TRISB5
#define Clock_In_LAT                  LATBbits.LATB5
#define Clock_In_PORT                 PORTBbits.RB5
#define Clock_In_WPU                  WPUBbits.WPUB5
#define Clock_In_ANS                  ANSELBbits.ANSB5
#define Clock_In_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define Clock_In_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define Clock_In_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define Clock_In_GetValue()           PORTBbits.RB5
#define Clock_In_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define Clock_In_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define Clock_In_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define Clock_In_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define Clock_In_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define Clock_In_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set BCD_1 aliases
#define BCD_1_TRIS                 TRISCbits.TRISC0
#define BCD_1_LAT                  LATCbits.LATC0
#define BCD_1_PORT                 PORTCbits.RC0
#define BCD_1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define BCD_1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define BCD_1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define BCD_1_GetValue()           PORTCbits.RC0
#define BCD_1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define BCD_1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set BDC_2 aliases
#define BDC_2_TRIS                 TRISCbits.TRISC1
#define BDC_2_LAT                  LATCbits.LATC1
#define BDC_2_PORT                 PORTCbits.RC1
#define BDC_2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define BDC_2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define BDC_2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define BDC_2_GetValue()           PORTCbits.RC1
#define BDC_2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define BDC_2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set Gate_Out aliases
#define Gate_Out_TRIS                 TRISCbits.TRISC2
#define Gate_Out_LAT                  LATCbits.LATC2
#define Gate_Out_PORT                 PORTCbits.RC2
#define Gate_Out_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Gate_Out_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Gate_Out_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Gate_Out_GetValue()           PORTCbits.RC2
#define Gate_Out_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Gate_Out_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set BCD8 aliases
#define BCD8_TRIS                 TRISCbits.TRISC5
#define BCD8_LAT                  LATCbits.LATC5
#define BCD8_PORT                 PORTCbits.RC5
#define BCD8_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define BCD8_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define BCD8_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define BCD8_GetValue()           PORTCbits.RC5
#define BCD8_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define BCD8_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set Clock_Out aliases
#define Clock_Out_TRIS                 TRISCbits.TRISC6
#define Clock_Out_LAT                  LATCbits.LATC6
#define Clock_Out_PORT                 PORTCbits.RC6
#define Clock_Out_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define Clock_Out_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define Clock_Out_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define Clock_Out_GetValue()           PORTCbits.RC6
#define Clock_Out_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define Clock_Out_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set BCD_4 aliases
#define BCD_4_TRIS                 TRISCbits.TRISC7
#define BCD_4_LAT                  LATCbits.LATC7
#define BCD_4_PORT                 PORTCbits.RC7
#define BCD_4_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define BCD_4_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define BCD_4_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define BCD_4_GetValue()           PORTCbits.RC7
#define BCD_4_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define BCD_4_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF3 pin functionality
 * @Example
    IOCBF3_ISR();
 */
void IOCBF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_InterruptHandler);

*/
extern void (*IOCBF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_DefaultInterruptHandler);

*/
void IOCBF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/