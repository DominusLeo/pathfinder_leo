#include "pathfinder.h"

static void init_bridges(t_file *data) {
    data->file_lines = mx_strsplit(data->file, '\n');
    data->bridges = mx_strnew(mx_strlen(data->file));

    for (int i = 0; data->file[i]; i++)
        (!mx_isalpha(data->file[i])) ?
        (data->bridges[i] = '-') : (data->bridges[i] = data->file[i]);
    data->all_bridges = mx_strsplit(data->bridges, '-');
    data->all_bridges_sort = mx_strsplit(data->bridges, '-');
}

static void init_arr_lengts(t_file *data) {
    data->lengt = mx_strnew(mx_strlen(data->file));

    for (int i = 0; data->file[i]; i++)
        (!mx_isdigit(data->file[i])) ?
        (data->lengt[i] = ' ') : (data->lengt[i] = data->file[i]);
    for (; mx_isdigit(*data->lengt); data->lengt++);
    data->lengts = mx_strsplit(data->lengt, ' ');
    data->isl_lengts = (int *)malloc(sizeof(int *) * data->pairs_count);
    for (int i = 0; i < data->pairs_count; i++) {
        data->isl_lengts[i] = mx_atoi(data->lengts[i]);
    }
}

t_file *init_start(char *argv[]) {
    t_file *data = (t_file *)malloc(sizeof(t_file));

    data->name = argv[1];
    data->file = mx_file_to_str(argv[1]);
    if (empty(data))
        exit(0);
    data->pairs_count = mx_count_words(data->file, '\n') - 1;
    init_bridges(data);
    data->count_islands = mx_atoi(data->file_lines[0]);
    init_arr_lengts(data);
    return data;
}
