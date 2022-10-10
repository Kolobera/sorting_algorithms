#include "sort.h"

/**
 * p_merge - print
 * @A: ...
 * @lb: ...
 * @mid: ...
 * @ub: ...
 */
void p_merge(int *A, int lb, int mid, int ub)
{
    int n, o;

    printf("Merging...\n[left]: ");
    n = lb;
    o = 0;
    while (A && n <= mid)
    {
        if (o > 0)
            printf(", ");
        printf("%d", A[n]);
        ++o;
        n++;
    }
    printf("\n[right]: ");
    n = mid + 1;
    o = 0;
    while (A && n <= ub)
    {
        if (o > 0)
            printf(", ");
        printf("%d", A[n]);
        ++n;
        ++o;
    }
    printf("\n");
}
/**
 * merge - merge sub_lists
 * @A: array to sort
 * @lb: start of partition
 * @ub: end of partition
 * @mid: midlle of partition
 */
void merge(int *A, int lb,int mid, int ub, int *b)
{
    int i = lb, j = mid + 1, k = lb, temp = 1, te = 0, o;

    if (lb <= mid && mid + 1 <= ub)
    {       
        p_merge(A, lb, mid, ub);
    }
    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            b[k] = A[i];
            i++;
        }
        else
        {
            b[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        temp = j;
        te = ub;
    }
    else if (j > ub)
    {
        temp = i;
        te = mid;
    }
    while (temp <= te)
    {
        b[k] = A[temp];
        temp++;
        k++;
    }
    printf("[Done]: ");
    o = 0;
    for (k = lb; k <= ub; k++)
    {
        if (o > 0)
            printf(", ");
        printf("%d", b[k]);
        A[k] = b[k];
        ++o;
    }
    printf("\n");
}

/**
 * mergesort - merge sort algorithm 
 * @A: array to sort
 * @lb: start of partition
 * @ub: end of partition
 */
void mergesort(int *A, int lb, int ub, int *b)
{
    int mid;

    if (lb < ub)
    {
        mid = (lb + ub - 1) / 2;
        mergesort(A, lb, mid, b);
        mergesort(A, mid + 1, ub, b);
        merge(A, lb, mid, ub, b);
    }
}
/**
 * merge_sort - merge sort algorithm 
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
    int *b;

    if (array == NULL || size < 2)
        return;
    b = malloc(sizeof(int) * size);
    if (!b)
        return;
    mergesort(array, 0, ((int)size - 1), b);
    free(b);
}
