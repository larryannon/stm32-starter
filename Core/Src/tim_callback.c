#include "sys/sys.h"
#include "tim.h"
#include "tim_callback.h"

void tim_start_1us_timer(void) {
  HAL_TIM_Base_Start_IT(&htim2);
}

uint32_t tim_get_1us_timer_counter(void) {
  return __HAL_TIM_GET_COUNTER(&htim2);
}
