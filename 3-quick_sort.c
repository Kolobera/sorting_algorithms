#include "sort.h"


/**
 * partition - make a partition of A 
 * @A: array
 * @start: start of A portion
 * @end: end of A portion
 * Return: partition index
 */

int partition(int *A, int start, int end, size_t size)
{
    int pivot = A[end], i, temp, p_index = start;


    for (i = start; i < end; i++)
    {
        if (A[i] < pivot)
        {
            temp = A[i];
            A[i] = A[p_index];
            A[p_index] = temp;
            p_index++;
        }
    }
    temp = A[p_index];
    A[p_index] = A[end];
    A[end] = temp;
    print_array(A, size);
    return p_index;
}

/**
 * quicksort - sorting algorithm
 * @A: array
 * @start: start of A portion
 * @end: end of A portion
 */

void quicksort(int *A, int start, int end, size_t size)
{
    int p_index;
    if (start < end)
    {
        p_index = partition(A, start, end, size);
        quicksort(A, start, p_index - 1, size);
        quicksort(A, p_index + 1, end, size);
    }
}
/**
 * quick_sort - sorting algorithm
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    
    quicksort(array, 0, ((int)size - 1), size);
}