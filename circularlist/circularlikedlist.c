#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

} *head = NULL;

int count()
{
    struct Node *p;
    int count;
    if (head == NULL)
        return 0;
    p = head;
    count = 0;
    do
    {

        p = p->next;
        count++;
    } while (p != head);
    return count;
}

void display()
{
    struct Node *p;
    printf("\n");
    p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void insert(int index, int value)
{
    int i;
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->prev = t->next = NULL;
    if (head == NULL)
    {
        head = t;
        t->prev = t->next = t;
    }
    else if (index == 0)
    {
        t->next = head;
        t->prev = head->prev;
        head->prev = t;
    }
    else if (index <= count())
    {
        p = head;
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int delete (int index)
{
    struct Node *p;
    int i, value;

    if (index < 0 || index > count())
        return -1;
    p = head;
    for (i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    value = p->data;
    free(p);
    return value;
}

void main()
{
    insert(0, 1);
    insert(1, 2);
    insert(2, 3);
    insert(3, 4);
    display();

    delete (2);
    display();
}