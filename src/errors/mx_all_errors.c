#include "pathfinder.h"

/*int smth(struct file0 *data, struct file0 *flag) {

    return 1;
}*/
bool invalid_n(struct file0 *data) {
    format_flags *flag = (format_flags *) malloc(sizeof(struct format_flags));
    int j;
    char *line = 0;
    //long a = 0;

    for (int i = 1; i < mx_count_words(data->file, '\n'); i++) {
        j = 0;
        flag->word1 = 1;
        flag->word2 = 1;
        flag->num = 1;
        flag->tire = 1;
        for (; mx_isalpha(data->file_lines[i][j]); j++)
            flag->word1 = 0;
        if (data->file_lines[i][j++] != '-')
            flag->tire = 0;
        for (; mx_isalpha(data->file_lines[i][j]); j++)
            flag->word2 = 0;
        if (data->file_lines[i][j++] != ',')
            flag->tire = 0;
        for (; mx_isdigit(data->file_lines[i][j]); j++) {
            flag->num = 0;
        }
        if (data->file_lines[i][j] != '\0')
            flag->tire = 0;
        if (flag->tire == 0 || flag->word1 + flag->word2 + flag->num > 0) {
            line = mx_itoa(i + 1);
            mx_printerr("error: line ");
            mx_printerr(line);
            mx_printerr(" is not valid\n");
            free(line);
            free(flag);
            return 1;
        }
    }
    free(line);
    free(flag);
    return 0;
}

bool invalid_number_islands(struct file0 *data) {
    int number = mx_atoi(data->file_lines[0]);
    int z = 0;
    int count = 0;

    printf("num0 |%d|\n", number);
    for (z = 0; data->all_bridges[z]; z++)
        printf("bridge %d = |%s|\n", z, data->all_bridges[z]);
    for (z = 0; data->all_bridges[z]; z++) {
        for (int i = z; data->all_bridges[i]; i++) {
            if (mx_strcmp(data->all_bridges[z], data->all_bridges[i]) == 0)
                count++;
        }
    }
    printf("count = |%d|\n", count/2);
//    for (z = 0; data->all_bridges[z]; z++)
//        printf("bridge %d = |%s|\n", z, data->all_bridges[z]);
    return 0;
}
/*bool duplicates(char *argv[]) {


    return 0;
}*/

/*bool invalid_sum(char *argv[]) {

    return 0;
}*/

void mx_all_errors(struct file0 *data) {
    printf("file:\n%s\n", data->file);
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
