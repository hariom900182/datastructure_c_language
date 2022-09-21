#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
struct Array array;

void initArray(int length)
{
    array.arr = (int *)malloc(length * sizeof(int));
    array.length = length;
    array.size = 0;
}
void append(int value)
{
    if (array.size >= array.length)
        return;
    array.arr[array.size++] = value;
}
void display()
{
    int i;
    for (i = 0; i < array.size; i++)
    {
        printf("%d\t", array.arr[i]);
    }
    printf("\n");
}
void insertElementAt(int index, int value)
{
    if (index < 0 || index > array.length)
        return;
    int i;
    if (array.size == array.length)
        return;
    for (i = array.size; i > index; i--)
    {
        array.arr[i] = array.arr[i - 1];
    }
    array.arr[index] = value;
    array.size++;
}

int deleteElementFrom(int index)
{
    int val, i;
    if (array.size - 1 < 0)
        return 0;
    if (index < 0 || index >= array.length)
        return 0;
    val = array.arr[index];
    for (i = index; i < array.size - 1; i++)
    {
        array.arr[i] = array.arr[i + 1];
    }
    array.size--;
    return val;
}