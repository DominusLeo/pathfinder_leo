#pragma once

#include "libmx.h"

typedef struct s_file {
    int fd;//need it?
    int bridge_count;
    int *isl_lengts;
    char *lengt;
    char *name;
    char *file;
    char *bridges;
    char **lengts;
    char **file_lines;
    char **all_bridges;
    char **all_bridges_sort;
}              t_file;

/*typedef struct bridges {
}bridges;*/

t_file *init_start(char *argv[]);
bool mx_all_errors(t_file *data);
bool invalid_argc(int argc);
bool not_exist(char *argv[]);
bool empty(t_file *data);
bool invalid_1(char *str);
bool invalid_n(t_file *data);//INT_MAX gluks
bool invalid_number_islands(t_file *data);
bool duplicates(char **bridges, int count);
bool invalid_sum(int *arr, int count);
