#include "pathfinder.h"

static int smth(struct file0 *data, int i) {
    int j = 0;
    int num = 1;
    int tire = 0;
    int word1 = 1;
    int word2 = 1;

    for (; mx_isalpha(data->file_lines[i][j]); j++)
        word1 = 0;
    (data->file_lines[i][j++] != '-') ? tire = 1 : 1;
    for (; mx_isalpha(data->file_lines[i][j]); j++)
        word2 = 0;
    (data->file_lines[i][j++] != ',') ? tire = 1: 1;
    for (; mx_isdigit(data->file_lines[i][j]); j++)
        num = 0;
    (data->file_lines[i][j] != '\0') ? tire = 1 : 1;
    if (tire + word1 + num + word2 > 0)
        return 1;
    return 0;
}

bool invalid_n(struct file0 *data) {
    char *line = 0;
    //long a = 0;

    for (int i = 1; i < mx_count_words(data->file, '\n'); i++)
        if (smth(data, i)) {
        line = mx_itoa(i + 1);
        mx_printerr("error: line ");
        mx_printerr(line);
        mx_printerr(" is not valid\n");
        free(line);
        return 1;
        }
    return 0;
}

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
