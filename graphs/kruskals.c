#include <stdio.h>
#include <stdlib.h>

#define V 7
#define E 9
#define I __INT32_MAX__
int set[E - 1];
int included[E];

void set_union(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] = set[u] + set[v];
        set[v] = u;
    }
    else
    {
        set[v] = set[v] + set[u];
        set[u] = v;
    }
}

int set_find(int u)
{
    int x = u;
    int v = 0;

    while (set[x] > 0)
    {
        x = set[x];
    }

    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

void kruskals_min_s_tree(int edges[3][E])
{
    int i, j, k, u, v, min = I;
    int t[2][V - 1];

    // set set as -1 for values
    for (i = 0; i < (E - 1); i++)
    {
        set[i] = -1;
    }

    // set included as 0 for values
    for (i = 0; i < E; i++)
    {
        included[i] = 0;
    }

    // while loop is more suitable but tried with for
    for (i = 0; i < (V - 1); i++)
    {
        // find minimum edge which is not included
        min = I;
        for (k = 0; k < E; k++)
        {
            if (included[k] == 0 && edges[2][k] < min)
            {
                min = edges[2][k];
                u = k;
            }
        }
        printf("min index %d \n", u);
        // find and union
        if (set_find(edges[0][u]) != set_find(edges[1][u]))
        {
            set_union(set_find(edges[0][u]), set_find(edges[1][u]));
            t[0][i] = edges[0][u];
            t[1][i] = edges[1][u];
        }
        else
        {
            i--;
        }
        included[u] = 1;
    }

    // print min spanning tree
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < (V - 1); i++)
        {
            printf("%d ", t[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void main()
{
    int edges[3][E] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                       {2, 6, 3, 7, 4, 5, 7, 6, 7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    kruskals_min_s_tree(edges);
}