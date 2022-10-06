#include "sort.h"

/**
 * bubble_sort - sorting algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
    size_t k, flag, i, temp;

    if (array == NULL || size < 2)
        return;
    for (k = 1; k <= size - 1; k++)
    {
        flag = 0;
        for (i = 0;i <= size - k - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
                flag = 1;
                print_array(array, size);
            }
        }
        if (flag == 0)
            break;
    }
}
