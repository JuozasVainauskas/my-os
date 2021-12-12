#ifndef OS_INTERRUPT_H
#define OS_INTERRUPT_H

void enable_interrupts(void);
void disable_interrupts(void);
void handle_pic_int(void);
void handle_cpu_int(void);

#endif