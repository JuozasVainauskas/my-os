#include "headers/font.h"

Font makeFont(unsigned char bg_color, unsigned char fg_color) {
    Font font;
    font.bg_color = bg_color;
    font.fg_color = fg_color;
    return font;
};
