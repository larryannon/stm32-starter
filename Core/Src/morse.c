#include "sys.h"
#include "delay.h"
#include "led.h"
#include "morse.h"

volatile uint8_t morse_stop_request = 0;

void morse_begin(void) {
    morse_stop_request = 0;
}

void morse_request_stop(void) {
    morse_stop_request = 1;
}

uint8_t morse_is_stopped(void) {
    return morse_stop_request;
}

void morse_delay(int n) {
    int total = n * MORSE_DELAY_MS_UNIT;
    while (total > 0) {
        int step = (total > 50) ? 50 : total;
        delay_ms(step);
        total -= step;

        if (morse_stop_request) {
            return;
        }
    }
}

void morse_dot(int led) {
    if (morse_stop_request) {
        return;
    }

    led_on(led);
    morse_delay(1);
    led_off(led);
    morse_delay(1);
}

void morse_dash(int led) {
    if (morse_stop_request) {
        return;
    }

    led_on(led);
    morse_delay(3);
    led_off(led);
    morse_delay(1);
}

void morse_char(const char *code, int led) {
    for (int i = 0; code[i] && !morse_stop_request; i++) {
        if (code[i] == '.') {
            morse_dot(led);
        } else if (code[i] == '-') {
            morse_dash(led);
        }
    }
    morse_delay(2);
}

typedef struct {
    const char *morse;
    int led;
    int word_gap;
} MorseItem;

MorseItem morse_sequence[] = {
    // YUAN
    {"-.--", 0, 0}, {"..-", 1, 0}, {".-", 0, 0}, {"-.", 1, 5},
    // SHEN
    {"...", 0, 0}, {"....", 1, 0}, {".", 0, 0}, {"-.", 1, 5},
    // QI
    {"--.-", 0, 0}, {"..", 1, 5},
    // DONG
    {"-..", 0, 0}, {"---", 1, 0}, {"-.", 0, 0}, {"--.", 1, 0}
};

void morse_message() {
    morse_stop_request = 0;

    int len = sizeof(morse_sequence) / sizeof(MorseItem);
    for (int i = 0; i < len; i++) {
        if (morse_stop_request) {
            return;
        }
        morse_char(morse_sequence[i].morse, morse_sequence[i].led);

        if (morse_stop_request) {
            return;
        }
        if (morse_sequence[i].word_gap) {
            morse_delay(morse_sequence[i].word_gap);
        }
    }
}
