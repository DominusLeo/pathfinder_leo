#include "pathfinder.h"

t_matrix *init_matrix(t_file *data) {
    t_matrix *mat = (t_matrix *)malloc(sizeof(t_file));
    mat->matrix = (int **)malloc(sizeof(int *) * data->count_islands);
    mat->count_islands = data->count_islands;

    for (int i = 0; i < data->count_islands; i++) {
        mat->matrix[i] = (int *)malloc(sizeof(int) * data->count_islands);
        for (int j = 0; j < data->pairs_count * 2 + 2; j++)
            (i == j) ? (mat->matrix[i][j] = 0) : (mat->matrix[i][j] = INT_MAX);
    }
    mat->unique_isl = mx_unique_elements(data->all_bridges, mat->count_islands);
    return mat;
}

int main (int argc, char *argv[]) {
    t_file *data = NULL;
    t_matrix *mat = NULL;

    if (invalid_argc(argc))
        return 0;
    if (not_exist(argv))
        return 0;
    data = init_start(argv);
    if (mx_all_errors(data))
        return 0;
    mat = init_matrix(data);
    for(int i = 0; i < data->count_islands; i++) {
        printf("island [%d] |%s|\n", i+1, mat->unique_isl[i]);
    }

    printf("\n\t     ");
    for(int i = 0; i < mat->count_islands; i++)
        printf("%-12s ", mat->unique_isl[i]);
    printf("\n");
    for(int i = 0; i < data->count_islands; i++) {
        for (int j = 0; j < data->count_islands; j++) {
            if (j == 0)
                printf("%-12s ", mat->unique_isl[i]);
            printf("%-12d", mat->matrix[i][j]);
        }
        printf("\n");
    }
//    data->pairs_count > data->count_islands ? printf("da %d", data->pairs_count) : printf("net %d", data->count_islands);
//    system("leaks -q pathfinder");
    return 0;
}
