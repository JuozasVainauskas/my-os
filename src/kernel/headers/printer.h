#ifndef OS_WRITER_H
#define OS_WRITER_H

#define FB_MEMORY_MAPPED_IO 0x000B8000

#define FB_BLACK     2
#define FB_DARK_GREY 8

#define FB_COMMAND_PORT         0x03D4
#define FB_DATA_PORT            0x03D5
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

void print(char* output, int position);
void fb_write_cell(int i, char c, unsigned char bg, unsigned char fg);
void fb_move_cursor(unsigned short pos);

#endif