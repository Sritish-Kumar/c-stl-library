#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* -------------------------------------------------------------- --------------------------------------------------------------
Print Array Implementation
*/

void array_print_impl(int* arr, size_t n){
    printf("[ ");
    for(size_t i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

/* -------------------------------------------------------------- --------------------------------------------------------------
Linear Search Implementation with O(n) time complexity  
*/
int array_find_impl(int *arr, size_t n, int value)
{
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == value)
            return (int)i;
    }
    return -1;
}

/* -------------------------------------------------------------- --------------------------------------------------------------
Bubble Sort Implementation with -
O(n) best case when the array is already sorted
O(n^2) average and worst case
*/
void bubble_sort_impl(int *arr, size_t n){
    //base case (no need to sort)
    if (n == 0 || n == 1) return;

    for (size_t i = 0; i <= n - 2; i++) {
        bool isSorted = true;

        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                isSorted = false;

                //swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(isSorted) break;
    }
}

/* -------------------------------------------------------------- --------------------------------------------------------------
Array Copy Range Implementation
Takes arguments as src array, start index, end index and size of the array n
Returns a new allocated array containing elements from src[start] to src[end-1]
Returns NULL if the range is invalid
*/
int *array_copy_range_impl(int *src, size_t start, size_t end, size_t n)
{

    if ((end > n) || (start > end))
    {
        return NULL;
    }

    // new allocated memory size = end-start (exclusive of end)
    int *arr = (int *)calloc(end - start, sizeof(int));

    if (arr == NULL)
    {
        return NULL;
    }

    for (size_t i = start; i < end; i++)
    {
        arr[i - start] = src[i];
    }

    return arr;
}

/* -------------------------------------------------------------- --------------------------------------------------------------
 Merge Two arrays 
*/
int *merge_array(int *left, size_t left_size, int *right, size_t right_size, size_t n)
{
    int *mix = (int *)calloc(n, sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            mix[k] = left[i];
            i++;
        }
        else
        {
            mix[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        mix[k++] = left[i++];
    }

    while (j < right_size)
    {
        mix[k++] = right[j++];
    }

    return mix;
}

/* -------------------------------------------------------------- --------------------------------------------------------------
Merge sort implemention
Returns a new sorted array
Note: Caller is responsible for freeing the returned array
*/
int *merge_sort_impl(int *arr, size_t n)
{
    // single element, return a new dynamically allocated array
    if (n == 1)
    {
        int *result = (int *)malloc(sizeof(int));
        if (result)
            result[0] = arr[0];
        return result;
    }

    size_t mid = n / 2;

    int *left_copy = array_copy_range_impl(arr, 0, mid, n);
    int *left = merge_sort_impl(left_copy, mid);
    free(left_copy); 

   
    int *right_copy = array_copy_range_impl(arr, mid, n, n);
    int *right = merge_sort_impl(right_copy, n - mid);
    free(right_copy); 

    
    int *result = merge_array(left, mid, right, n - mid, n);

   
    free(left);
    free(right);

    return result;
}
