#ifndef STM32_LIB_DELAY_H
#define STM32_LIB_DELAY_H

#include "sys/sys.h"

void DELAY_Init();

void delay_ms(uint32_t Delay);

void delay_us(uint32_t Delay);

void HAL_Delay(uint32_t Delay);

#endif // STM32_LIB_DELAY_H