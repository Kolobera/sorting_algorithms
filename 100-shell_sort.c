#include "sort.h"

/**
 * shell_sort - shell sort algorithm 
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
    size_t gapi, gap, j, i, k, l, temp, flag;
    int lk;
    if (array == NULL || size < 2)
        return;
    gapi = 1; 
    while (gapi < size)
        gapi = gapi * 3 + 1;
    if (gapi > size)
        gapi = (gapi - 1 ) / 3;
    for (gap = gapi; gap >= 1; gap /= 3)
    {
        i = 0;
        for(j = gap; j < size; j++)
        {
            if (array[j] < array[i])
            {
                k = j;
                l = i;
                flag = 1;
                while(flag)
                {
                    if (array[k] < array[l])
                    {
                        temp = array[k];
                        array[k] = array[l];
                        array[l] = temp;
                    }
                    else
                        break;
                    
                    lk = l - gap;
                    if (lk < 0)
                        {
                            break;
                        }
                    k = k - gap;
                    l = l - gap;
                }
            }
            i++;
        }
        print_array(array, size);
    }
}