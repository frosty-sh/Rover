/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define PWM_Pin GPIO_PIN_1
#define PWM_GPIO_Port GPIOA
#define RTRIG_Pin GPIO_PIN_10
#define RTRIG_GPIO_Port GPIOB
#define RECHO_Pin GPIO_PIN_11
#define RECHO_GPIO_Port GPIOB
#define FTRIG_Pin GPIO_PIN_12
#define FTRIG_GPIO_Port GPIOB
#define FECHO_Pin GPIO_PIN_13
#define FECHO_GPIO_Port GPIOB
#define RESWCH_Pin GPIO_PIN_14
#define RESWCH_GPIO_Port GPIOB
#define REBTN_Pin GPIO_PIN_15
#define REBTN_GPIO_Port GPIOB
#define REBTN_EXTI_IRQn EXTI15_10_IRQn
#define TX_Pin GPIO_PIN_9
#define TX_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_10
#define RX_GPIO_Port GPIOA
#define LIN1_Pin GPIO_PIN_6
#define LIN1_GPIO_Port GPIOB
#define LIN2_Pin GPIO_PIN_7
#define LIN2_GPIO_Port GPIOB
#define RIN1_Pin GPIO_PIN_8
#define RIN1_GPIO_Port GPIOB
#define RIN2_Pin GPIO_PIN_9
#define RIN2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
