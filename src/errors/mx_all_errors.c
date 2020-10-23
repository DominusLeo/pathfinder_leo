#include "pathfinder.h"

bool not_exist(struct file0 *data) {
    if (data->fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(data->name);
        mx_printerr(" does not exist\n");
        close(data->fd);
        //system("leaks -q pathfinder");
        return 1;
    }
    else
        //system("leaks -q pathfinder");
        return 0;
}
bool empty(struct file0 *data) {
        if (mx_strlen(data->file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(data->name);
        mx_printerr(" is empty\n");
        //system("leaks -q pathfinder");
        return 1;
    }
    else
        //system("leaks -q pathfinder");
        return 0;
}
bool invalid_1(char *str) {
    if (str[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        return 1;
    }
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
        if (!mx_isdigit(str[i])) {
            mx_printerr("error: line 1 is not valid\n");
            return 1;
        }
    return 0;
}

/*int smth(struct file0 *data, struct file0 *flag) {

    return 1;
}*/
bool invalid_n(struct file0 *data) {
    format_flags *flag = (format_flags *) malloc(sizeof(struct format_flags));
    int j;
    char *line = 0;

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
        for (; mx_isdigit(data->file_lines[i][j]); j++)
            flag->num = 0;
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

bool invalid_number_is(char *argv[]) {
    char **c = mx_strsplit(mx_file_to_str(argv[1]), '\n');
    int number = mx_atoi(c[0]);
    printf("num0 %d\n", number);


    return 0;
}
//bool invalid_sum(char *argv[]) {
//    return 0;
//}

void mx_all_errors(int argc, struct file0 *data) {
    //printf("file:\n%s\n", data->file);
    if (not_exist(data))
        return;
    if (empty(data))
        return;
    if (invalid_1(data->file_lines[0]))
        return;
    if (invalid_n(data))
        return;
//    if (invalid_number_is(argv))
//        return;
//    if(invalid_sum(argv))
//        return;
        mx_print_unicode_str("\n4053 4053 4053 4053 4053 4053 4053 4053 4053\n"
                             "78008 hello world 78008\n"
                             "4053 4053 4053 4053 4053 4053 4053 4053 4053\n\n");
    //system("leaks -q pathfinder");
}
