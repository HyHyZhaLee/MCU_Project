/*
 * software_timer.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"
#define NO_OF_TIMER	6
#define TICK 1

extern int timer_flag[NO_OF_TIMER];
void setTimer(int duration, int ID);
void timerRun();
void initTimer(int delay);
#endif /* INC_SOFTWARE_TIMER_H_ */
