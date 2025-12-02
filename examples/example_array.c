#include "array.h"
#include <stdio.h>

int main() {
    int arr[] = {3, 1, 4, 1, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Index of 4: %d\n", array_find(arr, 4));

    printf("Sorting array...\n");
    bubble_sort(arr);
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
