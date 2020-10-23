#include "pathfinder.h"

/*bool duplicates(char *argv[]) {

    return 0;
}*/

bool invalid_sum(int *arr, int count) {
    unsigned long sum = 0;
    for (int i = 0; i < count;i++)
        sum += arr[i];
    printf("sum = %lu\n", sum);
    if (sum > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        return 1;
    }
    return 0;
}

void mx_all_errors(t_file *data) {
//    printf("file:\n%s\n", data->file);
    if (invalid_1(data->file_lines[0]))
        return;
    if (invalid_n(data))
        return;
    if (invalid_number_islands(data))
        return;
//    if (duplicates())
//        return;
    if(invalid_sum(data->isl_lengts, data->bridge_count))
        return;
        mx_print_unicode_str("\n4053 4053 4053 4053 4053 4053 4053 4053 4053\n"
                             "78008 hello world 78008\n"
                             "4053 4053 4053 4053 4053 4053 4053 4053 4053\n\n");
}
