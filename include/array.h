#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define array_find(arr,value)( array_find_impl(arr, sizeof(arr)/sizeof((arr)[0]), value) )
#define bubble_sort(arr)( bubble_sort_impl(arr, sizeof(arr)/sizeof((arr)[0])) )

/**
 * @brief Finds a value in an int array
 * @param arr Array to search in
 * @param n Size of the array
 * @param value Value to find
 * @return Index of the value, or -1 if not found
 */
int array_find_impl(const int *arr, size_t n, int value);
void bubble_sort_impl(int *arr, size_t n);




#endif
