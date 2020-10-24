#include "pathfinder.h"

bool empty(t_file *data) {
    if (mx_strlen(data->file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(data->name);
        mx_printerr(" is empty\n");
        return 1;
    }
    else
        return 0;
}
