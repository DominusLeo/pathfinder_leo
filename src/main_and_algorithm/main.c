#include "pathfinder.h"

int main (int argc, char *argv[]) {
    t_file *data = NULL;

    if (invalid_argc(argc))
        return 0;
    if (not_exist(argv))
        return 0;
    data = init_start(argv);
    if (mx_all_errors(data))
        return 0;
    system("leaks -q pathfinder");
    return 0;
}
