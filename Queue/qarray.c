#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
int *queue;
int front, rear;
int enqueue(int value)
{
    // printf("\n %d %d %d \n", rear, SIZE, rear == SIZE);
    if (rear == SIZE - 1)
        return -1;

    queue[++rear] = value;
    return 0;
}
int dequeue()
{
    if (front == rear)
        return -1;
    front++;
    return queue[front];
}
void display()
{
    int i;
    printf("\n");
    for (i = front + 1; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void create()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int i;
    front = rear = -1;
    queue = (int *)malloc(SIZE * sizeof(int));
    // for (i = 0; i < SIZE + 1; i++)
    // {
    //     if (enqueue(arr[i]) == -1)
    //     {
    //         printf("\nOverflow\\n");
    //     }
    // }
}

void main()
{
    create();
    enqueue(5);
    enqueue(4);
    enqueue(3);
    display();
    printf("value  = %d\n", dequeue());
    enqueue(2);
    display();
    // printf("\n--------------------\n");
    // printf("value  = %d\n", dequeue());
    // printf("value  = %d\n", dequeue());
    // printf("value  = %d\n", dequeue());
    // printf("value  = %d\n", dequeue());
    // printf("value  = %d\n", dequeue());
    // printf("value  = %d\n", dequeue());
    // printf("\n--------------------\n");
    // display();
}