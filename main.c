

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
    IOCBF0_SetInterruptHandler(handle_slower_RB0);
    IOCBF1_SetInterruptHandler(handle_faster_RB1);
    TMR2_SetInterruptHandler(POT_multiplex);
    TMR2_SetInterruptHandler(POT_S0_read_in);
    while (1) {




    }
}
/**
 End of File
 */