#include "headers/framebuffer.h"
#include "headers/printer.h"
#include "headers/font.h"

void clear_screen() {
    unsigned short i = 0;
    for(; i < MAX_COLUMNS * MAX_ROWS; i++) {
        fb_write_cell(i, ' ', makeFont(FB_BLACK, FB_LIGHT_GREY));
    }
}

void print_str(char* output, unsigned short position, Font font) {
    for(; *output != '\0'; output++) {
        fb_write_cell(position++, *output, font);
        fb_move_cursor(position);
    }
}
