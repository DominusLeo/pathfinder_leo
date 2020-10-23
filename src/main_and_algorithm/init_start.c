#include "pathfinder.h"

static void init_bridges(t_file *data) {
    data->file_lines = mx_strsplit(data->file, '\n');
    data->bridges = mx_strnew(mx_strlen(data->file));
    for (int i = 0; data->file[i]; i++) {
        if (!mx_isalpha(data->file[i]))
            data->bridges[i] = '-';
        else
            data->bridges[i] = data->file[i];
    }
    printf("bridges = |%s|\n", data->bridges);
    data->all_bridges = mx_strsplit(data->bridges, '-');
    for (int i = 0; i < (mx_count_words(data->file, '\n') - 1) * 2; i++)
        printf("word %d = |%s|\n", i, data->all_bridges[i]);
}

static void init_arr_lengts(t_file *data) {
    data->lengt = mx_strnew(mx_strlen(data->file));
    for (int i = 0; data->file[i]; i++) {
        if (!mx_isdigit(data->file[i]))
            data->lengt[i] = ' ';
        else
            data->lengt[i] = data->file[i];
    }
    data->lengt++;
    printf("nums = |%s|\n", data->lengt);
    data->lengts = mx_strsplit(data->lengt, ' ');
    data->isl_lengts = (int *)malloc(mx_count_words(data->file, '\n') - 1);
    for (int i = 0; i < (mx_count_words(data->file, '\n') - 1); i++) {
        data->isl_lengts[i] = mx_atoi(data->lengts[i]);
        printf("lengt %d = %d\n", i, data->isl_lengts[i]);
    }
}

t_file *init_start(char *argv[]) {
    t_file *data = (t_file *)malloc(sizeof(t_file));

    data->name = argv[1];
    data->file = mx_file_to_str(argv[1]);
    if (empty(data))
        exit(0);
    data->fd = open(argv[1], O_RDONLY);
    init_bridges(data);
    init_arr_lengts(data);

    return data;
}
