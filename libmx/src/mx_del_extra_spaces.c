#include "libmx.h"

static char to_space(char c) {
    if(mx_isspace(c))
        c = ' ';
    return c;
}
static int size_char(char *temp) {
    int count = 0;

    for(int i = 0; temp[i]; i++)
        if(mx_isspace(temp[i]))
            for (; mx_isspace(temp[i + 1]); i++, count++);
    return count;
}

char *mx_del_extra_spaces(const char *str) {
    char *clear_name;
    int count;
    int j = 0;
    char *temp = mx_strtrim(str);

    if(temp == NULL)
        return NULL;
    count = size_char(temp);
    clear_name = mx_strnew(count);
    for(int i = 0; temp[i]; i++, j++) {
        if(mx_isspace(temp[i])) {
            for (; mx_isspace(temp[i + 1]); i++);
        }
        temp[i] = to_space(temp[i]);
        clear_name[j] = temp[i];
    }
    free(temp);
    return clear_name;
}
