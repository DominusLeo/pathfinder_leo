#include "pathfinder.h"

static char *temp_strcat (char *isl1, char *isl2) {
    char *temp = mx_strnew(sizeof(char *) *
            (mx_strlen(isl1) + mx_strlen(isl2) + 1));

    temp = mx_strcat(temp, isl1);
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

    for (int i = 0; i < mat->count_islands; i++)
        for (int j = 0; j < mat->count_islands; j++)
            for (int z = 0; z < data->pairs_count; z++) {
                temp1 = temp_strcat(mat->unique_isl[i], mat->unique_isl[j]);
                temp2 = temp_strcat(mat->unique_isl[j], mat->unique_isl[i]);
                if (mx_strncmp(temp1, data->file_lines[z],
                    len_of_two(mat->unique_isl[i], mat->unique_isl[j])) == 0 ||
                    mx_strncmp(temp2, data->file_lines[z],
                    len_of_two(mat->unique_isl[j], mat->unique_isl[i])) == 0) {
                    mat->matrix[i][j] = data->isl_lengts[z];
                    mat->matrix[j][i] = data->isl_lengts[z];
                }
                free(temp1);
                free(temp2);
            }
    return mat;
}
