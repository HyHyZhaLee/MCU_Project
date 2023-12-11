/*
 * fsm_pes.c
 *
 *  Created on: Dec 9, 2023
 *      Author: tango
 */

#include "fsm_for_pedestrian.h"

void resetPedestrianFlag(){
	BuzzerOff();								// Turn off the buzzer
	timer_flag[TIMER_PEDESTRIAN_PERIOD] = 0;	// Reset the timer flag for pedestrian cycle
	pedestrianDisplay(OFF);						// Turn off the pedestrian light
	flag_pedestrian = 0;						// Reset the pedestrian flag to prevent pedestrian crossing
}

void fsm_pedestrian(){
	// If pedestrian flag = 1, begin the pedestrian fsm
	if(flag_pedestrian){
		switch(TRAFFIC_STATUS){
			case RED1_GREEN2:
				pedestrianDisplay(GREEN);			// Display green light for pedestrians
				break;
			case RED1_YELLOW2:
				/* Remaining time for pedestrians to cross the road is running out
				 *Turn on the buzzer for alert
				 */
				pedestrianDisplay(GREEN);
				BuzzerOn();
				break;
			case GREEN1_RED2:
				pedestrianDisplay(RED);				// Display red light for pedestrians
				BuzzerOff();						// Turn off the buzzer
				break;
			case YELLOW1_RED2:
				pedestrianDisplay(RED);				// Display red light for pedestrians
				break;
			default:
				resetPedestrianFlag();				// By default reset the pedestrian flag
				break;
		}
	}

	// After 2 period running reset the pedestrian flag
	if(timer_flag[TIMER_PEDESTRIAN_PERIOD]){
		resetPedestrianFlag();
	}
}
