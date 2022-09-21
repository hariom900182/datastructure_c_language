#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int value)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("\n Stack overflow\n");
        return;
    }
    temp->data = value;
    temp->next = top;
    top = temp;
}
int pop()
{
    int x;
    struct Node *temp;
    if (top == NULL)
    {
        printf("\nStack overflow\n");
        return -1;
    }
    temp = top;
    x = top->data;
    top = top->next;
    free(temp);
    return x;
}
int peep(int index)
{
    int x, i;
    struct Node *temp;
    temp = top;

    for (i = 0; i < index - 1; i++)
    {
        if (!temp)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("\nInvalid Index\n");
    else
        x = temp->data;
    return x;
}
int count()
{
    int x = 0;
    struct Node *temp;
    printf("\n");
    temp = top;
    while (temp)
    {
        //  printf(" %d ", temp->data);
        temp = temp->next;
        x++;
    }
    // printf("\n");
    return x;
}
// void main()
// {
//     printf("\n");
//     // create();
//     push(5);
//     push(4);
//     push(3);
//     push(2);
//     push(1);
//     display();
//     printf("value at last: %d\n", pop());
//     printf("value at last: %d\n", pop());
//     display();
//     printf("peep : %d\n", peep(1));
// }