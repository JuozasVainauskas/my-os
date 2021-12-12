#include "headers/io.h"
#include "headers/idt.h"
#include "headers/gdt.h"
#include "headers/interrupt.h"

idt_gate_t idt[IDT_NUM_ENTRIES];

void idt_init()
{
    idt_ptr_t idt_ptr;
    idt_ptr.limit = IDT_NUM_ENTRIES * sizeof(idt_gate_t) - 1;
    idt_ptr.base  = (unsigned int) &idt;

    idt_create_cpu_gate();
    idt_create_pic_gate();

    idt_load_and_set((unsigned int) &idt_ptr);
}

void idt_create_cpu_gate() {
    unsigned int i;
    for (i = 0; i < 20; ++i) {
        idt_create_gate(i, (unsigned int) &handle_cpu_int, IDT_TRAP_GATE_TYPE);
    }
}

void idt_create_pic_gate() {
    unsigned int i;
    for (i = 0x20; i < 0x20 + 16; ++i) {
        idt_create_gate(i, (unsigned int) &handle_pic_int, IDT_TRAP_GATE_TYPE);
    }
}

void idt_create_gate(unsigned char entry, unsigned int handler, unsigned char type)
{
    idt[entry].offset_low = handler & 0x0000FFFF;
    idt[entry].offset_high = (handler >> 16) & 0x0000FFFF;
    idt[entry].segment_selector = SEGMENT_SELECTOR_KERNEL_CS;
    idt[entry].zero = 0;
    idt[entry].config = 
        (0x01 << 7)          | 
        ((PL0 & 0x03)  << 5) | 
        (0x01 << 3)          | 
        (0x01 << 2)          | 
        (0x01 << 1)          | 
        type;
}