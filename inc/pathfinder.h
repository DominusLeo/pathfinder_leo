#pragma once

#include "libmx.h"

typedef struct s_file {
    int fd;//?
    int *isl_lengts;
    char *lengt;
    char *name;
    char *file;
    char *bridges;
    char **lengts;
    char **file_lines;
    char **all_bridges;
} t_file;

/*typedef struct bridges {
}bridges;*/

t_file *init_start(char *argv[]);
void mx_all_errors(t_file *data);
bool invalid_argc(int argc);
bool not_exist(char *argv[]);
bool empty(t_file *data);
bool invalid_1(char *str);//INT_MAX?
bool invalid_n(t_file *data);//Dup Bridges
bool invalid_number_islands(t_file *data);
