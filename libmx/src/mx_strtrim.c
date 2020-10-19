#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *clear_name;
    int lengt;
    int i;
    int c_left = 0;
    int c_right = 0;

    if(str == NULL)
        return NULL;
    lengt = mx_strlen(str);
    for(i = lengt - 1; mx_isspace(str[i]); i--, c_right++);
    i = 0;
    for (; mx_isspace(str[i]); str++, c_left++);
    clear_name = mx_strnew(lengt - c_right - c_left);
    clear_name = mx_strncpy(clear_name, str, lengt - c_right - c_left);
    return clear_name;
}
