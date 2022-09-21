
#include "queue.c"

int enqueue(int value)
{
    struct Queue *t;
    t = (struct Queue *)malloc(sizeof(struct Queue));
    t->data = value;
    t->next = front;
    if (!t)
    {
        printf("\noverflow\n");
        return -1;
    }
    if (front == NULL && rear == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }

    return 0;
}
int dequeue()
{
    struct Queue *t;
    int value = 0;
    if (front == NULL)
    {
        printf("\nunderflow\n");
        return -1;
    }
    t = front;

    if (front->next && front->next != front)
    {
        front = front->next;
        rear->next = front;
    }
    else
    {
        front = rear = NULL;
    }
    value = t->data;
    free(t);
    return value;
}

void display()
{
    struct Queue *p;
    p = front;
    printf("\n");

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != front);
    printf("\n");
}
// void main()
// {
//     enqueue(5);
//     enqueue(4);
//     enqueue(3);

//     enqueue(3);
//     enqueue(1);
//     display();
//     printf("\ndequeue vlaue: %d\n", dequeue());
//     display();
//     // printf("\ndequeue vlaue: %d\n", dequeue());
// }