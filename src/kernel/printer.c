#include "headers/io.h"
#include "headers/printer.h"

unsigned char color = ((FB_BLACK & 0x0F) << 4) | (FB_LIGHT_GREY & 0x0F);

void prn_set_color(unsigned char bg_color, unsigned char fg_color) {
    color = ((bg_color & 0x0F) << 4) | (fg_color & 0x0F);
}

void prn_clear_screen() {
    unsigned char output_color = color;
    color = ((FB_BLACK & 0x0F) << 4) | (FB_LIGHT_GREY & 0x0F);
    unsigned short i;
    for(i = MAX_COLUMNS * MAX_ROWS - 1; i > 0; i--) {
        prn_print_char(i, ' ');
    }
    prn_print_char(0, ' ');
    color = output_color;
    prn_move_cursor(0);
}

void prn_print_str(char* output, unsigned short position) {
    char* character;
    for(character = output; *character != '\0'; character++) {
        prn_print_char(position++, *character);
        prn_move_cursor(position);
    }
}

void prn_print_char(unsigned short position, char c) {
    unsigned char* frameBuffer = (char*) FB_MEMORY_MAPPED_IO;
    frameBuffer[position * 2] = c;
    frameBuffer[position * 2 + 1] = color;
}

void prn_move_cursor(unsigned short position) {
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    0x0000);
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    position & 0x00FF);
}