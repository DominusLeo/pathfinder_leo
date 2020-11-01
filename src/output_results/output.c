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

    for (int ii = 0; ii < mat->count_islands; ii++) {
       for (int jj = 0; jj < mat->count_islands; jj++) {
           if (mat->final_matrix[ii][jj] == mat->matrix[ii][jj] && ii < jj) {
               out(mat, ii, jj);
           }
           else if (mat->matrix[ii][jj] == INT_MAX) {

           }
       }
   }
}
