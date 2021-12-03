#include "headers/framebuffer.h"
#include "headers/printer.h"

void print_str(char* output, int position, unsigned char bg_color, unsigned char fg_color) {
    for(; *output != '\0'; output++) {
        fb_write_cell(position++, *output, bg_color, fg_color);
    }
    fb_move_cursor(position);
}
