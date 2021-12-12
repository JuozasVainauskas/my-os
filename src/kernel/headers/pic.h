#ifndef OS_PIC_H
#define OS_PIC_H

// http://www.acm.uiuc.edu/sigops/roll_your_own/i386/irq.html

#define PIC1_PORT_A 0x20
#define PIC1_PORT_B 0x21

#define PIC2_PORT_A 0xA0
#define PIC2_PORT_B 0xA1

#define PIC1_ICW1   0x11
#define PIC2_ICW1   PIC1_ICW2

#define PIC1_ICW2   0x20
#define PIC2_ICW2   0x28

#define PIC1_ICW3   0x04
#define PIC2_ICW3   0x02

#define PIC1_ICW4   0x05
#define PIC2_ICW4   0x01

#define PIC1_START  0x20
#define PIC2_START  0x28

#define PIC_EOI     0x20

void pic_init();
void pic_acknowledge();

#endif