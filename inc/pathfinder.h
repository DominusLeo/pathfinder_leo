#pragma once

#include "libmx.h"

typedef struct format_flags {
    int word1;
    int word2;
    int tire;
    int koma;
    int num;
    int space;
    int line;
} format_flags;

void mx_all_errors(int argc, char *argv[]);
