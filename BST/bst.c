#include "types.c"
#include "stack.c"
int height(struct NodeB *p)
{
    int x = 0, y = 0;
    if (p != NULL)
    {
        if (p->left)
        {

            x = height(p->left);
        }
        if (p->right)
        {

            y = height(p->right);
        }
        return x > y ? x + 1 : y + 1;
    }
    return x > y ? x : y;
}

void insert(int value)
{
    struct NodeB *t, *p;
    t = (struct NodeB *)malloc(sizeof(struct NodeB));
    t->left = NULL;
    t->right = NULL;
    t->value = value;
    if (root == NULL)
    {
        root = t;
        return;
    }
    p = root;
    while (p != NULL)
    {
        if (p->value > value)
        {
            if (p->left)
                p = p->left;
            else
                p->left = t;
        }
        else if (p->value < value)
        {
            if (p->right)
                p = p->right;
            else
                p->right = t;
        }
        else
            break;
    }
}

struct NodeB *inorder_pred(struct NodeB *p)
{
    while (p && p->right != NULL)
    {
        p = p->right;
    }
    return p;
}

struct NodeB *inorder_succ(struct NodeB *p)
{
    while (p && p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

struct NodeB *delete (struct NodeB *p, int value)
{
    struct NodeB *q;
    if (p == NULL)
        return NULL;
    if (p->right == NULL && p->left == NULL)
    {
        if (p == root)
        {

            root = NULL;
        }
        free(p);
        return NULL;
    }
    if (value > p->value)
    {
        p->right = delete (p->right, value);
    }
    else if (value < p->value)
    {
        p->left = delete (p->left, value);
    }
    else
    {
        if (height(p->left) > height(p->right))
        {
            q = inorder_pred(p->left);
            p->value = q->value;
            p->left = delete (p->left, q->value);
        }
        else
        {
            q = inorder_succ(p->right);
            p->value = q->value;
            p->right = delete (p->right, q->value);
        }
    }
    return p;
}
void bst_from_preorder(int *list, int size)
{
    struct NodeB *t, *p;
    int i = 0;
    if (root == NULL)
    {
        t = (struct NodeB *)malloc(sizeof(struct NodeB));
        t->value = list[i];
        t->left = NULL;
        t->right = NULL;
        root = t;
        p = root;
    }
    i++;
    while (i < size)
    {
        t = (struct NodeB *)malloc(sizeof(struct NodeB));
        t->value = list[i];
        t->left = NULL;
        t->right = NULL;
        // p->left = t;
        if (p->value > list[i])
        {
            p->left = t;
            push(p);
            p = t;
            i++;
        }
        else if (top != NULL)
        {
            if (list[i] > p->value && list[i] < top->data->value)
            {
                p->right = t;
                p = t;
                // push(p);
                i++;
            }
            else
            {
                p = pop();
            }
        }
        else
        {
            p->right = t;
            p = t;
            i++;
        }
    }
    while (top)
    {
        pop();
    }
}
void main()
{
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    // int i;
    // int arr[] = {9,
    //              15,
    //              5,
    //              20,
    //              16,
    //              8,
    //              12,
    //              3,
    //              6};
    // for (i = 0; i < 9; i++)
    // {
    //     insert(arr[i]);
    // }
    // delete (root, 5);
    bst_from_preorder(pre, sizeof(pre) / sizeof(pre[0]));
    printf("\n");
}