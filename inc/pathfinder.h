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
    int *lengts;
    char *name;
    char *file;
    char *bridges;
    char **file_lines;
    char **all_bridges;
} file0;

/*typedef struct bridges {
}bridges;*/

void mx_all_errors(file0 *data);
