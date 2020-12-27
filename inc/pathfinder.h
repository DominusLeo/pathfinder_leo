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
    char *isl_lengts_char;
    char **lengts;
    char **file_lines;
    char **all_bridges;
    char **all_bridges_sort;
}              t_file;

typedef struct s_matrix {
    int count_islands;
    int **matrix;
    long **final_matrix;
    char **unique_isl;
}              t_matrix;

//
typedef struct s_matrixxx {
    int len;
    int *route;
}              t_matrixxx;
//

t_file *init_start(char *argv[]);
t_matrix *init_matrix(t_file *data);
t_matrix *fill_matrix (t_file *data, t_matrix *mat);

long **floyd_algo(t_matrix *mat);
bool mx_all_errors(t_file *data);
bool invalid_argc(int argc);
bool not_exist(char *argv[]);
bool empty(t_file *data);
bool invalid_1(char *str);
bool invalid_n(t_file *data);
bool invalid_number_islands(t_file *data);
bool duplicates(char **bridges, int count);
bool invalid_sum(int *arr, int count);
void print_error_line(int i);
//
void mx_output_results(t_matrixxx *matrixxx, t_matrix *matrix0);
