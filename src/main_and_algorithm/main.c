#include "pathfinder.h"

int main (int argc, char *argv[]) {
    file0 *data = NULL;

    if (invalid_argc(argc))
        return 0;
    if (not_exist(argv))
        return 0;
    data = init_start(argv);
    mx_all_errors(data);
    system("leaks -q pathfinder");
    return 0;
}
