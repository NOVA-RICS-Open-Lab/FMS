#ifndef __INDUSTRIALSHIELDS_H__
#define __INDUSTRIALSHIELDS_H__

#include "Arduino.h"

extern void RS485EventRun() __attribute__((weak));
extern void RS232EventRun() __attribute__((weak));

void IS_initDefaultIOPins();

#endif // __INDUSTRIALSHIELDS_COM
