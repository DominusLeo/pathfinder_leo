#include "pathfinder.h"

static void print_shortest_path(t_matrixxx *matrix, t_matrix *matrix0);
static bool check_shortest_path(t_matrixxx *matrix, int k, t_matrix *matrix0);
static void print_path_and_route(t_matrixxx *matrix, t_matrix *matrix0);
static void print_distance(t_matrixxx *matrix, t_matrix *matrix0);

void mx_output_results(t_matrixxx *matrix, t_matrix *matrix0) {
    for (int i = 0; i < matrix0->count_islands; i++) {
        for (int j = i + 1; j < matrix0->count_islands; j++) {
            matrix->route = (int *)malloc(sizeof(int) * (matrix0->count_islands));
            matrix->len = 1;
            matrix->route[0] = j;
            matrix->route[matrix->len] = i;
            print_shortest_path(matrix, matrix0);
            free(matrix->route);
        }
    }
}

static void print_shortest_path(t_matrixxx *matrix, t_matrix *matrix0) {
    for (int k = 0; k < matrix0->count_islands; k++) {
        if (k != matrix->route[matrix->len] && check_shortest_path(matrix, k, matrix0)) {
            matrix->route[++matrix->len] = k;
            print_shortest_path(matrix, matrix0);
            matrix->len--;
        }
    }
    if (matrix->route[matrix->len] != matrix->route[0]) {
        return;
    }
    print_path_and_route(matrix, matrix0);
    print_distance(matrix, matrix0);
}

static bool check_shortest_path(t_matrixxx *matrix, int k, t_matrix *matrix0) {
    int i = matrix->route[matrix->len];
    int j = matrix->route[0];

    if (matrix0->matrix[i][k] == matrix0->final_matrix[i][j] - matrix0->final_matrix[k][j]) {
        return true;
    }
    return false;
}

static void print_path_and_route(t_matrixxx *matrix, t_matrix *matrix0) {
    for (int i = 0; i++ < 40; mx_printstr("="));
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(matrix0->unique_isl[matrix->route[1]]);
    mx_printstr(" -> ");
    mx_printstr(matrix0->unique_isl[matrix->route[matrix->len]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < matrix->len + 1; ) {
        mx_printstr(matrix0->unique_isl[matrix->route[i]]);
        ++i < matrix->len + 1 ? mx_printstr(" -> ") : mx_printstr("");
    }
    mx_printstr("\n");
}

static void print_distance(t_matrixxx *matrix, t_matrix *matrix0) {
    int sum = 0;
    mx_printstr("Distance: ");
    for (int i = 1; i < matrix->len; i++){
        mx_printint(matrix0->matrix[matrix->route[i]][matrix->route[i + 1]]);
        sum += matrix0->matrix[matrix->route[i]][matrix->route[i + 1]];
        if (i < matrix->len - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    for (int i = 0; i++ < 40; mx_printstr("="));
    mx_printstr("\n");
}
