#include "pathfinder.h"

static double mx_min (double a, double b) {
    return (a < b) ? a : b;
}

double **floyd_algo(t_matrix *mat) {
    mat->final_matrix =
            (double **)malloc(sizeof(double *) * mat->count_islands);
    for (int i = 0; i < mat->count_islands; i++) {
        mat->final_matrix[i] =
                (double *)malloc(sizeof(double ) * mat->count_islands);
        for (int j = 0; j < mat->count_islands; j++)
            mat->final_matrix[i][j] = mat->matrix[i][j];
    }
    for (int i = 0; i < mat->count_islands; i++)
        for (int j = 0; j < mat->count_islands; j++)
            for (int k = 0; k < mat->count_islands; k++)
                mat->final_matrix[i][j] = mx_min(mat->final_matrix[i][j],
                mat->final_matrix[i][k] + mat->final_matrix[k][j]);
    return mat->final_matrix;
}
