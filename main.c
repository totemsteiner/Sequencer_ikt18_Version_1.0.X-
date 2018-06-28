

#include "mcc_generated_files/mcc.h"
#include "functions.h"
#include "mcc_generated_files/adc.h"


/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    
    TMR2_Initialize();
    TMR2_SetInterruptHandler(POT_multiplex);
    ADC_Initialize(); 
    TMR4_Initialize();
    PWM4_Initialize();
    
   

    
    while (1) {
        POT_LED_SetHigh();
        PWM4_LoadDutyValue(poti_to_ccp(CURRENT_STEP_VALUE, 499));
        
        //set_timer_callback_rate(value);
        
          
    
    
   
        
        
    }
}
/**
 End of File
 */