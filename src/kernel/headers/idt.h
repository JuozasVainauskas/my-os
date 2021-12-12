#ifndef OS_IDT_H
#define OS_IDT_H

#define IDT_NUM_ENTRIES 256

#define IDT_INTERRUPT_GATE_TYPE 0
#define IDT_TRAP_GATE_TYPE		1

#define IDT_TIMER_INTERRUPT_INDEX    0x20
#define IDT_KEYBOARD_INTERRUPT_INDEX 0x21

#define SEGMENT_SELECTOR_KERNEL_CS 0x08

struct idt_gate {
    unsigned short offset_low;
    unsigned short segment_selector;
    unsigned char  zero;
    unsigned char  config;
    unsigned short offset_high;
} __attribute__((packed));
typedef struct idt_gate idt_gate_t;

struct idt_ptr {
    unsigned short limit; // number of entries in the IDT
    unsigned int base;    // address of the first IDT entry
} __attribute__((packed));
typedef struct idt_ptr idt_ptr_t;

void idt_load_and_set(unsigned int idt_ptr);
void idt_init();
void idt_create_cpu_gate();
void idt_create_pic_gate();
void idt_create_gate(unsigned char entry, unsigned int handler, unsigned char type);

#endif