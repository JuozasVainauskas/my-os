#include "headers/framebuffer.h"
#include "headers/printer.h"

void print_str(char* output, int position, unsigned char bg, unsigned char fg) {
    for(; *output != '\0'; output++) {
        fb_write_cell(position++, *output, bg, fg);
    }
    fb_move_cursor(position);
}
