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
#include "stm32l4xx_hal.h"

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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define INT_Reset_Pin GPIO_PIN_0
#define INT_Reset_GPIO_Port GPIOA
#define INT_Reset_EXTI_IRQn EXTI0_IRQn
#define Buzzer_Pin GPIO_PIN_1
#define Buzzer_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define ETH_Power_Pin GPIO_PIN_4
#define ETH_Power_GPIO_Port GPIOA
#define EEPROM_Power_Pin GPIO_PIN_5
#define EEPROM_Power_GPIO_Port GPIOA
#define WLAN_Power_Pin GPIO_PIN_6
#define WLAN_Power_GPIO_Port GPIOA
#define INT_ETH_Pin GPIO_PIN_7
#define INT_ETH_GPIO_Port GPIOA
#define ENABLE_POLOLU_Pin GPIO_PIN_1
#define ENABLE_POLOLU_GPIO_Port GPIOB
#define DISPLAY_POWER_Pin GPIO_PIN_2
#define DISPLAY_POWER_GPIO_Port GPIOB
#define EN_WLAN_Pin GPIO_PIN_8
#define EN_WLAN_GPIO_Port GPIOA
#define RST_WLAN_Pin GPIO_PIN_9
#define RST_WLAN_GPIO_Port GPIOA
#define CS_ETH_Pin GPIO_PIN_10
#define CS_ETH_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define RST_Pin GPIO_PIN_4
#define RST_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_5
#define DC_GPIO_Port GPIOB
#define SPI_CS_Pin GPIO_PIN_6
#define SPI_CS_GPIO_Port GPIOB
#define BUSY_Pin GPIO_PIN_7
#define BUSY_GPIO_Port GPIOB
#define RST_ETH_Pin GPIO_PIN_8
#define RST_ETH_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
