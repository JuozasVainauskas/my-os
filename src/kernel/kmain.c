#include "headers/printer.h"

int kmain() {
    prn_clear_screen();
    char output[] = "Text";
    prn_set_color(FB_BLACK, FB_LIGHT_GREY);
    prn_print_str(output, 0);
    return 0;
}
