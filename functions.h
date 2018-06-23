/*
 * File:   functions.h
 * Author: totemsteiner
 *
 * Created on June 6, 2018, 4:46 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include "mcc_generated_files/pin_manager.h"
#include "GLOBALS.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/tmr1.h"

void POT_multiplex(void) {
    
    if ( REPETITIONS == 0){
    INDEX = ( INDEX + 1) % 8;
    //LED Multiplexing
    POT_LED_SetHigh();
    LED_S0_LAT = (INDEX & 0b00000001) / 1;
    LED_S1_LAT = (INDEX & 0b00000010) / 2;
    LED_S2_LAT = (INDEX & 0b00000100) / 4;   
    
    //POTENTIOMETER und Codierer MULTIPLEXING    
    S0_LAT = (INDEX & 0b00000001) / 1;
    S1_LAT = (INDEX & 0b00000010) / 2;
    S2_LAT = (INDEX & 0b00000100) / 4;  
    
    //Einlesen des durch INDEX gemuxten POTIS
    CURRENT_STEP_VALUE = POT_read_in();
    
    //Einlesen des durch INDEX gemuxten DECODERS
    REPETITIONS = 0;
    REPETITIONS |= BCD_1_GetValue() << 0;
    //schreibfehler bitte noch ändern!
    REPETITIONS |= BDC_2_GetValue() << 1;
    REPETITIONS |= BCD_4_GetValue() << 2;
    REPETITIONS |= BCD_8_GetValue() << 3;    
    }
    else {
        REPETITIONS--;
    }
    
}

/*handle_faster() tempo einstellung, PERIOD1 wird in RP2 (PeriodRegister des T
 TMR2) geschrieben, Funktionen sind an TMR2 übergeben*/
/*void handle_faster_RB1() {
    __delay_ms(150);
    TMR2_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR + 10; //Hex Wert PERIOD1 wird vergroessert -> schneller
    
}

/*handle_slower() tempo einstellung, PERIOD1 wird in RP2 (PeriodRegister des T
 TMR2) geschrieben, Funktionen sind an TMR2 übergeben*/
/*void handle_slower_RB0() {
    __delay_ms(150);
    TMR2_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR - 10; //Hex Wert PERIOD1 wird verringert -> langsamer
   
}
*/

//für analoges POTI
void set_timer_callback_rate(uint16_t value){
    uint8_t rate = (uint8_t)(((float)value / (float)POTI_MAX) * ((float)TMR2_MAX_RATE - (float)TMR2_MIN_RATE) + 
            TMR2_MIN_RATE);
    TMR2_INTERRUPT_TICKER_FACTOR = rate;
}

int POT_read_in() {
    uint16_t value;   
    
    ADC_StartConversion(POT);
    while (!ADC_IsConversionDone());
    value = ADC_GetConversionResult();    
    return value;
}
 
void voltage_output(){
    Gate_Out_SetHigh();
    TMR1_WriteTimer(0);
    //CURRENT_STEP_VALUE in i2c message
    
}





#endif	/* FUNCTIONS_H */

