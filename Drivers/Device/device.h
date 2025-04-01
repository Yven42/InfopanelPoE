/*
 * device.h
 *
 *  Created on: Jan 8, 2025
 *      Author: yvogt
 */

#ifndef DEVICE_DEVICE_H_
#define DEVICE_DEVICE_H_

#include "main.h"

extern TIM_HandleTypeDef htim5;
extern RTC_HandleTypeDef hrtc;

void StandbyStart(uint32_t Seconds);
void Buzzer(uint32_t MilliSecond);


#endif /* DEVICE_DEVICE_H_ */
