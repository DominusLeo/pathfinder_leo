#include "pathfinder.h"

bool invalid_argc(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    else
        return 0;
}

bool not_exist(char *argv[]) {
    int fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        close(fd);
        return 1;
    }
    else
        return 0;
}
bool empty(char *argv[]) {
    char *str = mx_file_to_str(argv[1]);

    if (mx_strlen(str) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        return 1;
    }
    else
        return 0;
}
bool invalid_1(char *argv[]) {
    char *str = mx_file_to_str(argv[1]);
    char *str1 = mx_strnew(mx_strlen(str));

    for (int i = 0; str[i] != '\n'; i++)
        str1[i] = str[i];
    str = mx_itoa(mx_atoi(str1));
    if (mx_strcmp(str, str1) != 0 || mx_atoi(str1) <= 0) {
        mx_printerr("error: line 1 is not valid\n");
        return 1;
    }
    else
        return 0;
}
bool invalid_n(char *argv[]) {
    format_flags *flag = malloc(sizeof(format_flags));
    char *str = mx_file_to_str(argv[1]);
    char **lines = mx_strsplit(str, '\n');

    for (int i = 1; i < mx_count_words(str, '\n'); i++) {
        for (int j = 0; lines[i][j]; j++) {
        flag->word1 = 1;
        flag->word2 = 1;
        flag->num = 1;
        flag->tire = 1;
            for (; mx_isalpha(lines[i][j]); j++)
                flag->word1 = 0;
            if (lines[i][j++] != '-')
                flag->tire = 0;
            for (; mx_isalpha(lines[i][j]); j++)
                flag->word2 = 0;
            if (lines[i][j++] != ',')
                flag->tire = 0;
            for (; mx_isdigit(lines[i][j]); j++)
                flag->num = 0;
            if (lines[i][j] != '\0')
                flag->tire = 0;
            if (flag->tire == 0 || flag->word1 + flag->word2 + flag->num > 0) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                return 1;
            }
        }
    }
    mx_del_strarr(&lines);
    lines = NULL;
    return 0;
}
/*bool invalid_number_is(char *argv[]) {
    unsigned long number;

    number = atoi()
    return 0;
}*/
bool invalid_sum(char *argv[]) {
    char **c = mx_strsplit(mx_file_to_str(argv[1]), '\n');
    int number = mx_atoi(c[0]);
    return 0;
}

void mx_all_errors(int argc, char *argv[]) {
    if (invalid_argc(argc))//1 leak
        return;
    if (not_exist(argv))
        return;
    if (empty(argv))
        return;
    if (invalid_1(argv))//3 leaks
        return;
    if (invalid_n(argv))//2 leaks
        return;
//    if (invalid_number_is(argv))
//        return;
    if(invalid_sum(argv))
        return;
    printf("next\n");
    //system("leaks -q pathfinder");
}
