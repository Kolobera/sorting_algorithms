#include "sort.h"

/**
 * partition - change of position
 * @left: ...
 * @right: ..
 * @array: ..
 * @size: ...
 */
void partition(int *left, int *right, int *array, size_t size)
{
	int tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
	if (tmp != *left)
		print_array(array, size);
}

/**
 * quicksort - function to divide the array
 * @array: array
 * @left: left
 * @right: right
 * @size: size
 */
void quicksort(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left;
	int j = 0;

	if (left < right)
	{
		for (j = left; j < right; j++)
		{
			if (array[j] < pivot)
			{
				partition(&array[i], &array[j], array, size);
				i += 1;
			}
		}
		partition(&array[i], &array[right], array, size);
		quicksort(array, left, i - 1, size);
		quicksort(array, i + 1, right, size);
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
