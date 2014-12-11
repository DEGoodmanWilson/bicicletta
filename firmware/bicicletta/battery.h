#ifndef __BATTERY_H__
#define __BATTERY_H__

#include <stdint.h>

typedef struct _battery_status_t
{
  uint16_t current;
  uint16_t voltage;
} battery_status_t;

battery_status_t battery_status = {0, 0};

void battery_init(void);
void battery_process(void);

#endif //__BATTERY_H__
