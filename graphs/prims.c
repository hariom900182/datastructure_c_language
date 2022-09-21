#include <stdio.h>
#include <stdlib.h>

#define V 8
#define I __INT32_MAX__

struct Edge
{
    int x;
    int y;
};

struct Edge min_edge(int cost[V][V], int size)
{
    int i, j;
    int max = I;
    struct Edge edge;
    for (i = 1; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (cost[i][j] < max)
            {
                edge.x = i;
                edge.y = j;
                max = cost[i][j];
            }
        }
    }
    return edge;
}

struct Edge min_cost_edge(int list[], int cost[V][V], int size)
{
    int i;
    int val = I;
    struct Edge e;
    for (i = 1; i < size; i++)
    {
        if (list[i] != 0 && cost[i][list[i]] < val)
        {
            val = cost[i][list[i]];
            e.x = i;
            e.y = list[i];
        }
    }
    return e;
}

void prims_algo(int cost[V][V], int size)
{
    int near[V];
    int t[2][size];
    int i = 0, u = 1, j, sum = 0;
    for (i = 0; i < V; i++)
        near[i] = I;
    struct Edge e = min_edge(cost, V);
    near[e.x] = 0;
    near[e.y] = 0;
    t[0][0] = e.x;
    t[1][0] = e.y;

    // near list initial setup
    for (i = 1; i < V; i++)
    {
        // int index;
        if (near[i] != 0)
        {
            if (cost[i][t[0][0]] < cost[i][t[1][0]])
            {
                near[i] = t[0][0];
            }
            else
            {
                near[i] = t[1][0];
            }
        }
    }

    while (u < V - 1)
    {
        e = min_cost_edge(near, cost, V);
        t[1][u] = e.y;
        t[0][u] = e.x;
        near[e.x] = 0;
        near[e.y] = 0;
        for (i = 1; i < V; i++)
        {
            if (near[i] != 0)
            {
                if (cost[i][t[0][u]] < cost[i][near[i]])
                {
                    near[i] = t[0][u];
                }
            }
        }
        u++;
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            printf("%d  ", t[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < size - 1; j++)
    {
        sum = sum + cost[t[0][j]][t[1][j]];
    }
    printf("Cost of spanning tree is: %d\n", sum);
}
void main()
{

    int cost[V][V] = {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
    };
    int size = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;
    prims_algo(cost, size);
}