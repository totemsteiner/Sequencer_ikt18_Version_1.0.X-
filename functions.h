/* 
 * File:   functions.h
 * Author: totemsteiner
 *
 * Created on June 6, 2018, 4:46 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/pin_manager.h"
#include "GLOBALS.h"



void POT_multiplex() {    

    for (unsigned int i = 0; i < 8; i++) {
        VALUE = i;
    }
    PORTAbits.RA2 = VALUE << 2; //POTi S0
    
    //PORTAbits.RA5 = VALUE; //LED S0
}

void POT_S0_read_in() {
    int conversion;
    ADC_Initialize();
    ADC_StartConversion(POT_S0);

    while (ADC_IsConversionDone());

    conversion = ADC_GetConversion(POT_S0);
};

void handle_faster(){
    //PERIOD ist Startwert für PeriodRegister PR des Timers
    //Funktion muss dann noch an Encoder übergeben werden  IOCBF0_SetInterruptHandler(handle_slower);
    //IOCBF1_SetInterruptHandler(handle_faster);
   __delay_ms(150); //Entprellung
    PERIOD1 = PERIOD1 + 10;
    TMR2_LoadPeriodRegister(PERIOD1);
}

void handle_slower(){
    __delay_ms(150);
    PERIOD1 = PERIOD1 - 10;
    TMR2_LoadPeriodRegister(PERIOD1);
}

void gate_out() {

};

void clk_out();

void POT_LED_out();

void Codierer_read_in();

void encoder_read_in();

void sw_read();

void voltage_out() {

};



#endif	/* FUNCTIONS_H */

