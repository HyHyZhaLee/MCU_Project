/*
 * fsm_pes.c
 *
 *  Created on: Dec 9, 2023
 *      Author: tango
 */

#include "global.h"

void fsm_pedestrian(){
	if(pes_flag){
		switch(status){
			case RED1_GREEN2:
				pedestrianDispay(GREEN);
				break;
			case RED1_YELLOW2:
				pedestrianDisplay(TOGGLE);
				// time to walk running out
				BuzzerOn();
				break;
			case GREEN1_RED2:
				pedestrianDispay(RED);
				// BUZZER OFF
				BuzzerOff();
				break;
			case YELLOW1_RED2:
				pedestrianDispay(RED);
				break;
			default:
				break;
		}
	}
	if(timer_flag[TIMER_PEDESTRIAN_PERIOD]){
		timer_flag[TIMER_PEDESTRIAN_PERIOD] = 0;
		pedestrianDispay(OFF);
		pes_flag = 0;
	}
}
