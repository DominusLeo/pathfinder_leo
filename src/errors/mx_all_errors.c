#include "pathfinder.h"
/*bool duplicates(char *argv[]) {


    return 0;
}*/

/*bool invalid_sum(char *argv[]) {

    return 0;
}*/

void mx_all_errors(struct file0 *data) {
//    printf("file:\n%s\n", data->file);
    if (invalid_1(data->file_lines[0]))
        return;
    if (invalid_n(data))
        return;
    if (invalid_number_islands(data))
        return;
//    if (duplicates())
//        return;
//    if(invalid_sum(argv))
//        return;
        mx_print_unicode_str("\n4053 4053 4053 4053 4053 4053 4053 4053 4053\n"
                             "78008 hello world 78008\n"
                             "4053 4053 4053 4053 4053 4053 4053 4053 4053\n\n");
}
