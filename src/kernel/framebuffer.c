#include "headers/framebuffer.h"
#include "headers/io.h"

void fb_write_cell(int position, char c, unsigned char bg, unsigned char fg) {
    char* frameBuffer = (char*) FB_MEMORY_MAPPED_IO;
    frameBuffer[position * 2] = c;
    frameBuffer[position * 2 + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

void fb_move_cursor(unsigned short position) {
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((position >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    position & 0x00FF);
}
