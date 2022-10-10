#include "sort.h"

/**
 * counting_sort - counting sort algorithm
 * @array: array to sort
 * @size: size of array 
 */
void counting_sort(int *array, size_t size)
{
    int i, k, n = size;
    int *b, *count;

    for (i = 0; array[i]; i++)
    {
        if (array[i] > k)
            k = array[i];
    }
    b = malloc(sizeof(int) * (k + 1));
    if (!b)
        return;
    for (i = 0; i < n; i++)
        ++b[array[i]];
    for (i = 1; i <= k; i++)
        b[i] += b[i - 1];
    print_array(b, ((size_t)k + 1));
    count = malloc(sizeof(int) * (n));
    if (!count)
        return;
    for ( i = n - 1; i >= 0; i--)
        count[--b[array[i]]] = array[i];
    for (i = 0; i < n; i++)
        array[i] = count[i];
    free(b);
    free(count);
}
