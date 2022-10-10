#include "sort.h"

/**
 * counting_sort - counting sort algorithm
 * @array: array to sort
 * @size: size of array 
 */
void counting_sort(int *array, size_t size)
{
    int i, j, l, m, k, n = size;
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
    for (j = 1; j <= k; j++)
        b[j] += b[j - 1];
    print_array(b, ((size_t)k + 1));
    count = malloc(sizeof(int) * (n));
    if (!count)
        return;
    for (l = n - 1; l >= 0; l--)
        count[--b[array[l]]] = array[l];
    for (m = 0; m < n; m++)
        array[m] = count[m];
    free(b);
    free(count);
}
