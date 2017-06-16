#ifndef BLINK_LIB_H
#define BLINK_LIB_H

#include <stdint.h>


void blink_setup(uint8_t pin=13);

void blink(unsigned long duration, uint8_t pin=13);


#endif // BLINK_LIB_H
