#include "array.h"
#include <stdlib.h>

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
Merge Sort Implementation
*/

void merge_sort_impl(int *arr,size_t n){

    if (n==1)
    {
        return arr;
    }

    int mid = n/2;

    // int left[] = merge_sort_impl()
    // .... WIll update later 
    
}