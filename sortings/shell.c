#include "common.c"
#include "math.h"
void shell_sort(int a[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            j = i - gap;
            while (j >= 0 && a[j] > temp)
            {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }
    }
}

void main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    shell_sort(A, n);
    printf("\n---Sorted Array----\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}