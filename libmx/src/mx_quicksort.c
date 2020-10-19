#include "libmx.h"

static void swap(char **arr, int i, int j, int *count) {
    char *tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    (*count)++;
}

static int partition(char **arr,int left, int right, int *count) {
    int i = left;
    int j = right + 1;

    while (i < j) {
        while (mx_strlen(arr[++i]) < mx_strlen(arr[left]) && i != right);
        while (mx_strlen(arr[--j]) > mx_strlen(arr[left]) && j != left);
        if (i < j && mx_strlen(arr[i]) != mx_strlen(arr[j]))
            swap(arr, i, j, count);
    }
    if (mx_strlen(arr[left]) > mx_strlen(arr[j]))
        swap(arr, left, j, count);
    return j;
}

static void sort(char **arr, int left, int right, int *count) {
    static int j = 0;

    if (left >= right)
        return;
    j = partition(arr, left, right, count);
    sort(arr, left, j - 1, count);
    sort(arr, j + 1, right, count);
}

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;

    if (!arr)
        return -1;
    sort(arr, left, right, &count);
    return count;
}
