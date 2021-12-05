#ifndef OS_WRITER_H
#define OS_WRITER_H

enum {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    MAGENTA,
    RED,
    BROWN,
    LIGHT_GREY,
    DARK_GREY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    LIGHT_BROWN,
    WHITE,
};

#define MAX_COLUMNS 80
#define MAX_ROWS 25
#define FB_MEMORY_MAPPED_IO     0x000B8000
#define FB_COMMAND_PORT         0x03D4
#define FB_DATA_PORT            0x03D5
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

void prn_set_color(unsigned char bg_color, unsigned char fg_color);
void prn_clear_screen();
void prn_print_str(char* output);
void prn_print_char(char c);
void prn_cursor_inc();
void prn_cursor_dec();
void prn_move_cursor(unsigned char row, unsigned char column);
void prn_refresh_cursor();

#endif
