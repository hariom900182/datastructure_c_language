#include "common.c"
#include "../Queue/queue.c"

void add_to_bucket(int index, int value, struct Queue **x)
{
    struct Queue *p;
    struct Queue *t;
    t = (struct Queue *)malloc(sizeof(struct Queue));
    t->data = value;
    t->next = NULL;
    if (x[index] == NULL)
    {

        x[index] = t;
    }
    else
    {
        p = x[index];
        while (p && p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}

int pow1(int x, int y)
{
    int result = 1;
    while (y > 0)
    {
        result = result * x;
        y--;
    }
    return result;
}

int get_counts(int max)
{
    int count = 0;
    int x = max;
    while (x > 0)
    {
        x = x / 10;
        count++;
    }
    return count;
}

int get_index(int value, int iteration)
{
    int result = 1;
    int p = pow1(10, iteration);
    return (value / p) % 10;
}

void radix_sort(int a[], int n)
{
    int i, k = 0, count, c;
    struct Queue **bucket;
    struct Queue *temp;
    int max = find_max(a, n);
    count = get_counts(max);
    c = 0;
    bucket = (struct Queue **)malloc(10 * sizeof(struct Queue *));
    for (i = 0; i < 10; i++)
    {
        bucket[i] = NULL;
    }
    while (c < count)
    {
        /*
        code */

        k = 0;

        for (i = 0; i < n; i++)
        {

            add_to_bucket(get_index(a[i], c), a[i], bucket);
        }
        for (i = 0; i < 10; i++)
        {
            while (bucket[i] != NULL)
            {
                temp = bucket[i];
                bucket[i] = temp->next;
                a[k++] = temp->data;
                free(temp);
            }
        }
        for (i = 0; i < 10; i++)
        {
            bucket[i] = NULL;
        }
        printf("\npass: %d \n", c);
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        c++;
    }
}

void main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    radix_sort(A, n);
    printf("\n---Sorted Array----\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}