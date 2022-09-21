#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int *stk;
int top;
void create()
{
    top = -1;
    stk = (int *)malloc(MAX * sizeof(int));
}

void push(int value)
{
    top++;
    if (top == MAX)
    {
        printf("\nStack overflow\n");
        return;
    }
    stk[top] = value;
}
int pop()
{
    int x;
    if (top < 0)
    {
        printf("\nStack overflow\n");
        return -1;
    }
    x = stk[top--];
    return x;
}
int peep(int index)
{
    if (index < 0 || index > top)
    {
        return -1;
    }
    return stk[index];
}
void display()
{
    int i;
    printf("\n");
    for (i = 0; i <= top; i++)
    {
        printf(" %d ", stk[i]);
    }
    printf("\n");
}
void main()
{
    printf("\n");
    create();
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    display();
    printf("value at last: %d\n", pop());
    printf("value at last: %d\n", pop());
    display();
    printf("peep : %d\n", peep(1));
}