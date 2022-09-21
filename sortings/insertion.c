#include "common.c"

void insertion_sort(int a[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void main()
{

    int i;
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};

    insertion_sort(arr, 10);

    printf("\nSorted list\n");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
}