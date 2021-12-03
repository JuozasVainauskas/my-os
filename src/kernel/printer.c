#include "headers/framebuffer.h"
#include "headers/printer.h"
#include "headers/font.h"

void print_str(char* output, int position, Font font) {
    for(; *output != '\0'; output++) {
        fb_write_cell(position++, *output, font);
    }
    fb_move_cursor(position);
}
