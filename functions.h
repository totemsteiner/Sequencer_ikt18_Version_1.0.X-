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
#include "mcc_generated_files/tmr6.h"

uint16_t poti_to_ccp(uint16_t POT_VALUE, uint16_t ccp_max_value);
void gate_out();
void clock_out();

void POT_multiplex(void) {
    
    if (REPETITIONS > 0) {
        
        Gate_Out_SetHigh();
        Clock_Out_SetHigh();
        REPETITIONS--;
        //POT_VALUE wird an poti_to_ccp uebergeben, 499 ist der MAX Voltagewert
        PWM4_LoadDutyValue(poti_to_ccp(POT_VALUE, 499));
        TMR1_StartTimer();

    } else {
        PREINDEX = (PREINDEX + 1) % 8;
        INDEX = 8 - PREINDEX;
        POT_LED_SetHigh();
        //LED Multiplexing    
        LED_S0_LAT = (INDEX & 0b00000001) / 1;
        LED_S1_LAT = (INDEX & 0b00000010) / 2;
        LED_S2_LAT = (INDEX & 0b00000100) / 4;

        //POTENTIOMETER und Codierer MULTIPLEXING    
        S0_LAT = (INDEX & 0b00000001) / 1;
        S1_LAT = (INDEX & 0b00000010) / 2;
        S2_LAT = (INDEX & 0b00000100) / 4;

        //Einlesen des durch INDEX gemuxten POTIS
        POT_VALUE = POT_read_in();

        REPETITIONS = 1;
//        REPETITIONS |= BCD_1_GetValue() << 0;
//        REPETITIONS |= BCD_2_GetValue() << 1;
//        REPETITIONS |= BCD_4_GetValue() << 2;
//        REPETITIONS |= BCD_8_GetValue() << 3;
        
    }


}

void handle_pot_movement(void) {
    if (POT_STATE == FASTER) {
        // 13 als minimaler Wert um eine Gesamtdurchlaufzeit von 500ms
        // zu erhalten
        if (TMR2_INTERRUPT_TICKER_FACTOR > 13) {
            TMR2_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR - 1;
            TMR1_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR / 2;
            TMR6_INTERRUPT_TICKER_FACTOR = TMR1_INTERRUPT_TICKER_FACTOR;
        }
    }
    if (POT_STATE == SLOWER) {
        if (POT_STATE < 800) {
            TMR2_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR + 1;
            TMR1_INTERRUPT_TICKER_FACTOR = TMR2_INTERRUPT_TICKER_FACTOR / 2 ;
            TMR6_INTERRUPT_TICKER_FACTOR = TMR1_INTERRUPT_TICKER_FACTOR;
        }
    }
    POT_STATE = IDLE;
    return;
}

/*
 * handle_faster() tempo einstellung, der Interrupt  TICKER_FACTOR des TMR2
 * wird verringert, somit wird das Tempo schneller!
 */
void handle_faster(void) {
    if (POT_STATE == IDLE) {
        POT_STATE = FASTER;
        __delay_ms(5);
    } else {
        handle_pot_movement();
    }
}

/*
 * handle_slower() tempo einstellung, der Interrupt  TICKER_FACTOR des TMR2
 * wird vergroessert, somit wird das Tempo langsamer!
 */
void handle_slower(void) {
    if (POT_STATE == IDLE) {
        POT_STATE = SLOWER;
        __delay_ms(5);
    } else {
        handle_pot_movement();
    }

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

uint16_t poti_to_ccp(uint16_t POT_VALUE, uint16_t ccp_max_value) {
    float f = (float) POT_VALUE / (float) 62784;
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
    // Setze gate out auf low, es wird von POT_multiplex
    // auf high gesetzt
    Gate_Out_SetLow();
    TMR1_StopTimer();
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
        TMR1_StartTimer();
        LED_SW1_SetHigh();

    } else {
        TMR2_StopTimer();
        TMR1_StopTimer();
        LED_SW1_SetLow();
    }
}

// Setze clock out auf low, es wird von POT_multiplex
// auf high gesetzt

void clock_out() {
    Clock_Out_SetLow();
    TMR6_StopTimer();
}


#endif	/* FUNCTIONS_H */

