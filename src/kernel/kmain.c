#include "headers/kmain.h"
#include "headers/io.h"

int kmain() {
    fb_write_cell(0, 'Q', 0, 15);
    fb_move_cursor(1);
    return 0;
}

void fb_write_cell(int i, char c, unsigned char bg, unsigned char fg) {
    char* fb = (char*) FB_MEMORY_MAPPED_IO;
    fb[i] = c;
    fb[i + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

void fb_move_cursor(unsigned short pos) {
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}
