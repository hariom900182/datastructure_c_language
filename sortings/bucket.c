#include "common.c"
#include "../Queue/queue.c"

void add_to_bucket(int value, struct Queue **x)
{
    struct Queue *p;
    struct Queue *t;
    t = (struct Queue *)malloc(sizeof(struct Queue));
    t->data = value;
    t->next = NULL;
    if (x[value] == NULL)
    {

        x[value] = t;
    }
    else
    {
        p = x[value];
        do
        {
            p = p->next;
        } while (p->next != NULL);
        p->next = t;
    }
}

void bucket_sort(int a[], int n)
{
    int i, k = 0;
    struct Queue **bucket;
    struct Queue *temp;
    int max = find_max(a, n);
    bucket = (struct Queue **)malloc((max + 1) * sizeof(struct Queue *));
    for (i = 0; i < max; i++)
    {
        bucket[i] = NULL;
    }
    for (i = 0; i < n; i++)
    {
        add_to_bucket(a[i], bucket);
    }
    for (i = 0; i < max + 1; i++)
    {
        while (bucket[i] != NULL)
        {
            temp = bucket[i];
            bucket[i] = temp->next;
            a[k++] = temp->data;
            free(temp);
        }
    }
}

void main()
{
    int A[] = {11, 5, 14, 2, 6, 3, 1}, n = 7, i;
    bucket_sort(A, n);
    printf("\n---Sorted Array----\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}