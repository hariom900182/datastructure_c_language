#include "queue.c"
static int preOrderIndex = 0;
void create()
{
    int value;
    struct Node *p, *t;
    printf("\n Enter root value: ");
    scanf("%d", &value);
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    root = p;
    enqueue(p);
    do
    {
        p = dequeue();
        if (p != NULL)
        {
            printf("\n Enter left child of %d : ", p->data);
            scanf("%d", &value);
            if (value != -1)
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = value;
                t->left = NULL;
                t->right = NULL;
                p->left = t;
                enqueue(t);
            }
            printf("\n Enter right child of %d : ", p->data);
            scanf("%d", &value);
            if (value != -1)
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = value;
                t->left = NULL;
                t->right = NULL;
                p->right = t;
                enqueue(t);
            }
        }
    } while (p);
}

void in_order(struct Node *n)
{
    if (!n)
        return;
    in_order(n->left);
    printf("%d ", n->data);
    in_order(n->right);
}

void pre_order(struct Node *n)
{
    if (!n)
        return;
    printf("%d ", n->data);
    pre_order(n->left);
    pre_order(n->right);
}

void post_order(struct Node *n)
{
    if (!n)
        return;
    post_order(n->left);
    post_order(n->right);
    printf("%d ", n->data);
}
int searchValue(int *in, int start, int end, int value)
{
    int i;
    i = -1;
    for (i = start; i <= end; i++)
    {
        if (in[i] == value)
            break;
    }
    return i;
}
struct Node *generateTree(int *pre, int *in, int start, int end)
{
    struct Node *t;
    int splitIndex;
    if (start > end)
        return NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = pre[preOrderIndex++];
    t->left = NULL;
    t->right = NULL;
    if (start == end)
    {
        return t;
    }
    splitIndex = searchValue(in, start, end, t->data);
    t->left = generateTree(pre, in, start, splitIndex - 1);
    t->right = generateTree(pre, in, splitIndex + 1, end);
    return t;
}

void level_order(struct Node *root)
{
    int value;
    struct Node *p, *t;
    // printf("%d ", p->data);
    p = root;
    enqueue(p);
    do
    {
        p = dequeue();
        if (p != NULL)
        {
            printf("%d", p->data);
            if (p->left)
                enqueue(p->left);
            if (p->right)
                enqueue(p->right);
        }
    } while (p);
}

int count_nodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count_nodes(p->left);
        y = count_nodes(p->right);
        return x + y + 1;
    }
    return 0;
}

int height(struct Node *p)
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
int leaf_nodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count_nodes(p->left);
        y = count_nodes(p->right);
        if (p->left == NULL && p->right == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int none_leaf_nodes(struct Node *p)
{

    int x, y;
    if (p != NULL)
    {
        x = none_leaf_nodes(p->left);
        y = none_leaf_nodes(p->right);
        if (p->left != NULL || p->right != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

void main()
{
    struct Node *p;
    int preorder[] = {1, 2, 3};
    int inorder[] = {2, 1, 3};
    // create();
    // printf("\n");
    // post_order(root);
    //  printf("root %d", root->data);
    p = generateTree(preorder, inorder, 0, sizeof(inorder) / sizeof(inorder[0]) - 1);
    // level_order(p);
    //  pre_order(p);
    printf("\n Total Nodes = %d", count_nodes(p));
    printf("\n Height = %d", height(p));
    printf("\n Leaf nodes = %d", leaf_nodes(p));
    printf("\n None leaf nodes = %d", none_leaf_nodes(p));
    printf("\n");
}