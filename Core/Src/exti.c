#include "sys/sys.h"
#include "delay/delay.h"
#include "key/key.h"
#include "led/led.h"
#include "morse/morse.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    delay_ms(30);
    switch (GPIO_Pin) {
        case KEY0_GPIO_PIN:
            if (KEY0 == 0) {
                morse_begin();
            }
            break;

        case KEY1_GPIO_PIN:
            if (KEY1 == 0) {
                morse_request_stop();
                led_toggle(1);
            }
            break;

        case KEY2_GPIO_PIN:
            if (KEY2 == 0) {
                morse_request_stop();
                led_toggle(0);
            }
            break;

        case WKUP_GPIO_PIN:
            if (WK_UP == 1) {
                morse_request_stop();
                led_toggle(1);
                if (HAL_GPIO_ReadPin(LED_GPIO_PORT, LED1_PIN) == 1) {
                    led_on(0);
                } else {
                    led_off(0);
                }
            }
            break;

        default:
            break;
    }
}
