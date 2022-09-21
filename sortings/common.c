#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int find_max(int a[], int n)
{
    int i;
    int max = INT32_MIN;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}