/* 
 * File:   GLOBALS.h
 * Author: totemsteiner
 *
 * Created on June 6, 2018, 4:51 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

//Globale Variablen



unsigned int POT_VALUE = 0;
unsigned int START_STOP_COUNT = 1;

unsigned char PREINDEX = 0;
unsigned char INDEX = 02;
unsigned char REPETITIONS = 0;

unsigned char TMR2_MIN_RATE = 42;
unsigned char TMR2_MAX_RATE = 100;

unsigned int POTI_MAX = 62784;

enum POT_STATES {IDLE, FASTER, SLOWER};

enum POT_STATES POT_STATE = IDLE;





#endif	/* GLOBALS_H */

