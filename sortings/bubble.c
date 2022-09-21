#include "common.c"

void bubble_sort(int a[], int n)
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void main()
{

    int i;
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};

    bubble_sort(arr, 10);

    printf("\nSorted list\n");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
}