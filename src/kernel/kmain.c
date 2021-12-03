#include "headers/printer.h"

int kmain() {
    char output[] = "Text";
    print_str(output, 0, FB_BLACK, FB_WHITE);
    return 0;
}
