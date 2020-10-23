#include "pathfinder.h"

file0 *init_start(char *argv[]) {
    file0 *data = (file0 *)malloc(sizeof(struct file0));
//    bridges *lengts = (bridges *)malloc(sizeof(struct bridges));

    data->name = argv[1];
    data->file = mx_file_to_str(argv[1]);
    if (empty(data))
        exit(0);
    data->fd = open(argv[1], O_RDONLY);
    data->file_lines = mx_strsplit(data->file, '\n');
    data->bridges = mx_strnew(mx_strlen(data->file));
    for (int i = 0; data->file[i]; i++) {
        if (!mx_isalpha(data->file[i]))
            data->bridges[i] = '-';
        else
            data->bridges[i] = data->file[i];
    }
    data->all_bridges = mx_strsplit(data->bridges, '-');
//    for (int i = 0; i < (mx_count_words(data->file, '\n') - 1) * 2; i++)
//        printf("word %d = |%s|\n", i, data->all_bridges[i]);
    return data;
}
