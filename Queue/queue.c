#include <stdlib.h>
#include <stdio.h>
struct Queue
{
    int data;
    struct Queue *next;
} *front = NULL, *rear = NULL;