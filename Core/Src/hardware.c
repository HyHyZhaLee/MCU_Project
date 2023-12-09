/*
 * hardware_unit_test.c
 *
 *  Created on: Dec 7, 2023
 *      Author: Admin
 */



#include <hardware.h>

void trafficDisplay1(uint8_t input){
	switch (input) {
		case OFF:
		  HAL_GPIO_WritePin(TRAFFIC1_BIT1_GPIO_Port, TRAFFIC1_BIT1_Pin, 0);
		  HAL_GPIO_WritePin(TRAFFIC1_BIT2_GPIO_Port, TRAFFIC1_BIT2_Pin, 0);
		  break;
		case RED:
		  HAL_GPIO_WritePin(TRAFFIC1_BIT1_GPIO_Port, TRAFFIC1_BIT1_Pin, 1);
		  HAL_GPIO_WritePin(TRAFFIC1_BIT2_GPIO_Port, TRAFFIC1_BIT2_Pin, 0);
		  break;
		case GREEN:
		  HAL_GPIO_WritePin(TRAFFIC1_BIT1_GPIO_Port, TRAFFIC1_BIT1_Pin, 0);
		  HAL_GPIO_WritePin(TRAFFIC1_BIT2_GPIO_Port, TRAFFIC1_BIT2_Pin, 1);
		  break;
		case YELLOW:
		  HAL_GPIO_WritePin(TRAFFIC1_BIT1_GPIO_Port, TRAFFIC1_BIT1_Pin, 1);
		  HAL_GPIO_WritePin(TRAFFIC1_BIT2_GPIO_Port, TRAFFIC1_BIT2_Pin, 1);
		  break;
		default:
			break;
	}
}

void trafficDisplay2(uint8_t input){
	switch (input) {
		case OFF:
		  HAL_GPIO_WritePin(TRAFFIC2_BIT1_GPIO_Port, TRAFFIC2_BIT1_Pin, 0);
		  HAL_GPIO_WritePin(TRAFFIC2_BIT2_GPIO_Port, TRAFFIC2_BIT2_Pin, 0);
		  break;
		case RED:
		  HAL_GPIO_WritePin(TRAFFIC2_BIT1_GPIO_Port, TRAFFIC2_BIT1_Pin, 1);
		  HAL_GPIO_WritePin(TRAFFIC2_BIT2_GPIO_Port, TRAFFIC2_BIT2_Pin, 0);
		  break;
		case GREEN:
		  HAL_GPIO_WritePin(TRAFFIC2_BIT1_GPIO_Port, TRAFFIC2_BIT1_Pin, 0);
		  HAL_GPIO_WritePin(TRAFFIC2_BIT2_GPIO_Port, TRAFFIC2_BIT2_Pin, 1);
		  break;
		case YELLOW:
		  HAL_GPIO_WritePin(TRAFFIC2_BIT1_GPIO_Port, TRAFFIC2_BIT1_Pin, 1);
		  HAL_GPIO_WritePin(TRAFFIC2_BIT2_GPIO_Port, TRAFFIC2_BIT2_Pin, 1);
		  break;
		default:
			break;
	}
}

uint8_t toggle_state = 0;
void trafficToggle(uint8_t input){
	if(timer_flag[4]){
		setTimer(1000, 4);
		toggle_state = 1 - toggle_state;
	}
	if(toggle_state){
		switch(input){
			case RED:
				trafficDisplay1(RED);
				trafficDisplay2(RED);
				break;
			case YELLOW:
				trafficDisplay1(YELLOW);
				trafficDisplay2(YELLOW);
				break;
			case GREEN:
				trafficDisplay1(GREEN);
				trafficDisplay2(GREEN);
				break;
		}
	}
	else {
		trafficDisplay1(OFF);
		trafficDisplay2(OFF);
	}
}


void pedestrianDispay(uint8_t input){
	switch (input) {
		case OFF:
		  HAL_GPIO_WritePin(PEDLED_BIT1_GPIO_Port, PEDLED_BIT1_Pin, 0);
		  HAL_GPIO_WritePin(PEDLED_BIT2_GPIO_Port, PEDLED_BIT2_Pin, 0);
		  break;
		case RED:
			  HAL_GPIO_WritePin(PEDLED_BIT1_GPIO_Port, PEDLED_BIT1_Pin, 1);
			  HAL_GPIO_WritePin(PEDLED_BIT2_GPIO_Port, PEDLED_BIT2_Pin, 0);
		  break;
		case GREEN:
			  HAL_GPIO_WritePin(PEDLED_BIT1_GPIO_Port, PEDLED_BIT1_Pin, 0);
			  HAL_GPIO_WritePin(PEDLED_BIT2_GPIO_Port, PEDLED_BIT2_Pin, 1);
		  break;
		case YELLOW:
			  HAL_GPIO_WritePin(PEDLED_BIT1_GPIO_Port, PEDLED_BIT1_Pin, 1);
			  HAL_GPIO_WritePin(PEDLED_BIT2_GPIO_Port, PEDLED_BIT2_Pin, 1);
		  break;
		default:
			break;
	}
}

uint8_t togglePedState = 0;
void pedestrianToggle(uint8_t input){
	if(timer_flag[4]){
		setTimer(1000, 4);
		togglePedState = 1 - togglePedState;
	}
	if(togglePedState){
		switch(input){
			case RED:
				pedestrianDispay(RED);
				break;
			case YELLOW:
				pedestrianDispay(YELLOW);
				break;
			case GREEN:
				pedestrianDispay(GREEN);
				break;
		}
	}
	else {
		pedestrianDispay(OFF);
	}
}

void BuzzerOn(){
	  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,1000);
}


void BuzzerOff(){
	  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
}

void runAutoDebug() {
	if(timer_flag[0]){
		setTimer(1000,0);
		HAL_GPIO_TogglePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin);
	}
#ifndef __TEST_BUTTON
    // This code runs when __TEST_BUTTON is not defined
    #ifdef __TEST_BUZZER
        BuzzerOn();
        HAL_Delay(1000);
        BuzzerOff();
        HAL_Delay(5000);
    #endif //__TEST_BUZZER

    #ifdef __TEST_TRAFFIC
        // Simulate traffic and pedestrian lights
        trafficDisplay1(RED);
        trafficDisplay2(GREEN);
        pedestrianDisplay(RED);
        HAL_Delay(2000);

        trafficDisplay1(GREEN);
        trafficDisplay2(RED);
        pedestrianDisplay(GREEN);
        HAL_Delay(2000);
    #endif //__TEST_TRAFFIC

	#ifdef __TEST_TOGGLE_TRAFIC
        trafficToggle(RED);
	#endif

	#ifdef __TEST_TOGGLE_PEDESTRIAN
        pedestrianToggle(RED);
	#endif
#else
    // This code runs when __TEST_BUTTON is defined

    // Check if buttons are pressed and toggle DEBUG_LED1 accordingly
        if(is_button_pressed(0)) HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
        if(is_button_pressed(1)) HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
        if(is_button_pressed(2)) HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
        if(is_button_pressed(3)) HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
#endif //__TEST_BUTTON
}

