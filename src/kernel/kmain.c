#include "headers/printer.h"
#include "headers/font.h"

int kmain() {
    char output[] = "Text";
    Font font = makeFont(FB_BLACK, FB_WHITE);
    print_str(output, 0, font);
    return 0;
}
