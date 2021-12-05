#include "headers/printer.h"

int kmain() {
    char output[] = "Text";
    prn_clear_screen();
    prn_set_color(FB_BLACK, FB_LIGHT_GREY);
    prn_print_str(output, 0);
    return 0;
}
