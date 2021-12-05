#include "headers/printer.h"

int kmain() {
    char output[] = "Text";
    prn_clear_screen();
    prn_set_color(BLACK, LIGHT_GREY);
    prn_print_str(output);
    return 0;
}
