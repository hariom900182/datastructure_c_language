#include "common.c"

void selection_sort(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        swap(&a[i], &a[k]);
    }
}

void main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    selection_sort(A, n);
    printf("\nSorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}