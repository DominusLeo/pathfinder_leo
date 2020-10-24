#include "pathfinder.h"

bool not_exist(char *argv[]) {
    int fd = open(argv[1], 1);

    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        close(fd);
        return 1;
    }
    else
        return 0;
}
