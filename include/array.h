#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define array_find(arr,value)( array_find_impl(arr, sizeof(arr)/sizeof((arr)[0]), value) )
#define bubble_sort(arr)( bubble_sort_impl(arr, sizeof(arr)/sizeof((arr)[0])) )
#define merge_sort(arr) merge_sort_impl(arr, sizeof(arr)/sizeof((arr)[0]))
#define array_copy_range(src, start, end) array_copy_range_impl(src, start, end, sizeof(src)/sizeof((src)[0]))

/**
 * @brief Finds a value in an int array
 * @param arr Array to search in
 * @param n Size of the array
 * @param value Value to find
 * @return Index of the value, or -1 if not found
 */
int array_find_impl(int *arr, size_t n, int value);
void bubble_sort_impl(int *arr, size_t n);
int* merge_sort_impl(int *arr, size_t n);
int* array_copy_range_impl(int *src, size_t start, size_t end, size_t n);
int* merge_array(int* left, size_t left_size, int* right, size_t right_size, size_t n);

#endif
