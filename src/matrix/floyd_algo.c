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
        for (int j = 0; j < mat->count_islands; j++) {
            for (int k = 0; k < mat->count_islands; k++) {
                sum = mat->final_matrix[i][k] + mat->final_matrix[j][i];
                if (sum <= mat->final_matrix[j][k]) {
//                    if (j > k && i != j && (i > k || (i == 0 && k == 0))) {
//                        printf("|%-12s| -> |%-12s|",
//                               mat->unique_isl[i], mat->unique_isl[j]);
//                        printf(" %d %d %d\n", i, j, k);
//                    }
                    printf("|%-12s| ik %-12ld ij %-12ld jk %-12ld sum %-12ld |%-12s|\n",
                        mat->unique_isl[j], mat->final_matrix[i][k],
                        mat->final_matrix[j][i], mat->final_matrix[j][k],
                        sum, mat->unique_isl[k]);
                    mat->final_matrix[k][j] = sum;
                    mat->final_matrix[j][k] = sum;
                }
            }
        }
        }

//    for (int i = 0; i < mat->count_islands; i++)
//        for (int j = 0; j < mat->count_islands; j++) {
//            for (int k = 0; k < mat->count_islands; k++) {
//                sum = mat->final_matrix[i][k] + mat->final_matrix[j][i];
//                if (sum <= mat->final_matrix[j][k] && mat->matrix[i][k] != 0
//                    && mat->matrix[i][k] != INT_MAX) {
//                    printf("|%-12s| |%-5d|\n",
//                    mat->unique_isl[k], mat->matrix[i][k]);
////                    printf("jopa");
//                }
//            }
//        }
//    printf("\n\n");
//    mx_out(mat);
    return mat->final_matrix;
}
