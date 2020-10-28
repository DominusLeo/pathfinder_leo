#include "pathfinder.h"

t_matrix *init_matrix(t_file *data) {
    t_matrix *mat = (t_matrix *) malloc(sizeof(t_file));
    mat->matrix = (int **) malloc(sizeof(int *) * data->count_islands);
    mat->count_islands = data->count_islands;

    for (int i = 0; i < data->count_islands; i++) {
        mat->matrix[i] = (int *)malloc(sizeof(int) * data->count_islands);
//    system("leaks -q pathfinder");
        for (int j = 0; j < data->pairs_count * 2 + 2; j++)
            (i == j) ? (mat->matrix[i][j] = 0) : (mat->matrix[i][j] = INT_MAX);
    }
    mat->unique_isl = mx_unique_elements(data->all_bridges, mat->count_islands);
    mx_str_rotate(data->file_lines, data->pairs_count + 1, -1);
    return mat;
}
