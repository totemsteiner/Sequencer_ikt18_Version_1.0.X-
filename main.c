

#include "mcc_generated_files/mcc.h"
#include "functions.h"
#include "mcc_generated_files/adc.h"

/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    TMR1_Initialize();
    TMR1_SetInterruptHandler(gate_out);
    TMR2_Initialize();
    TMR2_SetInterruptHandler(POT_multiplex);
    TMR6_Initialize();
    TMR6_SetInterruptHandler(clock_out);

    //InterruptOnChange Taster mit entsprechenden Funktionen
    IOCBF0_SetInterruptHandler(handle_faster);
    IOCBF1_SetInterruptHandler(handle_slower);
    IOCBF3_SetInterruptHandler(handle_start_stop);
    
    ADC_Initialize(); 
    TMR4_Initialize();
    PWM4_Initialize();
    TMR1_StartTimer();
    TMR6_StartTimer();
    TMR2_StopTimer();
    
       
    while (1) {
           
    }
}
/**
 End of File
 */