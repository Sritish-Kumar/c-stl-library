#include "array.h"
#include <stdlib.h>

int array_find(const int *arr, size_t n, int value) {
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == value) return (int)i;
    }
    return -1;
}

static int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void array_sort(int *arr, size_t n) {
    qsort(arr, n, sizeof(int), compare_ints);
}

void array_reverse(int *arr, size_t n) {
    for (size_t i = 0; i < n/2; i++) {
        int tmp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = tmp;
    }
}
