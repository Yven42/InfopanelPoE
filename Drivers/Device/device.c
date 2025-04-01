/*
 * device.c
 *
 *  Created on: Jan 8, 2025
 *      Author: yvogt
 */

#include "device.h"

void StandbyStart(uint32_t Seconds)
{
	// Zugriff auf Backup-Register aktivieren
	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_BACKUPRESET_FORCE();
	__HAL_RCC_BACKUPRESET_RELEASE();
	__HAL_RCC_RTC_ENABLE();
	HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x1234);

	// Power-Clock aktivieren
	__HAL_RCC_PWR_CLK_ENABLE();
	// Wake-up-Pin aktivieren
	HAL_PWR_EnableWakeUpPin(INT_Reset_Pin);
	// Wake-up-Flag löschen
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	// Standby-Modus betreten
	HAL_SuspendTick();
	HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, Seconds, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	HAL_PWR_EnterSTANDBYMode();
}

void Buzzer(uint32_t MilliSecond)
{
	HAL_TIM_PWM_Start_IT(&htim5,TIM_CHANNEL_2);
	HAL_Delay(MilliSecond);
	HAL_TIM_PWM_Stop_IT(&htim5,TIM_CHANNEL_2);
}
