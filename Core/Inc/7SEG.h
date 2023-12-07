/*
 * 7SEG.h
 *
 *  Created on: Oct 1, 2023
 *      Author: ADMIN
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include "main.h"
#include "global.h"

extern int index_led;
void display7SEG(int num);
void update7SEG(int index);
void updateLEDbuffer(int mode,int num);
void trafficDisplay(int index);
void resetLED();

#endif /* INC_7SEG_H_ */
