#include "sort.h"

/**
 * countsort - count sort
 * @A: array
 * @n: size
 * @pos: pos
 */
void countsort(int *A, int n, int pos)
{
    int count[10] = {0},b[10],  i;

    for (i = 0; i < n; i++)
        ++count[(A[i]/pos)%10];
    for (i = 1; i <= 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
        b[--count[(A[i]/pos)%10]] = A[i];
    for (i = 0; i < n; i++)
        A[i] = b[i];
}
/**
 * radix_sort - radix sort algorithm
 * @array: array to sort
 * @size: size of array 
 */
void radix_sort(int *array, size_t size)
{
    int i, k, n = size;

    for (i = 0; array[i]; i++)
    {
        if (array[i] > k)
            k = array[i];
    }
    for (i = 1; k/i > 0; i = i * 10)
    {
        countsort(array, n, i);
        print_array(array, size);
	printf("zml");
    }
}
