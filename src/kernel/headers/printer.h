#ifndef OS_WRITER_H
#define OS_WRITER_H

enum {
    FB_BLACK,
    FB_BLUE,
    FB_GREEN,
    FB_CYAN,
    FB_MAGENTA,
    FB_RED,
    FB_BROWN,
    FB_LIGHT_GREY,
    FB_DARK_GREY,
    FB_LIGHT_BLUE,
    FB_LIGHT_GREEN,
    FB_LIGHT_CYAN,
    FB_LIGHT_RED,
    FB_LIGHT_MAGENTA,
    FB_LIGHT_BROWN,
    FB_WHITE,
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
void prn_print_str(char* output, unsigned short position);
void prn_print_char(unsigned short position, char c);
void prn_move_cursor(unsigned short position);

#endif
