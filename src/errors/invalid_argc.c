#include "pathfinder.h"

bool invalid_argc(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    else
        return 0;
}
