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

typedef struct file0 {
    int fd;
    char *name;
    char *file;
    char **file_lines;
} file0;

void mx_all_errors(int argc, file0 *data);
