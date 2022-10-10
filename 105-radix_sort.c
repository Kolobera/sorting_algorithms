#include "sort.h"

/**
 * countsort - count sort
 * @A: array
 * @n: size
 * @pos: pos
 */
void countsort(int *A, int n, int pos)
{
    int count[10] = {0},b[10], i, j, k, l;

    for (i = 0; i < n; i++)
        ++count[(A[i]/pos)%10];
    for (j = 1; j <= 10; j++)
        count[j] += count[j - 1];
    for (k = n - 1; k >= 0; k--)
        b[--count[(A[k]/pos)%10]] = A[k];
    for (l = 0; l < n; l++)
        A[l] = b[l];
}
/**
 * radix_sort - radix sort algorithm
 * @array: array to sort
 * @size: size of array 
 */
void radix_sort(int *array, size_t size)
{
    int i, j, k, n = size;

    for (i = 0; array[i]; i++)
    {
        if (array[i] > k)
            k = array[i];
    }
    for (j = 1; k/j > 0; j = j * 10)
    {
        countsort(array, n, j);
        print_array(array, size);
    }
}
