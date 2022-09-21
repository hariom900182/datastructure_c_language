#include <stdio.h>
#include <stdlib.h>

#define HAS_FUN(x) x % 10
#define SIZE 10

void insert(int table[], int value)
{
    int index = HAS_FUN(value);
    int i, k;
    if (table[index] == 0)
    {
        table[index] = value;
        return;
    }
    i = 0;
    do
    {
        k = (index + (i * i)) % SIZE;
        i++;
    } while (table[k] != 0);
    table[k % 10] = value;
}

int search(int table[], int value)
{
    int index = HAS_FUN(value);
    int i, k;
    if (table[index] == value)
    {
        return index;
    }

    i = 0;
    do
    {
        k = (index + (i * i)) % SIZE;
        i++;
    } while (table[k] != 0 && table[k] != value);
    if (table[k] != value)
        return -1;
    return k;
}

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
    printf("value found at index : %d\n", search(table, 48));
    printf("\n");
}