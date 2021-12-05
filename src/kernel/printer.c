#include "headers/io.h"
#include "headers/printer.h"

unsigned char prn_color = ((BLACK & 0x0F) << 4) | (LIGHT_GREY & 0x0F);
unsigned char prn_curr_row = 0;
unsigned char prn_curr_column = 0;

void prn_clear_screen() {
    unsigned char output_color = prn_color;
    prn_set_color(BLACK, LIGHT_GREY);
    prn_move_cursor(MAX_ROWS - 1, MAX_COLUMNS - 1);

    for(short i = MAX_COLUMNS * MAX_ROWS; i > 0; i--) {
        prn_delete_char();
    }

    prn_color = output_color;
}

void prn_set_color(unsigned char bg_color, unsigned char fg_color) {
    prn_color = ((bg_color & 0x0F) << 4) | (fg_color & 0x0F);
}

void prn_move_cursor(unsigned char row, unsigned char column) {
    prn_curr_row = row;
    prn_curr_column = column;
    prn_refresh_cursor();
}

void prn_refresh_cursor() {
    unsigned short position = prn_curr_row * 80 + prn_curr_column;

    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    0x0000);
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    position & 0x00FF);
}

void prn_delete_char() {
    if(prn_curr_column == 0 && prn_curr_row == 0)
        return;

    prn_cursor_dec();
    prn_print_char(' ');
}

void prn_print_char(char symbol) {
    unsigned char* frameBuffer = (char*) FB_MEMORY_MAPPED_IO;
    unsigned short position = prn_curr_row * 80 + prn_curr_column;
    frameBuffer[position * 2] = symbol;
    frameBuffer[position * 2 + 1] = prn_color;
}

void prn_print_str(char* output) {
    for(char* symbol = output; *symbol != '\0'; symbol++) {
        prn_print_char(*symbol);
        prn_cursor_inc();
    }
}

void prn_cursor_inc() {
    if(prn_curr_column == MAX_COLUMNS - 1 && prn_curr_row == MAX_ROWS - 1)
        return;

    if(prn_curr_column < MAX_COLUMNS - 1) {
        prn_curr_column++;
    }
    else {
        prn_curr_column = 0;
        prn_curr_row++;
    }
    prn_refresh_cursor();
}

void prn_cursor_dec() {
    if(prn_curr_column == 0 && prn_curr_row == 0)
        return;

    if(prn_curr_column > 0) {
        prn_curr_column--;
    }
    else {
        prn_curr_column = MAX_COLUMNS - 1;
        prn_curr_row--;
    }
    prn_refresh_cursor();
}
