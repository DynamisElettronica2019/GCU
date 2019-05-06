/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "stm32f7xx_hal.h"

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
#define GEAR_MOTOR_IN1_Pin GPIO_PIN_2
#define GEAR_MOTOR_IN1_GPIO_Port GPIOE
#define GEAR_MOTOR_IN2_Pin GPIO_PIN_3
#define GEAR_MOTOR_IN2_GPIO_Port GPIOE
#define MCU_OSC_IN_Pin GPIO_PIN_0
#define MCU_OSC_IN_GPIO_Port GPIOH
#define MCU_OSC_OUT_Pin GPIO_PIN_1
#define MCU_OSC_OUT_GPIO_Port GPIOH
#define GEAR_MOTOR_IS1_Pin GPIO_PIN_0
#define GEAR_MOTOR_IS1_GPIO_Port GPIOC
#define GEAR_MOTOR_IS2_Pin GPIO_PIN_1
#define GEAR_MOTOR_IS2_GPIO_Port GPIOC
#define CLUTCH_SERVO_PWM_L_Pin GPIO_PIN_1
#define CLUTCH_SERVO_PWM_L_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_3
#define BUZZER_GPIO_Port GPIOA
#define CLUTCH_SERVO_SENSE_FIL_Pin GPIO_PIN_4
#define CLUTCH_SERVO_SENSE_FIL_GPIO_Port GPIOA
#define H20_FAN_SX_SENSE_FIL_Pin GPIO_PIN_5
#define H20_FAN_SX_SENSE_FIL_GPIO_Port GPIOA
#define H2P_FAN_DX_SENSE_FIL_Pin GPIO_PIN_6
#define H2P_FAN_DX_SENSE_FIL_GPIO_Port GPIOA
#define H2O_PUMP_SENSE_FIL_Pin GPIO_PIN_7
#define H2O_PUMP_SENSE_FIL_GPIO_Port GPIOA
#define FUEL_PUMP_SENSE_FIL_Pin GPIO_PIN_4
#define FUEL_PUMP_SENSE_FIL_GPIO_Port GPIOC
#define TEMP_SENSE_Pin GPIO_PIN_0
#define TEMP_SENSE_GPIO_Port GPIOB
#define CURRENT_SENSE_Pin GPIO_PIN_1
#define CURRENT_SENSE_GPIO_Port GPIOB
#define FUEL_PUMP_PWM_Pin GPIO_PIN_9
#define FUEL_PUMP_PWM_GPIO_Port GPIOE
#define AUX_CTRL_PWM_Pin GPIO_PIN_13
#define AUX_CTRL_PWM_GPIO_Port GPIOE
#define STOP_CTRL_PWM_Pin GPIO_PIN_14
#define STOP_CTRL_PWM_GPIO_Port GPIOE
#define LED_YELLOW_Pin GPIO_PIN_9
#define LED_YELLOW_GPIO_Port GPIOD
#define LED_GREEN_Pin GPIO_PIN_10
#define LED_GREEN_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_11
#define LED_RED_GPIO_Port GPIOD
#define L_OIL_Pin GPIO_PIN_6
#define L_OIL_GPIO_Port GPIOC
#define KEY_CTRL_Pin GPIO_PIN_8
#define KEY_CTRL_GPIO_Port GPIOC
#define STARTER_CTRL_Pin GPIO_PIN_9
#define STARTER_CTRL_GPIO_Port GPIOC
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define EFI_COM_1_Pin GPIO_PIN_1
#define EFI_COM_1_GPIO_Port GPIOD
#define EFI_COM_2_Pin GPIO_PIN_2
#define EFI_COM_2_GPIO_Port GPIOD
#define EFI_COM_3_Pin GPIO_PIN_3
#define EFI_COM_3_GPIO_Port GPIOD
#define EFI_COM_4_Pin GPIO_PIN_4
#define EFI_COM_4_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define EEPROM_WP_Pin GPIO_PIN_4
#define EEPROM_WP_GPIO_Port GPIOB
#define EEPROM_SCL_Pin GPIO_PIN_6
#define EEPROM_SCL_GPIO_Port GPIOB
#define EEPROM_SDA_Pin GPIO_PIN_7
#define EEPROM_SDA_GPIO_Port GPIOB
#define GEAR_MOTOR_INHIBIT_Pin GPIO_PIN_1
#define GEAR_MOTOR_INHIBIT_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
