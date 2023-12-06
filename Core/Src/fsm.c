/*
 * fsm.c
 *
 *  Created on: Dec 6, 2023
 *      Author: ADMIN
 */


#include "fsm.h"

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
			counter = green_timer_init;
			setTimer1(green_timer_init*100);
			setTimer2(25);
			setTimer3(100);
			trafficDisplay(INIT);
			break;
		case RED1_GREEN2:
			trafficDisplay(RED1_GREEN2);
			//NEXT STATUS SETTING
			if(timer1_flag == 1){
				counter = red_timer_init;
				setTimer1(green_timer_init*100);
				status = RED1_YELLOW2;
			}
			//7SEG SCANNING
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led++);
			}
			//DECEMENT THE VALUE BY 1 EACH SECOND
			if(timer3_flag == 1){
				setTimer3(100);
				counter--;
			}
			//BUTTON PROCESSING
			if(isButtonPressed(0) == 1){
				status = MODE_2;
				setTimer2(25);
				setTimer3(100);
				setTimer4(100);
			}
			//DISPLAY MODE AND NUMBER OF COUNTER
			updateLEDbuffer(1,counter);
			break;
		case RED1_YELLOW2:
			trafficDisplay(RED1_YELLOW2);
			//NEXT STATUS SETTING
			if(timer1_flag == 1){
				setTimer1(green_timer_init*100);
				status = GREEN1_RED2;
				counter = red_timer_init;
			}
			//7SEG SCANNING
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led++);
			}
			//DECEMENT THE VALUE BY 1 EACH SECOND
			if(timer3_flag == 1){
				setTimer3(100);
				counter--;
			}
			//BUTTON PROCESSING
			if(isButtonPressed(0) == 1){
				setTimer2(25);
				setTimer3(100);
				setTimer4(100);
				status = MODE_2;
			}
			//DISPLAY MODE AND NUMBER OF COUNTER
			updateLEDbuffer(1,counter);
			break;
		case GREEN1_RED2:
			trafficDisplay(GREEN1_RED2);
			//NEXT STATUS SETTING
			if(timer1_flag == 1){
				counter = yellow_timer_init;
				setTimer1(yellow_timer_init*100);
				status = YELLOW1_RED2;
			}
			//7SEG SCANNING
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led++);
			}
			//DECEMENT THE VALUE BY 1 EACH SECOND
			if(timer3_flag == 1){
				setTimer3(100);
				counter--;
			}
			//BUTTON PROCESSING
			if(isButtonPressed(0) == 1){
				status = MODE_2;
				setTimer2(25);
				setTimer3(100);
				setTimer4(100);
			}
			//DISPLAY MODE AND NUMBER OF COUNTER
			updateLEDbuffer(1,counter);
			break;
		case YELLOW1_RED2:
			trafficDisplay(RED1_YELLOW2);
			//NEXT STATUS SETTING
			if(timer1_flag == 1){
				setTimer1(green_timer_init*100);
				status = RED1_GREEN2;
				counter = green_timer_init;
			}
			//7SEG SCANNING
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led++);
			}
			//DECEMENT THE VALUE BY 1 EACH SECOND
			if(timer3_flag == 1){
				setTimer3(100);
				counter--;
			}
			//BUTTON PROCESSING
			if(isButtonPressed(0) == 1){
				setTimer2(25);
				setTimer3(100);
				setTimer4(100);
				status = MODE_2;
			}
			//DISPLAY MODE AND NUMBER OF COUNTER
			updateLEDbuffer(1,counter);
			break;
		case MODE_2:
			//DISPLAY MODE AND TIME
			updateLEDbuffer(2,red_timer_init);
			//LED7 SCANNING
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led++);
			}
			//BUTTON0 PRESSED
			if(isButtonPressed(0) == 1){
				status = MODE_3;
			}
			//BUTTON1 PRESSED
			if(isButtonPressed(1) == 1){
				//ADD UP RED
				if(red_timer_init >= 99){
					red_timer_init =0;
				}
				else{
					red_timer_init++;
				}
			}
			//BUTTON2 PRESSED
			if(isButtonPressed(2) == 1){
				//SAVE
				yellow_timer_init = red_timer_init - green_timer_init;
				status = INIT;
			}
			//TOGGLE LED FUNCTION
			//TODO
			break;
		case MODE_3:
			//DISPLAY MODE AND TIME
			updateLEDbuffer(3,yellow_timer_init);
			//LED7 SCANNING
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led++);
			}
			//BUTTON0 PRESSED
			if(isButtonPressed(0) == 1){
				status = MODE_4;
			}
			//BUTTON1 PRESSED
			if(isButtonPressed(1) == 1){
				//ADD UP YELLOW
				if(yellow_timer_init >= 99){
					yellow_timer_init =0;
				}
				else{
					yellow_timer_init++;
				}
			}
			//BUTTON2 PRESSED
			if(isButtonPressed(2) == 1){
				//SAVE
				green_timer_init = red_timer_init - yellow_timer_init;
				status = INIT;
			}
			//TOGGLE LED FUNCTION
			//TODO
			break;
		case MODE_4:
			//DISPLAY MODE AND TIME
			updateLEDbuffer(4,green_timer_init);
			//LED7 SCANNING
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led++);
			}
			//BUTTON0 PRESSED
			if(isButtonPressed(0) == 1){
				status = MODE_2 ;
			}
			//BUTTON1 PRESSED
			if(isButtonPressed(1) == 1){
				//ADD UP GREEN
				if(green_timer_init >= 99){
					green_timer_init =0;
				}
				else{
					green_timer_init++;
				}
			}
			//BUTTON2 PRESSED
			if(isButtonPressed(2) == 1){
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