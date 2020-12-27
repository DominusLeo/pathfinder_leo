#include "pathfinder.h"

static void smth(t_matrix *mat) {
    mat->final_matrix = malloc(sizeof(long *) * mat->count_islands);

    for (int i = 0; i < mat->count_islands; i++) {
        mat->final_matrix[i] = malloc(sizeof(long ) * mat->count_islands);
        for (int j = 0; j < mat->count_islands; j++)
            mat->final_matrix[i][j] = mat->matrix[i][j];
    }
}

long **floyd_algo(t_matrix *mat) {
    long sum;

    smth (mat);
    for (int i = 0; i < mat->count_islands; i++)
        for (int j = 0; j < mat->count_islands; j++) {
            for (int k = 0; k < mat->count_islands; k++) {
                sum = mat->final_matrix[i][k] + mat->final_matrix[j][i];
                if (sum <= mat->final_matrix[j][k]) {
                    mat->final_matrix[k][j] = sum;
                    mat->final_matrix[j][k] = sum;
                }
            }
        }
    return mat->final_matrix;
}
