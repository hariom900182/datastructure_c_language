#include "common.c"

int partition(int a[], int l, int h)
{
    int pivot, i = l, j = h;
    pivot = a[l];
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[l], &a[j]);
    return j;
}

void quick_sort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quick_sort(a, l, j);
        quick_sort(a, j + 1, h);
    }
}

void main()
{
    int arr[] = {11,
                 13,
                 7,
                 12,
                 16,
                 9,
                 24,
                 5,
                 10,
                 3,
                 __INT32_MAX__},
        n = 11, i;

    quick_sort(arr, 0, n - 1);

    printf("\n--sorted array--\n");
    for (i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}