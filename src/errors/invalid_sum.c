#include "pathfinder.h"

bool invalid_sum(int *arr, int count) {
    unsigned long sum = 0;
    for (int i = 0; i < count;i++)
        sum += arr[i];
    if (sum > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        return 1;
    }
    return 0;
}
