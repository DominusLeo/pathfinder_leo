#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    char *temp = NULL;
    int count = 0;

    if(!str || !sub)
        return -1;
    temp = (char *) str;
    for (; (temp = mx_strstr(temp, sub)) != NULL; temp++, count++);
    return count;
}