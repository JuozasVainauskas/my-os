#include "headers/pic.h"
#include "headers/io.h"

void pic_init()
{
    io_outb(PIC1_PORT_A, PIC1_ICW1);
    io_outb(PIC2_PORT_A, PIC2_ICW1);

    io_outb(PIC1_PORT_B, PIC1_ICW2);
    io_outb(PIC2_PORT_B, PIC2_ICW2);

    io_outb(PIC1_PORT_B, PIC1_ICW3);
    io_outb(PIC2_PORT_B, PIC2_ICW3);

    io_outb(PIC1_PORT_B, PIC1_ICW4);
    io_outb(PIC2_PORT_B, PIC2_ICW4);
}

void pic_acknowledge()
{
    io_outb(PIC1_PORT_A, PIC_EOI);
    io_outb(PIC2_PORT_A, PIC_EOI);
}
