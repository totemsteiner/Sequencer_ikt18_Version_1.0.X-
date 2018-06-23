

#include "mcc_generated_files/mcc.h"
#include "functions.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/i2c.h"

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
    I2C_Initialize();
    I2C_MESSAGE_STATUS status;
    uint16_t message = 0b00001111111111111;
    uint16_t address = 0b1100000;
    uint16_t length = 12;
    
    while (1) {
       
        uint16_t value = POT_read_in();
        //INDEX = value / 7848;
        __delay_ms(150);
        set_timer_callback_rate(value);
        I2C_MasterWrite(&message, length, address, &status);
        
        
        
    }
}
/**
 End of File
 */