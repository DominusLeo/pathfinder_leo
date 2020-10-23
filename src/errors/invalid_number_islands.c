#include "pathfinder.h"

bool invalid_number_islands(struct file0 *data) {
    int number = mx_atoi(data->file_lines[0]);
    int count = 1;
    char **temp = data->all_bridges;

    mx_bubble_sort(temp, (mx_count_words(data->file, '\n') - 1) * 2);
    for (int i = 1; temp[i]; i++)
        if (mx_strcmp(temp[i], temp[i - 1]) != 0)
            count++;
    if (number != count) {
        mx_printerr("error: invalid number of islands\n");
        return 1;
    }
//    printf("num0 = |%d| count = |%d|\n", number, count);
//    for (z = 0; temp[z]; z++)
//        printf("bBBridge %d = |%s|\n", z, temp[z]);
    return 0;
}
