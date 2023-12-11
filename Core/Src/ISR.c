/*
 * timer.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Admin
 */

# include "global.h"

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if ( htim -> Instance == TIM2 ) {
		button_reading() ;
		timerRun();
	}
}

#define MAX_UART_BUFFER_SIZE 30
uint8_t UART_VALUE = 0;
uint8_t uart_buffer[MAX_UART_BUFFER_SIZE];
uint8_t uart_index_buffer = 0;
uint8_t uart_buffer_flag = 0;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
//    	HAL_UART_Receive_IT(&huart2, &UART_VALUE, 1);
        uart_buffer[uart_index_buffer++] = UART_VALUE;
        if (uart_index_buffer == MAX_UART_BUFFER_SIZE) {
            uart_index_buffer = 0;
        }
        uart_buffer_flag = 1;
        HAL_UART_Receive_IT(&huart2, &UART_VALUE, 1);
    }
}

