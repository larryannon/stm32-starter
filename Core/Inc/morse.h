#ifndef STM32_STARTER_MORSE_H
#define STM32_STARTER_MORSE_H

#define MORSE_DELAY_MS_UNIT 200  // unit delay time ms

void morse_begin(void);

void morse_request_stop(void);

uint8_t morse_is_stopped(void);

void morse_message();

#endif //STM32_STARTER_MORSE_H
