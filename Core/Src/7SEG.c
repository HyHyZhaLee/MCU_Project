///*
// * 7SEG.c
// *
// *  Created on: Sep 20, 2023
// *      Author: ADMIN
// */
//#include "7SEG.h"
//
//GPIO_TypeDef* SEG_GPIO_Port = GPIOB; // GPIO port for the 7-segment display
//GPIO_TypeDef* LED_GPIO_Port[] = {GPIOA};
//uint16_t SEG_Pin[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};
//uint16_t LED_Pin[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8};  // Array of GPIO pins
//// Define patterns for displaying digits (common athode 7-segment display)
//uint8_t SEG_Patterns[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; // 0 to 9 patterns
//void display7SEG(int num){
//    if (num >= 0 && num <= 9) {
//        // Turn off all segments (set them LOW for common anode)
//        HAL_GPIO_WritePin(SEG_GPIO_Port, GPIO_PIN_All, GPIO_PIN_RESET);
//
//        // Set the pattern for the selected digit (set corresponding segments HIGH)
//        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG_Pin[0], !(SEG_Patterns[num] & 0x01));
//        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG_Pin[1], !((SEG_Patterns[num] >> 1) & 0x01));
//        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG_Pin[2], !((SEG_Patterns[num] >> 2) & 0x01));
//        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG_Pin[3], !((SEG_Patterns[num] >> 3) & 0x01));
//        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG_Pin[4], !((SEG_Patterns[num] >> 4) & 0x01));
//        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG_Pin[5], !((SEG_Patterns[num] >> 5) & 0x01));
//        HAL_GPIO_WritePin(SEG_GPIO_Port, SEG_Pin[6], !((SEG_Patterns[num] >> 6) & 0x01));
//    }
//
//}
////UPDATE 7SEG_LED
//const int MAX_LED = 4;
//int index_led = 0;
//int led_buffer[4] = {0,0,0,0};
//void update7SEG(int index){
//	if(index_led >= MAX_LED) index_led = 0;
//	switch(index){
//		case 0:
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,0);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
//			display7SEG(led_buffer[0]);
//			break;
//		case 1:
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,0);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
//			display7SEG(led_buffer[1]);
//			break;
//		case 2:
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,0);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
//			display7SEG(led_buffer[2]);
//			break;
//		case 3:
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,0);
//			display7SEG(led_buffer[3]);
//			break;
//		default:
//			break;
//	}
//}
////Display Traffic
//
//void trafficDisplay(int index){
//	switch (index){
//		case RED1_GREEN2:
//					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
//					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
//					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
//					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
//					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
//					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 0);
//					break;
//		case RED1_YELLOW2:
//					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
//					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
//					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
//					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
//					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 0);
//					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
//					break;
//		case GREEN1_RED2:
//					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
//					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
//					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 0);
//					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
//					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
//					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
//					break;
//		case YELLOW1_RED2:
//					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
//					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 0);
//					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
//					HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
//					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
//					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
//					break;
//		case INIT:
//					HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
//					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
//					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
//					break;
//	}
//}
//void updateLEDbuffer(int mode,int num){
//	if(mode > 5) mode = 1;
//		led_buffer[0] = 0;
//		led_buffer[1] = mode;
//	if(num >= 10){
//		led_buffer[3] = num % 10;
//		led_buffer[2] = num / 10;
//	}
//	else{
//		led_buffer[3] = num ;
//		led_buffer[2] = 0;
//	}
//}
//
//void resetLED(){
//	for(int i = 0 ; i <= 5 ; i++){
//		HAL_GPIO_WritePin(LED_GPIO_Port[0],LED_Pin[i],1);
//	}
//}
