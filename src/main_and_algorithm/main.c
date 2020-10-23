#include "pathfinder.h"

bool invalid_argc(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    else
        return 0;
}

int main (int argc, char *argv[]) {
    file0 *data = (file0 *)malloc(sizeof(struct file0));

    if (invalid_argc(argc))
        return 0;
    data->name = argv[1];
    data->file = mx_file_to_str(argv[1]);
    data->fd = open(argv[1], O_RDONLY);
    data->file_lines = mx_strsplit(data->file, '\n');
    mx_all_errors(argc, data);
    system("leaks -q pathfinder");
//    mx_print_unicode_str("4053 4053 4053 4053 4053 4053 4053 4053 4053\n"
//                             "78008 hello world 78008\n"
//                             "4053 4053 4053 4053 4053 4053 4053 4053 4053\n");
    return 0;
}
