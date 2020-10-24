#include "pathfinder.h"

bool duplicates(char **bridges, int count) {
    /*for (int i = 0; bridges[i]; i++) {
        printf("bridge %d = %s\n", i, bridges[i]);
    }*/

    for (int i = 0; bridges[i]; i++) {
        for (int j = i + 2; j < count * 2 - 1; j+=2) {
//            printf("i = %d |%s| - i + 1 = %d |%s|\n", i, bridges[i], i + 1, bridges[i + 1]);
//            printf("i = %d |%s| - i + 1 = %d |%s|\n", j, bridges[j], j + 1, bridges[j + 1]);
            if ((mx_strcmp(bridges[j], bridges[i]) == 0 &&
                 mx_strcmp(bridges[j + 1], bridges[i + 1]) == 0)
                || (mx_strcmp(bridges[j], bridges[i + 1]) == 0
                    && mx_strcmp(bridges[j + 1], bridges[i]) == 0)) {
                mx_printerr("error: duplicate bridges\n");
                return 1;
            }
        }
    }
    return 0;
}
