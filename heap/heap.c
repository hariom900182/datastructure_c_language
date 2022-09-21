#include <stdio.h>
#include <stdlib.h>

void create(int h[], int n)
{
    int i, temp;
    i = n;
    while (i > 1 && h[i] > h[i / 2])
    {
        temp = h[i];
        if (h[i] > h[i / 2])
        {
            h[i] = h[i / 2];
            h[i / 2] = temp;
            i = i / 2;
        }
        else
            break;
    }
}

int delete (int h[], int n)
{
    int i, j, temp;
    i = 1;
    temp = h[i];
    h[i] = h[n];
    h[n] = temp;
    j = i * 2;
    while (j < n - 1)
    {
        if (h[j] < h[j + 1])
            j = j + 1;

        if (h[i] < h[j])
        {
            temp = h[i];
            h[i] = h[j];
            h[j] = temp;
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}

void main()
{
    int arr[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for (i = 1; i <= 7; i++)
    {
        create(arr, i);
    }
    for (i = 7; i > 0; i--)
    {
        delete (arr, i);
    }
    printf("\n");
    // printf("deleted value %d", delete (arr, 7));
    // printf("deleted value %d", delete (arr, 6));
    printf("\n");
    printf("values of array after heap sort: ");
    for (i = 1; i <= 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}