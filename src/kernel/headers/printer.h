#ifndef OS_WRITER_H
#define OS_WRITER_H

#define MAX_COLUMNS 80
#define MAX_ROWS 25

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

void prn_clear_screen();
void prn_print_str(char* output, unsigned short position);
void prn_set_color(unsigned char bg_color, unsigned char fg_color);

#endif
