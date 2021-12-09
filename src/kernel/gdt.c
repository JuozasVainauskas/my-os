#include "headers/gdt.h"

// https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-vol-3a-part-1-manual.pdf
// Page 98

void gdt_init()
{
    gdt_ptr.limit   = sizeof(gdt_entry_t)*GDT_NUM_ENTRIES;
    gdt_ptr.base    = (unsigned int)&gdt_entries;

    // the null entry
    gdt_create_entry(0, 0, 0);
    // kernel mode code segment
    gdt_create_entry(1, PL0, CODE_RX_TYPE);
    // kernel mode data segment
    gdt_create_entry(2, PL0, DATA_RW_TYPE);

    gdt_load_and_set((unsigned int)&gdt_ptr);
}



void gdt_create_entry(unsigned int entry, unsigned char pl, unsigned char type)
{
    gdt_entries[entry].base_low     = (SEGMENT_BASE & 0xFFFF);
    gdt_entries[entry].base_mid     = (SEGMENT_BASE >> 16) & 0xFF;
    gdt_entries[entry].base_high    = (SEGMENT_BASE >> 24) & 0xFF;
    gdt_entries[entry].limit_low    = (SEGMENT_LIMIT & 0xFFFF);
    gdt_entries[entry].granularity |= 0x80 | 0x40 | 0x0F;
    gdt_entries[entry].access       = 0x80 | ((pl & 0x03) << 5) | 0x10 | (type & 0x0F);
}