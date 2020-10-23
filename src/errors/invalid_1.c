#include "pathfinder.h"

bool invalid_1(char *str) {
    if (str[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        return 1;
    }
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
        if (!mx_isdigit(str[i]) || mx_atoi(&str[i]) < 0) {
            mx_printerr("error: line 1 is not valid\n");
            return 1;
        }
    return 0;
}
