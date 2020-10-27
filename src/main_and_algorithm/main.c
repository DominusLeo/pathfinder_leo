#include "pathfinder.h"

static char *temp_strcat (char *isl1, char *isl2) {
    char *temp = mx_strdup(isl1);

    temp = mx_strcat(temp, "-");
    temp = mx_strcat(temp, isl2);
    return temp;
}
static int len_of_two(char *isl1, char *isl2) {
    return mx_strlen(isl1) + mx_strlen(isl2) + 1;
}

t_matrix *fill_matrix (t_file *data, t_matrix *mat) {
    char *temp1 = NULL;
    char *temp2 = NULL;
    int z = 0;

    mx_str_rotate(data->file_lines, data->pairs_count + 1, -1);
    for (int i = 0; i < mat->count_islands; i++, z++)
        for (int j = 0; j < mat->count_islands; j++, z++)
            for (z = 0; z < data->pairs_count; z++) {
                temp1 = temp_strcat(mat->unique_isl[i], mat->unique_isl[j]);
                temp2 = temp_strcat(mat->unique_isl[j], mat->unique_isl[i]);
//                printf("temp1 = |%-24s| line = |%-24s| lengt = |%-4d|", temp1,
//                       data->file_lines[z], data->isl_lengts[z]);
                if (mx_strncmp(temp1, data->file_lines[z],
                    len_of_two(mat->unique_isl[i], mat->unique_isl[j])) == 0 ||
                    strncmp(temp2, data->file_lines[z],
                    len_of_two(mat->unique_isl[j], mat->unique_isl[i])) == 0) {
                    mat->matrix[i][j] = data->isl_lengts[z];
                    mat->matrix[j][i] = data->isl_lengts[z];
//                    printf(" Yes, z = %d", z);
//                    printf(" len of two = %d", len_of_two(mat->unique_isl[i],
//                                                          mat->unique_isl[j]));
                }
                free(temp1);
                free(temp2);
//                printf("\n");
            }
    return mat;
}

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
