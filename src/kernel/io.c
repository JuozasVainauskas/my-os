#include "headers/io.h"

unsigned char io_color = ((BLACK & 0x0F) << 4) | (LIGHT_GREY & 0x0F);
unsigned char io_curr_row = 0;
unsigned char io_curr_column = 0;

void io_clear_screen() {
    unsigned char output_color = io_color;
    io_set_color(BLACK, LIGHT_GREY);
    io_move_cursor(MAX_ROWS - 1, MAX_COLUMNS - 1);

    for(short i = MAX_COLUMNS * MAX_ROWS; i > 0; i--) {
        io_delete_char();
    }

    io_color = output_color;
}

void io_set_color(unsigned char bg_color, unsigned char fg_color) {
    io_color = ((bg_color & 0x0F) << 4) | (fg_color & 0x0F);
}

void io_move_cursor(unsigned char row, unsigned char column) {
    io_curr_row = row;
    io_curr_column = column;
    io_refresh_cursor();
}

void io_refresh_cursor() {
    unsigned short position = io_curr_row * 80 + io_curr_column;

    io_outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    io_outb(FB_DATA_PORT,    0x0000);
    io_outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    io_outb(FB_DATA_PORT,    position & 0x00FF);
}

void io_delete_char() {
    if(io_curr_column == 0 && io_curr_row == 0)
        return;

    io_cursor_dec();
    io_print_char(' ');
}

void io_print_char(char symbol) {
    unsigned char* frameBuffer = (unsigned char*) FB_MEMORY_MAPPED_IO;
    unsigned short position = io_curr_row * 80 + io_curr_column;
    frameBuffer[position * 2] = symbol;
    frameBuffer[position * 2 + 1] = io_color;
}

void io_print_str(char* output) {
    for(char* symbol = output; *symbol != '\0'; symbol++) {
        io_print_char(*symbol);
        io_cursor_inc();
    }
}

void io_cursor_inc() {
    if(io_curr_column == MAX_COLUMNS - 1 && io_curr_row == MAX_ROWS - 1)
        return;

    if(io_curr_column < MAX_COLUMNS - 1) {
        io_curr_column++;
    }
    else {
        io_curr_column = 0;
        io_curr_row++;
    }
    io_refresh_cursor();
}

void io_cursor_dec() {
    if(io_curr_column == 0 && io_curr_row == 0)
        return;

    if(io_curr_column > 0) {
        io_curr_column--;
    }
    else {
        io_curr_column = MAX_COLUMNS - 1;
        io_curr_row--;
    }
    io_refresh_cursor();
}
