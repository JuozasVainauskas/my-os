#ifndef OS_GDT_H
#define OS_GDT_H

#define SEGMENT_BASE    0
#define SEGMENT_LIMIT   0xFFFFF

#define CODE_RX_TYPE    0xA
#define DATA_RW_TYPE    0x2

#define PL0 0x0 // highest privillege level
#define PL3 0x3

#define GDT_NUM_ENTRIES 3

struct gdt_entry { // 64 bits
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char  base_mid;
    unsigned char  access;
    unsigned char  granularity; 
    unsigned char  base_high;
} __attribute__((packed));
typedef struct gdt_entry gdt_entry_t;

typedef struct gdt_ptr {
    unsigned short limit; // number of entries in the GDT
    unsigned int base;    // address of the first GDT entry
} __attribute__((packed));
typedef struct gdt_ptr gdt_ptr_t;

gdt_entry_t gdt_entries[GDT_NUM_ENTRIES];
gdt_ptr_t   gdt_ptr;

void gdt_init();
void gdt_load_and_set(unsigned int gdtAddress);
void gdt_create_entry(unsigned int entry, unsigned char pl, unsigned char type);

#endif
