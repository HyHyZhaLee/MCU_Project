/*
 * fsm.c
 *
 *  Created on: Dec 6, 2023
 *      Author: ADMIN
 */


#include "fsm.h"
#include "software_timer.h"

int status = INIT;
int pes_flag = 0;
int counter = 0;

int yellow_timer_init  = 2;
int green_timer_init  = 3;
int red_timer_init  = 5;

int red_temp = 0;
int yellow_temp = 0;
int green_temp = 0;


int total = 0;


void fsm_function(){
	switch(status){
		case INIT:
			status = RED1_GREEN2;
			//INITIALIZE
			setTimer(green_timer_init*1000,TIMER_FSM_STATE);
			setTimer(1000,2);
			counter = red_timer_init;
			trafficDisplay1(OFF);
			trafficDisplay2(OFF);
			total = red_timer_init + green_timer_init + yellow_timer_init;
			break;
		case RED1_GREEN2:
			trafficDisplay1(RED);
			trafficDisplay2(GREEN);
			//DISPLAY PEDES
			if(pes_flag == 1){
				pedestrianDispay(GREEN);
			}
			//DECREMENT EACH SECOND
			if(timer_flag[2] == 1){
				counter--;
				setTimer(1000,2);
			}
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(yellow_timer_init*1000,TIMER_FSM_STATE);
				status = RED1_YELLOW2;
			}
			//BUTTON 0 PROCESSING
			if(is_button_pressed(0) == 1){
				status = MODE_2;
			}
			//BUTTON 3 PROCESSING
			if(is_button_pressed(3) == 1){
				setTimer(2000*total, TIMER_PEDESTRIAN_PERIOD);
				//TODO
				pes_flag = 1;
				if(timer_flag[3] == 1){
					pes_flag = 0;
				}
			}
			break;
		case RED1_YELLOW2:
			trafficDisplay1(RED);
			trafficDisplay2(YELLOW);
			//DISPLAY PEDES
			if(pes_flag == 1){
				pedestrianDispay(GREEN);
			}
			//DECREMENT EACH SECOND
			if(timer_flag[2] == 1){
				counter--;
				setTimer(1000,2);
			}
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(green_timer_init*1000,TIMER_FSM_STATE);
				status = GREEN1_RED2;
				counter = green_timer_init;
			}
			//BUTTON 0 PROCESSING
			if(is_button_pressed(0) == 1){
				status = MODE_2;
			}
			//BUTTON 3 PROCESSING
			if(is_button_pressed(3) == 1){
				setTimer(2000*total, TIMER_PEDESTRIAN_PERIOD);
				//TODO
				pes_flag = 1;
				if(timer_flag[3] == 1){
					pes_flag = 0;
				}
			}
			break;
		case GREEN1_RED2:
			trafficDisplay1(GREEN);
			trafficDisplay2(RED);
			//DISPLAY PEDES
			if(pes_flag == 1){
				pedestrianDispay(RED);
			}
			//DECREMENT EACH SECOND
			if(timer_flag[2] == 1){
				counter--;
				setTimer(1000,2);
			}
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(yellow_timer_init*1000,TIMER_FSM_STATE);
				status = YELLOW1_RED2;
				counter = yellow_timer_init;
			}
			//BUTTON 0 PROCESSING
			if(is_button_pressed(0) == 1){
				status = MODE_2;
			}
			//BUTTON 3 PROCESSING
			if(is_button_pressed(3) == 1){
				setTimer(2000*total, TIMER_PEDESTRIAN_PERIOD);
				//TODO
				pes_flag = 1;
				if(timer_flag[3] == 1){
					pes_flag = 0;
				}
			}
			break;
		case YELLOW1_RED2:
			trafficDisplay1(YELLOW);
			trafficDisplay2(RED);
			//DISPLAY PEDES
			if(pes_flag == 1){
				pedestrianDispay(RED);
			}
			//DECREMENT EACH SECOND
			if(timer_flag[2] == 1){
				counter--;
				setTimer(1000,2);
			}
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(green_timer_init*1000,TIMER_FSM_STATE);
				status = RED1_GREEN2;
				counter = red_timer_init;
			}
			//BUTTON 0 PROCESSING
			if(is_button_pressed(0) == 1){
				status = MODE_2;
			}
			//BUTTON 3 PROCESSING
			if(is_button_pressed(3) == 1){
				setTimer(2000*total, TIMER_PEDESTRIAN_PERIOD);
				//TODO
				pes_flag = 1;
				if(timer_flag[3] == 1){
					pes_flag = 0;
				}
			}
			break;
		case MODE_2:
			//TOGGLE RED
			trafficToggle(RED);
			//BUTTON0 PRESSED
			if(is_button_pressed(0) == 1){
				status = MODE_3;
			}
			//BUTTON1 PRESSED
			if(is_button_pressed(1) == 1){
				red_temp = red_timer_init;
				//ADD UP RED
				if(red_temp >= 99){
					red_temp =0;
				}
				else{
					red_temp++;
				}
			}
			//BUTTON2 PRESSED
			if(is_button_pressed(2) == 1){
				//SAVE
				red_timer_init = red_temp;
				//RESET CONDITION
				yellow_timer_init = red_timer_init - green_timer_init;
				green_timer_init = red_timer_init - yellow_timer_init;
				red_timer_init = yellow_timer_init + green_timer_init;

				status = INIT;
			}
			break;
		case MODE_3:
			//TOGGLE RED
			trafficToggle(YELLOW);
			//BUTTON0 PRESSED
			if(is_button_pressed(0) == 1){
				status = MODE_4;
			}
			//BUTTON1 PRESSED
			if(is_button_pressed(1) == 1){
				yellow_temp = yellow_timer_init;
				//ADD UP YELLOW
				if(yellow_temp >= 99){
					yellow_temp = 0;
				}
				else{
					yellow_temp++;
				}
			}
			//BUTTON2 PRESSED
			if(is_button_pressed(2) == 1){
				//SAVE
				yellow_timer_init = yellow_temp;
				//RESET CONDITION
				yellow_timer_init = red_timer_init - green_timer_init;
				green_timer_init = red_timer_init - yellow_timer_init;
				red_timer_init = yellow_timer_init + green_timer_init;

				status = INIT;
			}
			break;
		case MODE_4:
			//TOGGLE RED
			trafficToggle(GREEN);
			//BUTTON0 PRESSED
			if(is_button_pressed(0) == 1){
				status = INIT ;
			}
			//BUTTON1 PRESSED
			if(is_button_pressed(1) == 1){
				green_temp = green_timer_init;
				//ADD UP GREEN
				if(green_temp >= 99){
					green_temp =0;
				}
				else{
					green_temp++;
				}
			}
			//BUTTON2 PRESSED
			if(is_button_pressed(2) == 1){
				//SAVE
				green_timer_init = green_temp;;
				//RESET CONDITION
				yellow_timer_init = red_timer_init - green_timer_init;
				green_timer_init = red_timer_init - yellow_timer_init;
				red_timer_init = yellow_timer_init + green_timer_init;

				status = INIT;
			}
			break;
		default:
			break;
	}
}

