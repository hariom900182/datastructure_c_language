#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

} * first, *last;

int count(struct Node *p)
{
    // struct Node *p;
    // p = first;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(int index, int value)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = t->prev = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else if (index == 0)
    {
        t->next = first;
        t->next->prev = t;
        first = t;
    }
    else if (index <= count(first))
    {
        struct Node *p;
        int i;
        p = first;
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
        // if (p->next)
        //     t->next = p->next;
        // else
        //     last = t;

        // t->prev = p;
        // p->next = t;
    }
}

int delete (int index)
{
    int val, i;
    struct Node *p;
    if (index == 0)
    {
        p = first;
        val = first->data;
        first = first->next;
        first->prev = NULL;
        free(p);
    }
    else
    {
        if (index > count(first))
            return -1;
        p = first;
        for (i = 0; i < index; i++)
        {
            p = p->next;
        }
        if (p->next)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        else
            p->prev->next = NULL;

        val = p->data;
        free(p);
    }
    return val;
}

void display()
{
    printf("\n");
    struct Node *p;
    p = first;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverse()
{
    struct Node *p, *temp;
    p = first;
    while (p != NULL)
    {
        printf("\t %d \t", p->data);
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

void main()
{
    insert(0, 1);
    insert(1, 2);
    insert(2, 3);
    display();
    insert(1, 4);
    insert(3, 6);
    display();

    insert(0, 5);

    display();

    // printf("\n Reversed \n");

    reverse();
    display();

    // printf("deleted value:  %d\n", delete (0));

    // display();
}
