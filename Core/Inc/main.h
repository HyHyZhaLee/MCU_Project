/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global.h"
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON0_Pin GPIO_PIN_0
#define BUTTON0_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_1
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_4
#define BUTTON2_GPIO_Port GPIOA
#define DEBUG_LED1_Pin GPIO_PIN_5
#define DEBUG_LED1_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_0
#define BUTTON3_GPIO_Port GPIOB
#define PEDLED_BIT1_Pin GPIO_PIN_10
#define PEDLED_BIT1_GPIO_Port GPIOB
#define DEBUG_LED2_Pin GPIO_PIN_9
#define DEBUG_LED2_GPIO_Port GPIOC
#define PEDLED_BIT2_Pin GPIO_PIN_8
#define PEDLED_BIT2_GPIO_Port GPIOA
#define TRAFFIC1_BIT1_Pin GPIO_PIN_10
#define TRAFFIC1_BIT1_GPIO_Port GPIOA
#define TRAFFIC1_BIT2_Pin GPIO_PIN_3
#define TRAFFIC1_BIT2_GPIO_Port GPIOB
#define TRAFFIC2_BIT2_Pin GPIO_PIN_4
#define TRAFFIC2_BIT2_GPIO_Port GPIOB
#define TRAFFIC2_BIT1_Pin GPIO_PIN_5
#define TRAFFIC2_BIT1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
