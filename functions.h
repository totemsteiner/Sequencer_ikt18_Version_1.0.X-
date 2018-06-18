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

void POT_multiplex(void) {


    i++;

    switch (i) {
        case 1: LED_S1_PORT = 0;
            LED_S2_PORT = 0;
            LED_S0_PORT = 1;


            break;

        case 2:LED_S0_PORT = 0;
            LED_S1_PORT = 1;

            break;

        case 3: LED_S0_PORT = 1;
            LED_S1_PORT = 1;

            break;

        case 4: LED_S0_PORT = 0;
            LED_S1_PORT = 0;
            LED_S2_PORT = 1;

            break;

        case 5: LED_S0_PORT = 1;
            LED_S2_PORT = 1;

            break;

        case 6: LED_S1_PORT = 1;
            LED_S2_PORT = 1;

            break;

        case 7: LED_S0_PORT = 1;
            LED_S2_PORT = 1;
            LED_S1_PORT = 1;

            break;

        case 8: LED_S0_PORT = 1;
            LED_S1_PORT = 1;
            LED_S2_PORT = 1;
            i = 0;
            break;
    }





    TMR0IF = 0;




    //PORTAbits.RA2 = VALUE << 2; //POTi S0 - S2    


}

/*handle_faster() tempo einstellung, PERIOD1 wird in RP2 (PeriodRegister des T
 TMR2) geschrieben, Funktionen sind an TMR2 übergeben*/
void handle_faster_RB1() {
    __delay_ms(150);
    PERIOD1 = PERIOD1 + 10; //Hex Wert PERIOD1 wird vergroessert -> schneller
    TMR2_LoadPeriodRegister(PERIOD1);
}

/*handle_slower() tempo einstellung, PERIOD1 wird in RP2 (PeriodRegister des T
 TMR2) geschrieben, Funktionen sind an TMR2 übergeben*/
void handle_slower_RB0() {
    __delay_ms(150);
    PERIOD1 = PERIOD1 - 10; //Hex Wert PERIOD1 wird verringert -> langsamer
    TMR2_LoadPeriodRegister(PERIOD1);
}

/*
void POT_S0_read_in() {
    int conversion;
    ADC_Initialize();
    ADC_StartConversion(POT_S0);

    while (ADC_IsConversionDone());

    conversion = ADC_GetConversion(POT_S0);
};
 */

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

