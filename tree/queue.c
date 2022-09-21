#include "types.c"
int enqueue(struct Node *value)
{
    struct Queue *temp;
    temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->ref = value;
    temp->next = front;
    if (!temp)
    {
        printf("\noverflow\n");
        return -1;
    }
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

    return 0;
}
struct Node *dequeue()
{
    struct Queue *temp;
    struct Node *value = NULL;
    if (front == NULL)
    {
        // printf("\nunderflow\n");
        return NULL;
    }
    temp = front;
    value = temp->ref;
    if (front->next && front != rear)
    {
        front = front->next;
        rear->next = front;
    }
    else
    {
        front = rear = NULL;
    }

    free(temp);
    return value;
}
