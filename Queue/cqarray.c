#include <stdlib.h>
#include <stdio.h>
#define SIZE 5
int *queue;
int front, rear;
int enqueue(int value)
{
    // printf("\n %d %d %d \n", rear, SIZE, rear == SIZE);
    if ((rear + 1) % SIZE == front)
        return -1;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
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
    i = front + 1;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    } while (i != (rear + 1) % SIZE);
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