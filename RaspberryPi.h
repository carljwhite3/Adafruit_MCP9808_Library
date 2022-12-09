#ifndef __RaspberryPi
#define __RaspberryPi

#include <cstdint>

#define LSBFIRST 0
#define MSBFIRST 1

typedef bool boolean;
typedef uint8_t byte;

void delay(unsigned long ms);
unsigned long millis(void);

#endif
