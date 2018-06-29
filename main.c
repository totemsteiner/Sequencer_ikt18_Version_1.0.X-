

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
    
    TMR1_Initialize();
    TMR1_SetInterruptHandler(gate_out);
    TMR2_Initialize();
    TMR2_SetInterruptHandler(POT_multiplex);

    //InterruptOnChange Taster mit entsprechenden Funktionen
    IOCBF1_SetInterruptHandler(handle_faster);
    IOCBF0_SetInterruptHandler(handle_slower);
    IOCBF3_SetInterruptHandler(handle_start_stop);
    
    ADC_Initialize(); 
    TMR4_Initialize();
    PWM4_Initialize();
    TMR2_StopTimer();
    POT_LED_SetLow();
    
       
    while (1) {
        
        //POT_LED auf High, das ist das Signal, was am MUX U2 gemultiplext wird.
        POT_LED_SetHigh();
        
        //Analogwerte der Potis werden in pot_value gespeichert.
        uint16_t pot_value = POT_read_in();
        
        //pot_value wird an poti_to_ccp uebergeben, 499 ist der MAX Voltagewert
        PWM4_LoadDutyValue(poti_to_ccp(pot_value, 499));       
    }
}
/**
 End of File
 */