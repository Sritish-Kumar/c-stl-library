#include "array.h"
#include <stdlib.h>
#include <stdbool.h>

/*
Linear Search Implementation with O(n) time complexity
*/
int array_find_impl(const int *arr, size_t n, int value) {
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == value) return (int)i;
    }
    return -1;
}

/*
Bubble Sort Implementation with -
O(n) best case when the array is already sorted
O(n^2) average and worst case
*/
void bubble_sort_impl(int *arr, size_t n){
    if (n == 0 || n == 1) return;

    for (size_t i = 0; i <= n - 2; i++) {
        bool isSorted = true;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                isSorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(isSorted) break;
    }
}
