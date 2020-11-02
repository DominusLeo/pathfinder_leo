#include "pathfinder.h"

//static long mx_min (long a, long b) {
//    return (a < b) ? a : b;
//}

static void smth(t_matrix *mat) {
    mat->final_matrix = malloc(sizeof(long *) * mat->count_islands);

    for (int i = 0; i < mat->count_islands; i++) {
        mat->final_matrix[i] = malloc(sizeof(long ) * mat->count_islands);
        for (int j = 0; j < mat->count_islands; j++)
            mat->final_matrix[i][j] = mat->matrix[i][j];
    }
}

long **floyd_algo(t_matrix *mat, t_list_mat *out) {
    long sum;

    smth (mat);
    for (int i = 0; i < mat->count_islands; i++)
        for (int j = i; j < mat->count_islands; j++) {
            for (int k = 0; k < mat->count_islands; k++) {
                sum = mat->final_matrix[i][k] + mat->final_matrix[j][i];
                if (sum <= mat->final_matrix[j][k]) {
                    if (j > k && i != j && (i > k || (i == 0 && k == 0))) {
                        printf("|%-12s| -> |%-12s|",
                               mat->unique_isl[i], mat->unique_isl[j]);
                        printf(" %d %d %d\n", i, j, k);
                    }
                    mat->final_matrix[k][j] = sum;
                    mat->final_matrix[j][k] = sum;
                }
            }
        }

//    for (int i = 0; i < mat->count_islands; i++)
//        for (int j = 0; j < mat->count_islands; j++) {
//            for (int k = 0; k < mat->count_islands; k++) {
//
//                if (mat->final_matrix[j][k] == mat->matrix[j][k]
//                                    && i != j && i != k && j != k) {
//                    printf("|%-12s| |%-12s| |%-5d|\n",
//                    mat->unique_isl[j], mat->unique_isl[k], mat->matrix[j][k]);
//                }
//            }
//        }
//    mx_out(mat);
    return mat->final_matrix;
}
