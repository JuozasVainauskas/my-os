#include "headers/framebuffer.h"
#include "headers/printer.h"

unsigned char color = ((FB_BLACK & 0x0F) << 4) | (FB_LIGHT_GREY & 0x0F);

void prn_set_color(unsigned char bg_color, unsigned char fg_color) {
    color = ((bg_color & 0x0F) << 4) | (fg_color & 0x0F);
}

void prn_clear_screen() {
    unsigned short i = 0;
    for(; i < MAX_COLUMNS * MAX_ROWS; i++) {
        unsigned char clear_color = ((FB_BLACK & 0x0F) << 4) | (FB_LIGHT_GREY & 0x0F);
        fb_write_cell(i, ' ', clear_color);
    }
}

void prn_print_str(char* output, unsigned short position) {
    for(; *output != '\0'; output++) {
        fb_write_cell(position++, *output, color);
        fb_move_cursor(position);
    }
}