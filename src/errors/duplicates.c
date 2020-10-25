#include "pathfinder.h"

bool duplicates(char **bridges, int count) {
    for (int i = 0; bridges[i]; i+=2) {
        for (int j = i + 2; j < count * 2 - 1; j+=2) {
//            printf("|%s|-|%s|\n", bridges[i], bridges[i+1]);
//            printf("|%s|-|%s|\n\n", bridges[j], bridges[j+1]);
            if ((mx_strcmp(bridges[j], bridges[i]) == 0 &&
                 mx_strcmp(bridges[j + 1], bridges[i + 1]) == 0)
                || (mx_strcmp(bridges[j], bridges[i + 1]) == 0
                    && mx_strcmp(bridges[j + 1], bridges[i]) == 0)) {
                mx_printerr("error: duplicate bridges\n");
                return 1;
            }
        }
//        printf("------------------------------------------------\n");
    }
    return 0;
}
