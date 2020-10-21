#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;

    if (!str || !sub)
        return -1;
    for (; *str; str++)
        if (mx_strncmp(str, sub, mx_strlen(sub)) == 0)
            count++;
    return count;
}
