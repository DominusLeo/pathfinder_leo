#include "pathfinder.h"

static void start_output (t_file *data, t_matrix *mat) {
    for(int i = 0; i <= data->pairs_count; i++)
        printf("line[%d] |%s|\n", i, data->file_lines[i]);
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
}
static void mid_output (t_file *data, t_matrix *mat) {
    printf("\n\t     ");
    for(int i = 0; i < mat->count_islands; i++)
        printf("%-12s ", mat->unique_isl[i]);
    printf("\n");
    for(int i = 0; i < data->count_islands; i++) {
        for (int j = 0; j < data->count_islands; j++) {
            if (j == 0)
                printf("%-12s ", mat->unique_isl[i]);
            printf("%-12lu", mat->final_matrix[i][j]);
        }
        printf("\n");
    }
}

void final_output(t_matrix *mat) {
    for (int i = 0; i < mx_pow(mat->count_islands, 1); i++) {
        mx_printstr("========================================\n");
        mx_printstr("Path: ");

//        mx_printstr(" -> ");

        mx_printstr("\nRoute: ");

        mx_printstr("\nDistance: ");

        mx_printstr("\n========================================\n");
    }
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
    mat = init_matrix(data);//1/2 leak
    mat = fill_matrix(data, mat);
    mat->final_matrix = floyd_algo(mat);
    start_output(data, mat);
    mid_output(data, mat);
    final_output(mat);

    system("leaks -q pathfinder");
    return 0;
}
