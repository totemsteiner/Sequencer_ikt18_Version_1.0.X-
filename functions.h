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

    //if ( REPETITIONS == 1){
    INDEX = (INDEX + 1) % 8;

    //LED Multiplexing    
    LED_S0_LAT = (INDEX & 0b00000001) / 1;
    LED_S1_LAT = (INDEX & 0b00000010) / 2;
    LED_S2_LAT = (INDEX & 0b00000100) / 4;

    //POTENTIOMETER und Codierer MULTIPLEXING    
    S0_LAT = (INDEX & 0b00000001) / 1;
    S1_LAT = (INDEX & 0b00000010) / 2;
    S2_LAT = (INDEX & 0b00000100) / 4;

    //Einlesen des durch INDEX gemuxten POTIS
    pot_value = POT_read_in();
    //    
    //    //Einlesen des durch INDEX gemuxten DECODERS
    //    REPETITIONS = 1;
    //    REPETITIONS |= BCD_1_GetValue() << 0;
    //    //schreibfehler bitte noch ändern!
    //    REPETITIONS |= BDC_2_GetValue() << 1;
    //    REPETITIONS |= BCD_4_GetValue() << 2;
    //    REPETITIONS |= BCD_8_GetValue() << 3;    
    //    //}
    //    //else {
    //        //REPETITIONS--;
    //        
    //    //}

}

/*
 * handle_faster() tempo einstellung, der Interrupt  TICKER_FACTOR des TMR2
 * wird verringert, somit wird das Tempo schneller!
 */
void handle_faster(void) {
    __delay_ms(150);
    TMR2_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR - 50;
    TMR1_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR / 2;
}

/*
 * handle_slower() tempo einstellung, der Interrupt  TICKER_FACTOR des TMR2
 * wird vergroessert, somit wird das Tempo langsamer!
 */
void handle_slower(void) {
    __delay_ms(150);
    TMR2_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR + 50;
    TMR1_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR / 2;
}

// Calculates the ccp value for a specific duty cycle.
// The duty cycle has to be in the range of [0, 1.0]

uint16_t duty_to_ccp(float duty_cycle, uint16_t ccp_max_value) {
    //As the ccp_min_value is always '0' the ccp value
    //calculates very easily
    return (uint16_t) (duty_cycle * ccp_max_value);
}

// Calculates the cccp value for a specific analog voltage.
// The analog voltage has to be in the range of [0, 5.0]
// A low pass filter can turn the PWM signal into a real
// analog voltage

uint16_t voltage_to_ccp(float voltage, uint16_t ccp_max_value) {
    float duty_cyle = voltage / 5.0;
    return duty_to_ccp(duty_cyle, ccp_max_value);
}

uint16_t poti_to_ccp(uint16_t pot_value, uint16_t ccp_max_value) {
    float f = (float) pot_value / (float) 62784;
    return duty_to_ccp(f, ccp_max_value);
}

/*
 * Funktion zum Einlesen der Analogwerte an PIN POT. Funktionen sind aus adc.h
 * entnommen.
 */
int POT_read_in() {
    uint16_t value;

    ADC_StartConversion(POT);
    while (!ADC_IsConversionDone());
    value = ADC_GetConversionResult();
    return value;
}

void gate_out() {

    Gate_Out_Toggle();

    //TMR1_Reload();
}

/*
 *Funktion zum starten und stoppen des TMR2. Damit die Logik funktioniert, muss 
 *der START_STOP_COUNT um 1 inkrementiert werden. Die Funktion wird mit IOCRB3
 * gesteuert.
 */
void handle_start_stop() {
    __delay_ms(150);
    START_STOP_COUNT++;

    if (START_STOP_COUNT % 2 == 0) {
        TMR2_StartTimer();
        LED_SW1_SetHigh();

    } else {
        __delay_ms(150);
        TMR2_StopTimer();
        LED_SW1_SetLow();
    }
}




#endif	/* FUNCTIONS_H */

