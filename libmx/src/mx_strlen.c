#include "libmx.h"

int mx_strlen(const char *s) {
    int lengt = 0;

    for (; s[lengt]; lengt++);
    return lengt;
}
