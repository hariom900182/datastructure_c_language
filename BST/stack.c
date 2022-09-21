#include "types.c"

void push(struct NodeB *value)
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
struct NodeB *pop()
{
    struct NodeB *x;
    struct Node *temp;
    if (top == NULL)
    {
        printf("\nStack overflow\n");
        return NULL;
    }
    temp = top;
    x = top->data;
    top = top->next;
    free(temp);
    return x;
}
struct NodeB *peep(int index)
{
    int i;
    struct Node *temp;
    struct NodeB *x = NULL;
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