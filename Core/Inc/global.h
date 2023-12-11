/*
 * global.h
 *
 *  Created on: Oct 30, 2023
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "fsm_for_traffic_light.h"
#include "fsm_for_pedestrian.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "hardware.h"
#include "scheduler.h"
#include <stdio.h>
#include <string.h>
//Define timers
#define TIMER_DEBUG 0
#define TIMER_FSM_STATE 1
#define TIMER_FOR_UART 2
#define TIMER_PEDESTRIAN_PERIOD 3
#define TIMER_TOGGLE	4

//Define buttons
#define BUTTON_MODE 0
#define BUTTON_UP 1
#define BUTTON_SAVE 2
#define BUTTON_PED 3


//Use to define states
#define INIT 1
#define RED1_GREEN2 2
#define RED1_YELLOW2 3
#define GREEN1_RED2 4
#define YELLOW1_RED2 5

#define MAN_RED 12
#define MAN_YELLOW 13
#define MAN_GREEN 14

#define SETUP 	39
#define MODE_MODIFY_RED 	41
#define MODE_MODIFY_YELLOW	42
#define MODE_MODIFY_GREEN	43
#define PEDESTRIAN_MODE 44

extern int TRAFFIC_STATUS;
extern int TRAFFIC_COUNTER;
extern int flag_pedestrian;

#endif /* INC_GLOBAL_H_ */
