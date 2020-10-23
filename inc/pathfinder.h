#pragma once

#include "libmx.h"

typedef struct file0 {
    int fd;//?
    int *isl_lengts;
    char *lengt;
    char *name;
    char *file;
    char *bridges;
    char **lengts;
    char **file_lines;
    char **all_bridges;
} file0;

/*typedef struct bridges {
}bridges;*/

file0 *init_start(char *argv[]);
void mx_all_errors(struct file0 *data);
bool invalid_argc(int argc);
bool not_exist(char *argv[]);
bool empty(struct file0 *data);
bool invalid_1(char *str);//INT_MAX
bool invalid_n(struct file0 *data);//INT_MAX + Dup Bridges
bool invalid_number_islands(struct file0 *data);
