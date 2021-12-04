#ifndef OS_WRITER_H
#define OS_WRITER_H

#define MAX_COLUMNS 80
#define MAX_ROWS 25

#include "font.h"

void clear_screen();
void print_str(char* output, unsigned short position, Font font);

#endif
