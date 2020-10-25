#include "pathfinder.h"

t_matrix *init_matrix(t_file *data) {
    t_matrix *mat = (t_matrix *)malloc(sizeof(t_file));
    mat->matrix = (int **)malloc(sizeof(int *) * data->count_islands);
    printf("count = %d\n", data->count_islands);

    for (int i = 0; i < data->count_islands; i++) {
        mat->matrix[i] = (int *)malloc(sizeof(int) * data->count_islands);
        for (int j = 0; j < data->count_islands; j++) {
            if (i == j)
                mat->matrix[i][j] = 0;
            else
                mat->matrix[i][j] = INT_MAX;
            printf("%-11d", mat->matrix[i][j]);
        }
        printf("\n");
    }
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
    system("leaks -q pathfinder");
    return 0;
}
