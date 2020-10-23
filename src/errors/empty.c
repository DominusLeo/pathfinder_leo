#include "pathfinder.h"

bool empty(t_file *data) {
    if (mx_strlen(data->file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(data->name);
        mx_printerr(" is empty\n");
        //system("leaks -q pathfinder");
        return 1;
    }
    else
        //system("leaks -q pathfinder");
        return 0;
}
