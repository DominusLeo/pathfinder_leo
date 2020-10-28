#include "pathfinder.h"

static void output (t_file *data, t_matrix *mat) {
    for(int i = 0; i <= data->pairs_count; i++) {
        printf("line[%d] |%s|\n", i, data->file_lines[i]);
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
    system("leaks -q pathfinder");
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
    mat = fill_matrix(data, mat);

    output(data, mat);
    return 0;
}
