#include "pathfinder.h"

bool mx_all_errors(t_file *data) {
    if (invalid_1(data->file_lines[0]))
        return 1;
    if (invalid_n(data))
        return 1;
    if (invalid_number_islands(data))
        return 1;
    if (duplicates(data->all_bridges, data->pairs_count))
        return 1;
    if(invalid_sum(data->isl_lengts, data->pairs_count))
        return 1;
    mx_print_unicode_str("\n4053 4053 4053 4053 4053 4053 4053 4053 4053\n"
                             "78008 hello world 78008\n"
                             "4053 4053 4053 4053 4053 4053 4053 4053 4053\n\n");
    return 0;
}
