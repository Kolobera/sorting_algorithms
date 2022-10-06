#include "sort.h"

/**
 * bubble_sort - sorting algorithm
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
    size_t i, min, j, temp;

    if (array == NULL || size < 2)
        return;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        if (i != min)
            print_array(array, size);
    }
}
