#include <stdio.h>
#include <stdlib.h>

#define HAS_FUN(x) x % 10

struct Node
{
    int value;
    struct Node *next;
};

struct Node *create_node(int value)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->value = value;
    t->next = NULL;
    return t;
}

void insert(struct Node **hash, int value)
{
    struct Node *t, *p, *q;
    int index = HAS_FUN(value);
    if (hash[index] == NULL)
        hash[index] = create_node(value);
    else
    {
        p = q = hash[index];
        t = create_node(value);
        while (p)
        {
            if (p->value < value)
            {
                q = p;
                p = p->next;
            }
            else
            {

                break;
            }
        }

        q->next = t;
        if (p != NULL && p->next != hash[index])
            t->next = p;
    }
}

int search(struct Node **hash, int value)
{
    int index = HAS_FUN(value);
    struct Node *p;
    p = hash[index];
    if (!p)
        return -1;
    while (p != NULL && p->value != value)
    {
        p = p->next;
    }
    if (p == NULL)
        return -1;
    return index;
}

int delete (struct Node **hash, int value)
{
    int index = HAS_FUN(value), result;
    struct Node *p, *q, *t;
    p = q = hash[index];
    while (p != NULL)
    {
        if (p->value == value)
        {
            t = p;
            break;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    result = t->value;
    if (t == hash[index])
    {
        hash[index] = t->next;
        free(t);
    }
    else
    {
        q->next = t->next;
        free(t);
    }
    return result;
}
void main()
{
    int i;
    struct Node *table[10];
    for (i = 0; i < 10; i++)
        table[i] = NULL;
    insert(table, 12);
    insert(table, 22);
    insert(table, 42);
    insert(table, 11);
    insert(table, 33);
    insert(table, 43);
    insert(table, 90);
    insert(table, 99);

    printf("Value found at index: %d \n", search(table, 423));
    printf("Deleted value %d\n", delete (table, 33));
    printf("\n");
}