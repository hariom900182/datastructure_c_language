#include <stdio.h>
#include <stdlib.h>

#define HAS_FUN(x) x % 10
#define SIZE 10

void insert(int table[], int value)
{
    int index = HAS_FUN(value);
    int i = index;
    while (table[i] != 0 && i != index - 1)
    {
        i = ++i % SIZE;
    }
    if (i + 1 == index)
        return;
    table[i] = value;
}

int search(int table[], int value)
{
    int index = HAS_FUN(value);
    int i = index;
    while (table[i] != 0 && i != index - 1 && table[i] != value)
    {
        i = ++i % SIZE;
    }
    if (table[i] == value)
        return i;
    return -1;
}

// deletion requires lot of values shifting so not suggested for linear prob

void main()
{
    int table[SIZE] = {0};
    insert(table, 12);
    insert(table, 13);
    insert(table, 22);
    insert(table, 25);
    insert(table, 26);
    insert(table, 27);
    insert(table, 28);
    insert(table, 29);
    insert(table, 24);
    printf("value found at index : %d\n", search(table, 45));
    printf("\n");
}