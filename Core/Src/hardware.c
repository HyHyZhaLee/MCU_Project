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

void BuzzerOn(){
	  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,1000);
}


void BuzzerOff(){
	  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
}
void Buzzer_process(){

}
