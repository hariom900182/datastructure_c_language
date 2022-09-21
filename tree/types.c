#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} *root = NULL;

struct Queue
{
    struct Node *ref;
    struct Queue *next;
} *front = NULL, *rear = NULL;