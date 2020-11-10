#ifndef __TICK_H__
#define __TICK_H__

void tick_init(void);
void mdelay(unsigned long ms);
unsigned long tick_get(void);
int tick_register_task(void (*func)(void), unsigned long interval);

#endif
