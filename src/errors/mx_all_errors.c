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
        flag->space = 0;
        flag->tire = 1;
        flag->word1 = 1;
        flag->word2 = 1;
        flag->koma = 1;
        flag->num = 1;
        for (int j = 0; lines[i][j]; j++) {
            if (mx_isspace(lines[i][j]))
                flag->space = 1;
            mx_printint(1);
            if(lines[i][j] == '-')
                flag->tire = 0;
            mx_printint(2);
            if (lines[i][j] == ',')
                flag->koma = 0;
            mx_printint(3);
            for (; lines[i][j] != '-'; j++)
                if (mx_isdigit(lines[i][j]) || mx_isalpha(lines[i][j])) {
                    flag->word1 = 0;
                    j++;
                }
//            mx_printint(4);
//            for(; lines[i][j] != ','; j++)
//                if (mx_isdigit(lines[i][j]) || mx_isalpha(lines[i][j])) {
//                flag->word2 = 0;
//                j++;
//                }
//            mx_printint(5);
//            for (; lines[i][j] != '\n'; j++)
//                if (mx_isdigit(lines[i][j]))
//                    flag->num = 0;
//            mx_printint(6);
//            if (flag->num + flag->koma + flag->word2 + flag->word1 + flag->tire
//            + flag->space > 0) {
//                mx_printerr("error: line ");
//                mx_printerr(mx_itoa(i + 1));
//                mx_printerr(" is not valid\n");
//                return 1;
//            }
        }
    }
    return 0;
}

void mx_all_errors(int argc, char *argv[]) {
    if (invalid_argc(argc))
        return;
    if (not_exist(argv))
        return;
    if (empty(argv))
        return;
    if (invalid_1(argv))
        return;
    if (invalid_n(argv))
        return;
    printf("next\n");
}
