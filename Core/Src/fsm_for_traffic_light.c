/*
 * fsm.c
 *
 *  Created on: Dec 6, 2023
 *      Author: ADMIN
 */

#include "fsm_for_traffic_light.h"
#include "software_timer.h"

// Define global variables
int TRAFFIC_STATUS = INIT;             // Current traffic light status
int flag_pedestrian = 0;       // Flag indicating pedestrian crossing
int TRAFFIC_COUNTER = 0;               // Counter for timer

int YELLOW_TIME = 2;     // Initial yellow light duration in seconds
int GREEN_TIME = 3;      // Initial green light duration in seconds
int RED_TIME = 5;        // Initial red light duration in seconds

int RED_TIME_TEMP = 0;              // Temporary storage for red light duration
int YELLOW_TIME_TEMP = 0;           // Temporary storage for yellow light duration
int GREEN_TIME_TEMP = 0;            // Temporary storage for green light duration

int TRAFFIC_ONE_PERIOD = 0;             // Total duration of one complete traffic light cycle in seconds

// Function to handle the traffic light state machine
void fsm_function(){
	switch(TRAFFIC_STATUS){
		// CASE INIT
		case INIT:
			TRAFFIC_STATUS = RED1_GREEN2;
			// INITIALIZE
			setTimer(GREEN_TIME*1000, TIMER_FSM_STATE);
			TRAFFIC_COUNTER = RED_TIME;
			trafficDisplay1(OFF);
			trafficDisplay2(OFF);
			TRAFFIC_ONE_PERIOD = RED_TIME + GREEN_TIME + YELLOW_TIME;
			break;

		// CASE RED - GREEN
		case RED1_GREEN2:
			trafficDisplay1(RED);
			trafficDisplay2(GREEN);
			// DECREMENT EACH SECOND
			if(timer_flag[TIMER_FOR_UART] == 1){
				TRAFFIC_COUNTER--;
				setTimer(1000, TIMER_FOR_UART);
				UART_transmit_counter();
			}
			// NEXT STATUS SETTING
			if(timer_flag[TIMER_FSM_STATE] == 1){
				setTimer(YELLOW_TIME*1000, TIMER_FSM_STATE);
				TRAFFIC_STATUS = RED1_YELLOW2;
			}
			// BUTTON CHANGE MODE PROCESSING
			if(is_button_pressed(BUTTON_MODE) == 1){
				TRAFFIC_STATUS = MODE_MODIFY_RED;
			}
			// BUTTON FOR PEDESTRIAN PROCESSING
			if(is_button_pressed(BUTTON_PED) == 1){
				setTimer(2000*TRAFFIC_ONE_PERIOD, TIMER_PEDESTRIAN_PERIOD);
				flag_pedestrian = 1;
			}
			break;

		// CASE RED - YELLOW
		case RED1_YELLOW2:
			trafficDisplay1(RED);
			trafficDisplay2(YELLOW);
			// DECREMENT EACH SECOND
			if(timer_flag[TIMER_FOR_UART] == 1){
				TRAFFIC_COUNTER--;
				setTimer(1000, TIMER_FOR_UART);
				UART_transmit_counter();
			}
			// NEXT STATUS SETTING
			if(timer_flag[TIMER_FSM_STATE] == 1){
				setTimer(GREEN_TIME*1000, TIMER_FSM_STATE);
				TRAFFIC_STATUS = GREEN1_RED2;
				TRAFFIC_COUNTER = GREEN_TIME;
			}
			// BUTTON CHANGE MODE PROCESSING
			if(is_button_pressed(BUTTON_MODE) == 1){
				TRAFFIC_STATUS = MODE_MODIFY_RED;
			}
			// BUTTON FOR PEDESTRIAN PROCESSING
			if(is_button_pressed(BUTTON_PED) == 1){
				setTimer(2000*TRAFFIC_ONE_PERIOD, TIMER_PEDESTRIAN_PERIOD);
				flag_pedestrian = 1;
			}
			break;

		// CASE GREEN - RED
		case GREEN1_RED2:
			trafficDisplay1(GREEN);
			trafficDisplay2(RED);
			// DECREMENT EACH SECOND
			if(timer_flag[TIMER_FOR_UART] == 1){
				TRAFFIC_COUNTER--;
				setTimer(1000, TIMER_FOR_UART);
				UART_transmit_counter();
			}
			// NEXT STATUS SETTING
			if(timer_flag[TIMER_FSM_STATE] == 1){
				setTimer(YELLOW_TIME*1000, TIMER_FSM_STATE);
				TRAFFIC_STATUS = YELLOW1_RED2;
				TRAFFIC_COUNTER = YELLOW_TIME;
			}
			// BUTTON CHANGE MODE PROCESSING
			if(is_button_pressed(BUTTON_MODE) == 1){
				TRAFFIC_STATUS = MODE_MODIFY_RED;
			}
			// BUTTON FOR PEDESTRIAN PROCESSING
			if(is_button_pressed(BUTTON_PED) == 1){
				setTimer(2000*TRAFFIC_ONE_PERIOD, TIMER_PEDESTRIAN_PERIOD);
				flag_pedestrian = 1;
			}
			break;

		// CASE YELLOW - RED
		case YELLOW1_RED2:
			trafficDisplay1(YELLOW);
			trafficDisplay2(RED);
			// DECREMENT EACH SECOND
			if(timer_flag[TIMER_FOR_UART] == 1){
				TRAFFIC_COUNTER--;
				setTimer(1000, TIMER_FOR_UART);
				UART_transmit_counter();
			}
			// NEXT STATUS SETTING
			if(timer_flag[TIMER_FSM_STATE] == 1){
				setTimer(GREEN_TIME*1000, TIMER_FSM_STATE);
				TRAFFIC_STATUS = RED1_GREEN2;
				TRAFFIC_COUNTER = RED_TIME;
			}
			// BUTTON CHANGE MODE PROCESSING
			if(is_button_pressed(BUTTON_MODE) == 1){
				TRAFFIC_STATUS = MODE_MODIFY_RED;
			}
			// BUTTON FOR PEDESTRIAN PROCESSING
			if(is_button_pressed(BUTTON_PED) == 1){
				setTimer(2000*TRAFFIC_ONE_PERIOD, TIMER_PEDESTRIAN_PERIOD);
				flag_pedestrian = 1;
			}
			break;

		case MODE_MODIFY_RED:
			// TOGGLE RED
			trafficToggle(RED);
			// BUTTON 0 PRESSED
			if(is_button_pressed(BUTTON_MODE) == 1){
				TRAFFIC_STATUS = MODE_MODIFY_YELLOW;
			}
			// BUTTON 1 PRESSED
			if(is_button_pressed(BUTTON_UP) == 1){
				RED_TIME_TEMP = RED_TIME;
				// ADD UP RED
				if(RED_TIME_TEMP >= 99){
					RED_TIME_TEMP = 0;
				}
				else{
					RED_TIME_TEMP++;
				}
			}
			// BUTTON 2 PRESSED
			if(is_button_pressed(BUTTON_SAVE) == 1){
				// SAVE
				RED_TIME = RED_TIME_TEMP;
				// RESET CONDITION
				YELLOW_TIME = RED_TIME - GREEN_TIME;
				GREEN_TIME = RED_TIME - YELLOW_TIME;

				TRAFFIC_STATUS = MODE_MODIFY_YELLOW;
			}
			break;

		case MODE_MODIFY_YELLOW:
			// TOGGLE RED
			trafficToggle(YELLOW);
			// BUTTON 0 PRESSED
			if(is_button_pressed(BUTTON_MODE) == 1){
				TRAFFIC_STATUS = MODE_MODIFY_GREEN;
			}
			// BUTTON 1 PRESSED
			if(is_button_pressed(BUTTON_UP) == 1){
				YELLOW_TIME_TEMP = YELLOW_TIME;
				// ADD UP YELLOW
				if(YELLOW_TIME_TEMP >= 99){
					YELLOW_TIME_TEMP = 0;
				}
				else{
					YELLOW_TIME_TEMP++;
				}
			}
			// BUTTON 2 PRESSED
			if(is_button_pressed(BUTTON_SAVE) == 1){
				// SAVE
				YELLOW_TIME = YELLOW_TIME_TEMP;
				// RESET CONDITION
				GREEN_TIME = RED_TIME - YELLOW_TIME;
				RED_TIME = YELLOW_TIME + GREEN_TIME;

				TRAFFIC_STATUS = MODE_MODIFY_GREEN;
			}
			break;

		case MODE_MODIFY_GREEN:
			// TOGGLE RED
			trafficToggle(GREEN);
			// BUTTON 0 PRESSED
			if(is_button_pressed(BUTTON_MODE) == 1){
				TRAFFIC_STATUS = RED1_GREEN2;
				setTimer(GREEN_TIME*1000, TIMER_FSM_STATE);
			}
			// BUTTON 1 PRESSED
			if(is_button_pressed(BUTTON_UP) == 1){
				GREEN_TIME_TEMP = GREEN_TIME;
				// ADD UP GREEN
				if(GREEN_TIME_TEMP >= 99){
					GREEN_TIME_TEMP = 0;
				}
				else{
					GREEN_TIME_TEMP++;
				}
			}
			// BUTTON 2 PRESSED
			if(is_button_pressed(BUTTON_SAVE) == 1){
				// SAVE
				GREEN_TIME = GREEN_TIME_TEMP;;
				// RESET CONDITION
				YELLOW_TIME = RED_TIME - GREEN_TIME;
				RED_TIME = YELLOW_TIME + GREEN_TIME;

				setTimer(GREEN_TIME*1000, TIMER_FSM_STATE);
				TRAFFIC_ONE_PERIOD = RED_TIME + GREEN_TIME + YELLOW_TIME;
				TRAFFIC_STATUS = RED1_GREEN2;
			}
			break;
		default:
			break;
	}
}
