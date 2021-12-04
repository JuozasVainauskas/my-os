#ifndef OS_FONT_H
#define OS_FONT_H

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

typedef struct {
    unsigned char bg_color;
    unsigned char fg_color;
} Font;

Font makeFont(unsigned char bg_color, unsigned char fg_color);

#endif