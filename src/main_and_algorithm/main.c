#include "pathfinder.h"

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
    mat->final_matrix = floyd_algo(mat);
    mx_output_results(mat);
//    system("leaks -q pathfinder");
    return 0;
}
