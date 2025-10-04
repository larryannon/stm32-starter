#include "delay.h"
#include "sys/sys.h"

// available on H7
void DELAY_Init(void) {
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

void delay_us(uint32_t Delay) {
  uint32_t start = DWT->CYCCNT;
  uint32_t ticks = Delay * (SystemCoreClock / 1000000);

  while ((DWT->CYCCNT - start) < ticks) {
  }
}

void delay_ms(uint32_t Delay) {
  delay_us(Delay * 1000);
}

void HAL_Delay(uint32_t Delay) {
  delay_ms(Delay);
}
