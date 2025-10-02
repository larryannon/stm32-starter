#include "sys.h"
#include "delay.h"
#include "led.h"
#include "morse.h"

void morse_delay(int n) {
    delay_ms(n * MORSE_DELAY_MS_UNIT);
}

void morse_dot(int led) {
    led_on(led);
    morse_delay(1);
    led_off(led);
    morse_delay(1);
}

void morse_dash(int led) {
    led_on(led);
    morse_delay(3);
    led_off(led);
    morse_delay(1);
}

void morse_char(const char *code, int led) {
    for (int i = 0; code[i]; i++) {
        if (code[i] == '.') {
            morse_dot(led);
        } else if (code[i] == '-') {
            morse_dash(led);
        }
    }
    morse_delay(2);
}

void morse_message() {
    // YUAN
    morse_char("-.--", 0);
    morse_char("..-", 1);
    morse_char(".-", 0);
    morse_char("-.", 1);
    morse_delay(5);

    // SHEN
    morse_char("...", 0);
    morse_char("....", 1);
    morse_char(".", 0);
    morse_char("-.", 1);
    morse_delay(5);

    // QI
    morse_char("--.-", 0);
    morse_char("..", 1);
    morse_delay(5);

    // DONG
    morse_char("-..", 0);
    morse_char("---", 1);
    morse_char("-.", 0);
    morse_char("--.", 1);
}
