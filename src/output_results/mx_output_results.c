#include "pathfinder.h"

static bool check_shortest_path(int k, t_matrix *matrix0) {
    int i = matrix0->route[matrix0->len];
    int j = matrix0->route[0];

    if (matrix0->matrix[i][k] == matrix0->final_matrix[i][j] -
        matrix0->final_matrix[k][j]) {
        return true;
    }
    return false;
}

static void print_path_and_route(t_matrix *matrix0) {
    for (int i = 0; i++ < 40; mx_printstr("="));
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(matrix0->unique_isl[matrix0->route[1]]);
    mx_printstr(" -> ");
    mx_printstr(matrix0->unique_isl[matrix0->route[matrix0->len]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < matrix0->len + 1; ) {
        mx_printstr(matrix0->unique_isl[matrix0->route[i]]);
        ++i < matrix0->len + 1 ? mx_printstr(" -> ") : mx_printstr("");
    }
    mx_printstr("\n");
}

static void print_distance(t_matrix *matrix0) {
    int sum = 0;
    mx_printstr("Distance: ");
    for (int i = 1; i < matrix0->len; i++){
        mx_printint(matrix0->matrix[matrix0->route[i]][matrix0->route[i + 1]]);
        sum += matrix0->matrix[matrix0->route[i]][matrix0->route[i + 1]];
        if (i < matrix0->len - 1)
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

static void print_shortest_path(t_matrix *matrix0) {
    for (int k = 0; k < matrix0->count_islands; k++) {
        if (k != matrix0->route[matrix0->len] &&
            check_shortest_path(k, matrix0)) {
            matrix0->route[++matrix0->len] = k;
            print_shortest_path(matrix0);
            matrix0->len--;
        }
    }
    if (matrix0->route[matrix0->len] != matrix0->route[0]) {
        return;
    }
    print_path_and_route(matrix0);
    print_distance(matrix0);
}

void mx_output_results(t_matrix *matrix0) {
    for (int i = 0; i < matrix0->count_islands; i++) {
        for (int j = i + 1; j < matrix0->count_islands; j++) {
            matrix0->route = (int *)malloc(sizeof(int) *
                    (matrix0->count_islands));
            matrix0->len = 1;
            matrix0->route[0] = j;
            matrix0->route[matrix0->len] = i;
            print_shortest_path(matrix0);
            free(matrix0->route);
        }
    }
}

