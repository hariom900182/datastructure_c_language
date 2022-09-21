#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;
void create(int arrr[], int n)
{
    int i;
    struct Node *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arrr[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        struct Node *ptr;
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = arrr[i];
        ptr->next = NULL;
        last->next = ptr;
        last = ptr;
    }
}

void display(struct Node *p)
{

    while (p->next != NULL)
    {
        printf("%d ", p->data);
        if (p->next != NULL)
            p = p->next;
    }
    printf("%d", p->data);
}
void displayRec(struct Node *p)
{
    if (p->next != NULL)
    {
        printf("%d", p->data);
        displayRec(p->next);
    }
    else
    {
        printf("%d", p->data);
    }
}
void displayRecRev(struct Node *p)
{
    if (p->next != NULL)
    {

        displayRecRev(p->next);
        printf("%d", p->data);
    }
    else
    {
        printf("%d", p->data);
    }
}

int count(struct Node *p)
{
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
int countR(struct Node *p)
{
    if (p == 0)
        return 0;
    return countR(p->next) + 1;
}

int sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int sumR(struct Node *p)
{
    if (p == 0)
        return 0;
    return sumR(p->next) + p->data;
}

int max(struct Node *p)
{
    int m = INT32_MIN;
    while (p != 0)
    {
        if (m < p->data)
            m = p->data;
        p = p->next;
    }
    return m;
}
int maxR(struct Node *p)
{
    int x;
    if (p == 0)
    {
        return INT32_MIN;
    }
    x = maxR(p->next);
    return (x > p->data) ? x : p->data;
}

void insert(int value, int pos)
{
    int i;
    struct Node *t, *p, *q;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;
    last = t;
    if (first == NULL)
    {
        first = t;
    }
    else if (pos == 1)
    {
        t->next = first;
        first = t;
    }
    else if (count(first) < pos)
    {
        p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
    else
    {
        p = first;
        q = NULL;
        for (i = 1; i <= pos; i++)
        {
            if (p->next != NULL)
            {
                q = p;
                p = p->next;
            }
        }
        q->next = t;
        t->next = p;
    }
}

int delete (int pos)
{
    struct Node *p, *q;
    int reVal;
    int c;
    int isLast;
    q = NULL;
    p = first;
    c = count(first);
    isLast = 0;
    if (pos < 1 || c < pos)
    {
        printf("Invalid position");
        return -1;
    }
    if (pos == 1)
    {
        p = first;
        reVal = p->data;
        first = first->next;
        free(p);
    }
    else
    {

        while (pos > 1)
        {
            q = p;
            p = p->next;
            pos--;
        }
        q->next = p->next;
        reVal = p->data;
        if (c == pos)
            last = q;
        free(p);
    }
    return reVal;
}

int sorted(struct Node *node)
{
    int min = -65527;
    struct Node *p;
    p = first;
    while (p->next != NULL)
    {
        if (min > p->data)
        {
            printf("Not sorted\n");
            return -1;
        }
        min = p->data;
        p = p->next;
    }
    printf("Sorted\n");
    return 1;
}

void removeDupInSortedList()
{
    struct Node *p, *q;
    p = first;
    q = NULL;
    while (p != NULL)
    {
        // q = p;
        // p = p->next;
        if (q != NULL && q->data == p->data)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}

void reverseWithArray()
{
    int *arr;
    int i;
    struct Node *p;
    arr = (int *)malloc(count(first) * sizeof(int));
    p = first;
    i = 0;
    while (p != NULL)
    {
        arr[i++] = p->data;
        p = p->next;
    }
    p = first;

    while (p != NULL)
    {
        p->data = arr[--i];
        p = p->next;
    }
}

void reverseWithSlidePtr()
{
    struct Node *p, *q, *r;
    q = r = NULL;
    p = first;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseWithRec(struct Node *p, struct Node *q)
{
    if (p != NULL)
    {
        reverseWithRec(p->next, p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    // int arr[] = {1, 2, 0, 4, 3};
    int res;
    // int c;
    // create(arr, 5);
    //  displayRecRev(first);
    insert(14, 1);
    insert(15, 2);
    insert(16, 3);
    insert(17, 4);
    insert(18, 5);
    insert(19, 6);
    display(first);
    reverseWithRec(first, NULL);
    printf("\n");
    display(first);
    printf("\n--------\n");
    // sorted(first);

    // printf("Value = %d \n", res);
    //  printf("\n%d \n", c);
}
