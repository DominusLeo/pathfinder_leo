#include "pathfinder.h"

bool invalid_number_islands(t_file *data) {
    int number = mx_atoi(data->file_lines[0]);
    int count = 1;
    char **temp = data->all_bridges_sort;

    mx_bubble_sort(temp, data->pairs_count * 2);
    for (int i = 1; temp[i]; i++)
        if (mx_strcmp(temp[i], temp[i - 1]) != 0)
            count++;
    if (number != count) {
        mx_printerr("error: invalid number of islands\n");
        return 1;
    }
    return 0;
}
