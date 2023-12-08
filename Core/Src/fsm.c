/*
 * fsm.c
 *
 *  Created on: Dec 6, 2023
 *      Author: ADMIN
 */


#include "fsm.h"
#include "software_timer.h"

int status = INIT;


int yellow_timer_init = 2;
int green_timer_init = 3;
int red_timer_init = 5;
int counter = 0;


void fsm_function(){
	switch(status){
		case INIT:
			status = RED1_GREEN2;
			//INITIALIZE
			setTimer(green_timer_init*100,1);
			trafficDisplay1(OFF);
			trafficDisplay2(OFF);
			break;
		case RED1_GREEN2:
			trafficDisplay1(RED);
			trafficDisplay2(GREEN);
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(yellow_timer_init*100,1);
				status = RED1_YELLOW2;
			}
			//BUTTON PROCESSING
			if(is_button_pressed(0) == 1){
				status = MODE_2;
				setTimer(25,2);
				setTimer(100,3);
				setTimer(100,4);
			}
			break;
		case RED1_YELLOW2:
			trafficDisplay1(RED);
			trafficDisplay2(YELLOW);
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(green_timer_init*100,1);
				status = GREEN1_RED2;
			}
			//BUTTON PROCESSING
			if(is_button_pressed(0) == 1){
				setTimer(25,2);
				setTimer(100,3);
				setTimer(100,4);
				status = MODE_2;
			}
			break;
		case GREEN1_RED2:
			trafficDisplay1(GREEN);
			trafficDisplay2(RED);
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(yellow_timer_init*100,1);
				status = YELLOW1_RED2;
			}
			//BUTTON PROCESSING
			if(is_button_pressed(0) == 1){
				status = MODE_2;
			}
			break;
		case YELLOW1_RED2:
			trafficDisplay1(YELLOW);
			trafficDisplay2(RED);
			//NEXT STATUS SETTING
			if(timer_flag[1] == 1){
				setTimer(green_timer_init*100,1);
				status = RED1_GREEN2;
			}
			//DECEMENT THE VALUE BY 1 EACH SECOND
			//BUTTON PROCESSING
			if(is_button_pressed(0) == 1){
				setTimer(100,3);
				status = MODE_2;
			}
			break;
		case MODE_2:
			//BUTTON0 PRESSED
			if(is_button_pressed(0) == 1){
				status = MODE_3;
			}
			//BUTTON1 PRESSED
			if(is_button_pressed(1) == 1){
				//ADD UP RED
				if(red_timer_init >= 99){
					red_timer_init =0;
				}
				else{
					red_timer_init++;
				}
			}
			//BUTTON2 PRESSED
			if(is_button_pressed(2) == 1){
				//SAVE
				yellow_timer_init = red_timer_init - green_timer_init;
				status = INIT;
			}
			//TOGGLE LED FUNCTION
			//TODO
			break;
		case MODE_3:
			//BUTTON0 PRESSED
			if(is_button_pressed(0) == 1){
				status = MODE_4;
			}
			//BUTTON1 PRESSED
			if(is_button_pressed(1) == 1){
				//ADD UP YELLOW
				if(yellow_timer_init >= 99){
					yellow_timer_init =0;
				}
				else{
					yellow_timer_init++;
				}
			}
			//BUTTON2 PRESSED
			if(is_button_pressed(2) == 1){
				//SAVE
				green_timer_init = red_timer_init - yellow_timer_init;
				status = INIT;
			}
			//TOGGLE LED FUNCTION
			//TODO
			break;
		case MODE_4:
			//BUTTON0 PRESSED
			if(is_button_pressed(0) == 1){
				status = MODE_2 ;
			}
			//BUTTON1 PRESSED
			if(is_button_pressed(1) == 1){
				//ADD UP GREEN
				if(green_timer_init >= 99){
					green_timer_init =0;
				}
				else{
					green_timer_init++;
				}
			}
			//BUTTON2 PRESSED
			if(is_button_pressed(2) == 1){
				//SAVE
				red_timer_init = yellow_timer_init + green_timer_init;
				status = INIT;
			}
			//TOGGLE LED FUNCTION
			//TODO
			break;
		default:
			break;
	}
}
