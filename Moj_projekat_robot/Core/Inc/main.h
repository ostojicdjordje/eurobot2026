/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define RESET_Pin GPIO_PIN_2
#define RESET_GPIO_Port GPIOC
#define ENCLA_Pin GPIO_PIN_0
#define ENCLA_GPIO_Port GPIOA
#define ENCLB_Pin GPIO_PIN_1
#define ENCLB_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define ENCDA_Pin GPIO_PIN_5
#define ENCDA_GPIO_Port GPIOA
#define SZD_Pin GPIO_PIN_4
#define SZD_GPIO_Port GPIOC
#define M1_DIR_Pin GPIO_PIN_10
#define M1_DIR_GPIO_Port GPIOB
#define SPD_Pin GPIO_PIN_12
#define SPD_GPIO_Port GPIOB
#define SPL_Pin GPIO_PIN_13
#define SPL_GPIO_Port GPIOB
#define SZL_Pin GPIO_PIN_14
#define SZL_GPIO_Port GPIOB
#define AX3V3_Pin GPIO_PIN_6
#define AX3V3_GPIO_Port GPIOC
#define M1PWM_Pin GPIO_PIN_7
#define M1PWM_GPIO_Port GPIOC
#define P_Pin GPIO_PIN_9
#define P_GPIO_Port GPIOC
#define M1DIR_Pin GPIO_PIN_8
#define M1DIR_GPIO_Port GPIOA
#define M2DIR_Pin GPIO_PIN_9
#define M2DIR_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define START_Pin GPIO_PIN_15
#define START_GPIO_Port GPIOA
#define A0_Pin GPIO_PIN_10
#define A0_GPIO_Port GPIOC
#define A2_Pin GPIO_PIN_12
#define A2_GPIO_Port GPIOC
#define ENCDB_Pin GPIO_PIN_3
#define ENCDB_GPIO_Port GPIOB
#define M2PWM_Pin GPIO_PIN_6
#define M2PWM_GPIO_Port GPIOB
#define A1_Pin GPIO_PIN_7
#define A1_GPIO_Port GPIOB
#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_9
#define SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
