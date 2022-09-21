#include <stdio.h>
#include <stdlib.h>

struct NodeB
{
    struct NodeB *left;
    int value;
    struct NodeB *right;
    int height;
} *root = NULL;

int updateHeight(struct NodeB *p)
{
    int hl, hr;
    hl = p->left ? p->left->height : 0;
    hr = p->right ? p->right->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

struct NodeB *LLRotation(struct NodeB *p)
{
    struct NodeB *pl;
    struct NodeB *plr;
    pl = p->left;
    plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = updateHeight(p);
    pl->height = updateHeight(pl);
    if (p == root)
        root = pl;
    return pl;
}

struct NodeB *LRRotation(struct NodeB *p)
{
    struct NodeB *pl = p->left;
    struct NodeB *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;

    pl->height = updateHeight(pl);
    p->height = updateHeight(p);
    plr->height = updateHeight(plr);

    if (p == root)
        root = plr;

    return plr;
}

struct NodeB *RRRotation(struct NodeB *p)
{
    struct NodeB *pr;
    struct NodeB *prl;
    pr = p->right;
    prl = pr->left;
    pr->left = p;
    p->right = prl;
    p->height = updateHeight(p);
    pr->height = updateHeight(pr);
    if (p == root)
        root = pr;
    return pr;
}

struct NodeB *RLRotation(struct NodeB *p)
{
    struct NodeB *pr = p->right;
    struct NodeB *prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;

    pr->height = updateHeight(pr);
    p->height = updateHeight(p);
    prl->height = updateHeight(prl);

    if (p == root)
        root = prl;

    return prl;
}
int balanceFactor(struct NodeB *p)
{
    int hl, hr;
    hl = p->left != NULL ? p->left->height : 0;
    hr = p->right != NULL ? p->right->height : 0;
    return hl - hr;
}

struct NodeB *insert(struct NodeB *p, int value)
{
    struct NodeB *t;

    if (p == NULL)
    {
        t = (struct NodeB *)malloc(sizeof(struct NodeB));
        t->left = NULL;
        t->right = NULL;
        t->value = value;
        t->height = 1;
        return t;
    }
    if (p->value > value)
        p->left = insert(p->left, value);
    else if (p->value < value)
    {
        p->right = insert(p->right, value);
    }
    p->height = updateHeight(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
    {
        return LLRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
    {
        return LRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
    {
        return RRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
    {
        return RLRotation(p);
    }
    return p;
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
    p->height = updateHeight(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) // L1
    {
        return LLRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) // L-1
    {
        return LRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1) // R-1
    {
        return RRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1) // R1
    {
        return RLRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == 0) // L0 Rotation
    {
        return LLRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 0) // R0 Rotation
    {
        return RRRotation(p);
    }
    return p;
}
void main()
{

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);

    printf("\n");
    delete (root, 40);
    printf("\n");
}