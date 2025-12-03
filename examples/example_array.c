#include "array.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    int arr[] = {3, 1, 4, 1, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // array print
    array_print(arr);
    
    //array_find
    printf("Index of 4: %d\n", array_find(arr, 4));

    //bubble_sort
    printf("Bubble sort\n");
    bubble_sort(arr);
    array_print(arr);
    
    // Array copy range
    int *sub_arr = array_copy_range(arr, 1, 4);
    if (sub_arr != NULL) {
        printf("Subarray [1,4): ");
        array_print(arr);
        free(sub_arr);  // free the allocated subarray
    } else {
        printf("Invalid range for array copy.\n");
    }

    // merge sort
    int *sorted = merge_sort(arr);
    if (sorted != NULL) {
        printf("Sorted array: ");
        array_print(arr);
        free(sorted); // user has to free the new allocated sorted array
    }

    return 0;
}
