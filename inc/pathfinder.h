#pragma once

#include "libmx.h"

typedef struct s_file {
    int pairs_count;
    int count_islands;
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

typedef struct s_matrix {
    int count_islands;
    int **matrix;

}              t_matrix;

/*typedef struct bridges {
}bridges;*/

t_file *init_start(char *argv[]);
bool mx_all_errors(t_file *data);
bool invalid_argc(int argc);
bool not_exist(char *argv[]);
bool empty(t_file *data);
bool invalid_1(char *str);
bool invalid_n(t_file *data);//INT_MAX gluks
void print_error_line(int i);
bool invalid_number_islands(t_file *data);
bool duplicates(char **bridges, int count);
bool invalid_sum(int *arr, int count);
