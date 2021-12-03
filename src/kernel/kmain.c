#include "headers/printer.h"
#include "headers/font.h"

int kmain() {
    clear_screen();
    char output[] = "Text";
    Font font = makeFont(FB_BLACK, FB_LIGHT_GREY);
    print_str(output, 0, font);
    return 0;
}
