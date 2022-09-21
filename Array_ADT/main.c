#include <stdio.h>
#include "adt.h"
void main()
{
    int value;
    initArray(10);
    append(5);
    append(4);
    append(3);
    append(2);
    append(1);

    insertElementAt(2, 20);

    display();
    value = deleteElementFrom(4);
    printf("\n Deleted value: %d \n", value);
    display();
}