#include "common.c"

void count_sort(int a[], int n)
{
    int max, *c, i, j;
    max = find_max(a, n);
    c = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max + 1; i++)
        c[i] = 0;
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    i = j = 0;
    while (i < max + 1)
    {
        if (c[i] > 0)
        {
            a[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}

void main()
{
    int A[] = {11, 5, 14, 2, 6, 3, 1}, n = 7, i;
    count_sort(A, n);
    printf("\n---Sorted Array----\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}