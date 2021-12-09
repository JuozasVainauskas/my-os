#include "headers/printer.h"
#include "headers/gdt.h"

int kmain() {
    gdt_init();
    char output[] = "Text_";
    prn_clear_screen();
    prn_set_color(BLACK, LIGHT_GREY);
    prn_print_str(output);
    prn_delete_char();
    return 0;
}
