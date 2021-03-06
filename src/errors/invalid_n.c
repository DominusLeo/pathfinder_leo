#include "pathfinder.h"

void print_error_line(int i) {
    char *line;

    line = mx_itoa(i + 1);
    mx_printerr("error: line ");
    mx_printerr(line);
    mx_printerr(" is not valid\n");
    free(line);
}

static int smth(t_file *data, int i) {
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
    if (tire + word1 + num + word2 > 0 || mx_strcmp
        (data->all_bridges[(i - 1) * 2], data->all_bridges[i * 2 - 1]) == 0)
        return 1;
    return 0;
}

bool invalid_n(t_file *data) {
    for (int i = 1; i < mx_count_words(data->file, '\n'); i++) {
        if (smth(data, i) || data->isl_lengts[i-1] < 0) {
            print_error_line(i);
            return 1;
        }
    }
    return 0;
}
