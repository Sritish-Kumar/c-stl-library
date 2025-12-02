#include "array.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    int arr[] = {3, 1, 4, 1, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    //array_find
    printf("Index of 4: %d\n", array_find(arr, 4));

    //bubble_sort
    printf("Array sorting...\n");
    bubble_sort(arr);
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    // Array copy range
    int *sub_arr = array_copy_range(arr, 1, 4);
    if (sub_arr != NULL) {
        printf("Subarray [1,4): ");
        for (size_t i = 0; i < 3; i++)
            printf("%d ", sub_arr[i]);
        printf("\n");
        free(sub_arr);
    } else {
        printf("Invalid range for array copy.\n");
    }

    // merge sort
    int *sorted = merge_sort(arr);
    if (sorted != NULL) {
        printf("Sorted array: ");
        for (size_t i = 0; i < n; i++)
            printf("%d ", sorted[i]);
        printf("\n");
        free(sorted);
    }

    return 0;
}
