#include "pathfinder.h"

static void out(t_matrix *mat, int i, int j) {
    mx_print_unicode_str("78008 78008 78008 78008 78008 78008 78008 "
                         "78008 78008 78008 78008 78008 78008 78008\n");
    mx_printstr("Path: ");
    mx_printstr(mat->unique_isl[i]);
    mx_printstr(" -> ");
    mx_printstr(mat->unique_isl[j]);

    mx_printstr("\nRoute: ");
    mx_printstr(mat->unique_isl[i]);
    mx_printstr(" -> ");
    mx_printstr(mat->unique_isl[j]);

    mx_printstr("\nDistance: ");
    mx_printint((int) mat->final_matrix[i][j]);

    mx_print_unicode_str("\n78008 78008 78008 78008 78008 78008 78008 "
                         "78008 78008 78008 78008 78008 78008 78008\n");
}

void mx_out(t_matrix *mat) {

    for (int i = 0; i < mat->count_islands; i++) {
       for (int j = 0; j < mat->count_islands; j++) {
           if (mat->final_matrix[i][j] == mat->matrix[i][j] && i < j)
               out(mat, i, j);
           else if (mat->final_matrix[i][j] < mat->matrix[i][j]) {
//                while (mat->final_matrix[i][j] != mat->matrix[i][j]) {
//                    mx_print_unicode_str(" 78008 fuck 78008 ");
//                }
           }
       }
   }
}

//========================================
