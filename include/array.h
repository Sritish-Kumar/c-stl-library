#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define array_find(arr,value)( array_find_impl(arr, sizeof(arr)/sizeof((arr)[0]), value) )

#define merge_sort(arr) merge_sort_impl(arr, sizeof(arr)/sizeof((arr)[0]))

int array_find_impl(const int *arr, size_t n, int value);

void merge_sort_impl(int *arr, size_t n);

#endif
